#include "parser.h"

using namespace std;

    /////////////////////////SEAL////////////////////////////////
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(1024);
    SEALContext context(parms);
    ////////////////////////////////////////////////////////////////

// driver code 
string parser(string filename)
{ 
    int n_cols=0;
    // filestream variable file 
    ifstream file; 
    string word;
    string statement;
  
    // opening file 
    file.open(filename.c_str());

    file>>word;
    //cout<<word<<endl; //

    if (word=="1") {
        file>>word;
        n_cols = stoi(word);        
        statement=create(n_cols, file);

    }else if (word=="2"){
        file>>word;
        n_cols = stoi(word);
        statement=insert(n_cols, file);

    }else if (word=="3")
    {   file>>word;
        n_cols = stoi(word);
        statement=selectfrom(n_cols, file);

    }else if (word=="4"){
        file>>word;
        n_cols = stoi(word);
        statement=selectsum(n_cols, file);
    }

    file.close();
    return statement;
}

/////////////////////////////////////////////

string create(int n_cols, ifstream &file) {
    string colname;
    string tablename;
    string statement;
    string id_key="ID INTEGER PRIMARY KEY AUTOINCREMENT,";

    file>>tablename;

    statement = "CREATE TABLE " + tablename + " ("+id_key;

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>colname;
        statement=statement+colname+" INT,";
    }
    file>>colname;
    statement=statement+colname+" INT);";

    return statement;
    
}

string insert(int n_cols, ifstream &file) {
    string colname;
    string tablename;
    string statement;
    string values;

    ifstream value1;
    ifstream value2;

    file>>tablename;

    statement = "INSERT INTO " + tablename + " (";
    //cout<<statement<<endl; //

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>colname;
        statement=statement+colname+",";
    }
    file>>colname;
    statement=statement+colname+") VALUES (";
    //cout<<statement<<endl; //

    value1.open("encrypted/value1.txt");
    Ciphertext val1;
    val1.load(context,value1);

    value2.open("encrypted/value2.txt");
    Ciphertext val2;
    val2.load(context,value2);

    //for (int i = 0; i < n_cols-1; i++)
    //{
    //    file>>values;
    //    statement=statement+values+",";
    //}
    //file>>values;
    //statement=statement+values+");";
    //cout<<statement<<endl;  //

    return statement;
    
}

string selectfrom(int n_cols, ifstream &file) {
    string colname;
    string tablename;
    string statement;
    string values;
    string col1name,col2name,val1,val2,signal1,signal2,andor;

    file>>tablename;

    statement = "SELECT ";

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>colname;
        statement=statement+colname+",";
    }
    file>>colname;
    statement=statement+colname+" FROM "+tablename+" WHERE ";

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>values;
        statement=statement+values+",";
    }
    file>>values;
    statement=statement+values+");";

    return statement;
    
}

string selectsum(int n_cols, ifstream &file) {
    string colname;
    string tablename;
    string statement;
    string values;

    file>>tablename;

    statement = "INSERT INTO " + tablename + "(";

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>colname;
        statement=statement+colname+",";
    }
    file>>colname;
    statement=statement+colname+") VALUES (";

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>values;
        statement=statement+values+",";
    }
    file>>values;
    statement=statement+values+");";

    return statement;
    
}

