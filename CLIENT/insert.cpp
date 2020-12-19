#include "example.h"

using namespace std;
using namespace seal;

void insert( )
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
	Ciphertext encrypted_query_0;
    Ciphertext encrypted_query_1;
    Ciphertext encrypted_query_2;
    Ciphertext encrypted_query_3;
    Ciphertext encrypted_query_4;
///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////
   	
    string tablename;
 
    string mode;


    int n;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;

    cout<<"Number of columns? (max of 5)";
    cin>>n;

    string name[n];
    string value[5];

///// Condition 1
    for(int i = 0; i<n; i++)
    {
        cout<<"Column name:"<<endl;
        getline(cin >> std::ws, name[i]);
    
        cout<<"Value:"<<endl;
        cin>>value[i];
    }

    cout << "INSERT INTO TABLE " << tablename<<" (";
    for(int i = 0; i<n; i++)
    {
        cout << name[i];
        if(i < (n-1))
            cout<<", ";
    }
    cout<<") VALUES (";
    for(int i = 0; i<n; i++)
    {
        cout << value[i];
        if(i < (n-1))
            cout<<", ";
    }
    cout<<')'<<endl;

    string aux;
    cout<<"n:"<<n;

  
	if(n==1)
    {
        aux=value[0];
        Plaintext p_query_0(aux);//plaintext query
        encryptor.encrypt(p_query_0, encrypted_query_0);    
    }
    else if(n==2)
    {
        aux=value[0];
        Plaintext p_query_0(aux);//plaintext query
        aux=value[1];
        Plaintext p_query_1(aux);
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
    }
    else if(n==3)
    {

        aux=value[0];
        Plaintext p_query_0(aux);//plaintext query
        aux=value[1];
        Plaintext p_query_1(aux);
        aux=value[2];    
        Plaintext p_query_2(aux);
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2);    
    }
    else if(n==4)
    {
        aux=value[0];
        Plaintext p_query_0(aux);//plaintext query
        aux=value[1];
        Plaintext p_query_1(aux);
        aux=value[2];    
        Plaintext p_query_2(aux);
        aux=value[3];
        Plaintext p_query_3(aux);
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2); 
        encryptor.encrypt(p_query_1, encrypted_query_3);
   
    }
    else if(n==5)
    {
        aux=value[0];
        Plaintext p_query_0(aux);//plaintext query
        aux=value[1];
        Plaintext p_query_1(aux);
        aux=value[2];    
        Plaintext p_query_2(aux);
        aux=value[3];
        Plaintext p_query_3(aux);
        aux=value[4];    
        Plaintext p_query_4(aux);
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2); 
        encryptor.encrypt(p_query_3, encrypted_query_3);
	    encryptor.encrypt(p_query_4, encrypted_query_4);   
    }

    cout<<"encrypted"<<endl;	

    ////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////

    ofstream myfile;
    myfile.open ("encrypt/encrypted.txt");

    myfile<<"2 "<<n<<" " <<tablename<<" ";
    
    for(int i =0; i<n; i++)
    {
        myfile<< name[i];
        if (i<n-1)
        {
            myfile << " ";
        }
    }
    
    myfile.close();

	if(n>=1)
    {   
        ofstream value1;
        value1.open ("encrypt/value1.txt");
        encrypted_query_0.save(value1);
        value1.close(); 

    }
    if(n>=2)
    {
        ofstream value2;
        value2.open ("encrypt/value2.txt");
        encrypted_query_1.save(value2);
        value2.close(); 

    }
    if(n>=3)
    {
        ofstream value3;
        value3.open ("encrypt/value3.txt");
        encrypted_query_2.save(value3);
        value3.close(); 
    }
    if(n>=4)
    {
        ofstream value4;
        value4.open ("encrypt/value4.txt");
        encrypted_query_3.save(value4);
        value4.close();  
    }
    if(n==5)
    {
        ofstream value5;
        value5.open ("encrypt/value5.txt");
        encrypted_query_4.save(value5);
        value5.close();         
    }

	cout<<"ecrypted and saved to file"<<endl;	

}