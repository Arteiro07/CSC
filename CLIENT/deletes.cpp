#include "example.h"

using namespace std;
using namespace seal;

void deletes( )
{
///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////
	EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
//
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
	parms.set_plain_modulus(1024);
	SEALContext context(parms);
//
	KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);
//
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

    char op_1;
    char op_2;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;

///// Condition 1

    cout<<"Operation: = < > "<<endl;
    cin>>op_1;
    
    cout<<"Column 1 name:"<<endl;
    cin>>name_1;
    
    cout<<"Value1:"<<endl;
    cin>>value_1;
//
    cout<< "AND OR"<<endl;
    cin>>mode;
/// Condition 2

    cout<<"Column 2 name:"<<endl;
    cin>>name_2;

    cout<<"Operation: = < > "<<endl;
    cin>>op_2;

    cout<<"Value2"<<endl;
    cin>>value_2;

//////
    cout<<"DELETE FROM "<<tablename<<"WHERE "<<name_1<<" "<<op_1<<" "<<value_1<<" "<<mode<<" "<<name_2<<" "<<op_2<<" "<<value_2<<endl;
    
//send

}