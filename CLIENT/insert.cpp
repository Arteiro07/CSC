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
    string value[n];

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
    cout<<')'<<endl;;

    for(int i=0; i<5; i++)
    {
        if(i >= n)
        {   cout<<"dsasda";
            value[i]= to_string(6);
        }
        
    }    
    cout<<"dsa";

        Plaintext p_query_0((value[0]));//plaintext query
	    Plaintext p_query_1((value[1]));
        Plaintext p_query_2((value[2]));
        Plaintext p_query_3((value[3]));
        Plaintext p_query_4((value[4]));
 
	if(n==1)
    {
        encryptor.encrypt(p_query_0, encrypted_query_0);    
    }
    else if(n==2)
    {
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
    }
    else if(n==3)
    {
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2);    
    }
    else if(n==4)
    {
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2); 
        encryptor.encrypt(p_query_1, encrypted_query_3);
   
    }
    else if(n==5)
    {
        encryptor.encrypt(p_query_0, encrypted_query_0);
        encryptor.encrypt(p_query_1, encrypted_query_1);
        encryptor.encrypt(p_query_2, encrypted_query_2); 
        encryptor.encrypt(p_query_3, encrypted_query_3);
	    encryptor.encrypt(p_query_4, encrypted_query_4);   
    }

    cout<<"ecrypted"<<endl;	

    ////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////

    ofstream myfile;
    myfile.open ("encrypt/encrypted.txt");

    myfile<<"INSERT INTO "<<tablename<<"(";
    
    for(int i =0; i<n; i++)
    {
        myfile<< name[i];
        if (i<n-1)
        {
            myfile << ",";
        }
    }
    myfile<<") VALUES (";
	if(n==1)
    {
          encrypted_query_0.save(myfile); 
    }
    else if(n==2)
    {
        encrypted_query_0.save(myfile);
        myfile<<",";
        encrypted_query_1.save(myfile);
    }
    else if(n==3)
    {
        encrypted_query_0.save(myfile);
        myfile<<",";
        encrypted_query_1.save(myfile);
        myfile<<",";
        encrypted_query_2.save(myfile);
    }
    else if(n==4)
    {
        encrypted_query_0.save(myfile);
        myfile<<",";
        encrypted_query_1.save(myfile);
        myfile<<",";
        encrypted_query_2.save(myfile);
        myfile<<",";
        encrypted_query_3.save(myfile);   
    }
    else if(n==5)
    {
        encrypted_query_0.save(myfile);
        myfile<<",";
        encrypted_query_1.save(myfile);
        myfile<<",";
        encrypted_query_2.save(myfile);
        myfile<<",";
        encrypted_query_3.save(myfile);  
        myfile<<",";
        encrypted_query_4.save(myfile);         
    }

    myfile<<")";
    
    myfile.close();

	cout<<"ecrypted and saved to file"<<endl;	


}