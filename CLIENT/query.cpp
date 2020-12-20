#include "client.h"

using namespace std;
using namespace seal;

void query( )
{

///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////
	ifstream keyfile;
    keyfile.open("../client_1/database/database_public_key.txt");
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
//
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
	parms.set_plain_modulus(1024);
	SEALContext context(parms);
//
	KeyGenerator keygen(context);
    PublicKey public_key;
    public_key.load(context, keyfile);
    keyfile.close();
    Encryptor encryptor(context, public_key);

//
	Ciphertext encrypted_query_1;
    Ciphertext encrypted_query_2;
///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////

    string tablename;
    string value_1;
    string value_2;
    string mode;
    string name_1;
    string name_2;

    int n;

    char op_1;
    char op_2;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;
    cout<<"Number of columns?"<<endl;
    cin>>n;
    
    string name[n];
    
    for(int i=0; i<n; i++)
    {
        cout<<"Insert column name"<<endl;
        getline(cin >> std::ws, name[i]);
    }

    cout<<"Operation: = < > "<<endl;
    cin>>op_1;
    
    cout<<"Primeira Coluna"<<endl;
    cin>>name_1;

    cout<<"Value1:"<<endl;
    cin>>value_1;

///
    cout<<"AND OR"<<endl;
    cin>>mode;


    cout<<"Segunda Coluna"<<endl;
    cin>>name_2;

    cout<<"Operation: = < > "<<endl;
    cin>>op_2;

    cout<<"Value2"<<endl;
    cin>>value_2;

//////
    cout<<"Select "<<name_1<<" FROM "<<tablename<<" WHERE "<<name_1<<" "<<op_1<<" "<<value_1<<" "<<mode<<" "<<name_2<<" "<<op_2<<" "<<value_2<<endl;

//////
    Plaintext p_query_1((value_1));//plaintext query
	Plaintext p_query_2((value_2));
    
    cout<< p_query_1.to_string()<< endl;
    cout<< p_query_2.to_string()<< endl;
	
    encryptor.encrypt(p_query_1, encrypted_query_1);
    encryptor.encrypt(p_query_2, encrypted_query_2);
	cout<<"encrypted"<<endl;	


////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////

    ofstream myfile;
  	myfile.open ("encrypt/encrypted.txt");

    myfile<<"3 "<<n<<" "<<tablename<<" ";
    for(int i=0; i<n; i++)
    {
        myfile<<name[i]<<" ";
    }
    
    
    myfile<<name_1<<" "<<op_1<<" "<<mode<<" "<<name_2<<" "<<op_2;
    myfile.close();

    ofstream value1;
  	value1.open ("encrypt/value1.txt");
    encrypted_query_1.save(value1);
    value1.close();
    
    
    ofstream value2;
  	value2.open ("encrypt/value2.txt");
    encrypted_query_2.save(value2);
    value2.close();

//

	cout<<"ecrypted and saved to file"<<endl;	

////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////

//send
}