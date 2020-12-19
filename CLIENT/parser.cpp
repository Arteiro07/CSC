#include "parser.h"

using namespace std;
  
// driver code 
string parser(string userinput)
{ 
    int n_cols=0;
    // filestream variable file 
    ifstream file;
    string word;
    string statement;
    stringstream input(userinput);

    input>>word;
    //cout<<word<<endl; //

    if (word=="CREATE") {
        file>>word;
        if 
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

    for (int i = 0; i < n_cols-1; i++)
    {
        file>>values;
        statement=statement+values+",";
    }
    file>>values;
    statement=statement+values+");";
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

