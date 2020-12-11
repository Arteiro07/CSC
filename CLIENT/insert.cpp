#include "example.h"

using namespace std;
using namespace seal;

void insert( )
{

///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    //
    parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));

    SEALContext context(parms);

    auto qualifiers = context.first_context_data()->qualifiers();

    KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);
    RelinKeys relin_keys;
    keygen.create_relin_keys(relin_keys);
    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    Decryptor decryptor(context, secret_key);

    BatchEncoder batch_encoder(context);

    size_t slot_count = batch_encoder.slot_count();
    size_t row_size = slot_count / 2;
    cout << "Plaintext matrix row size: " << row_size << endl;

    vector<uint64_t> pod_result;
    vector<uint64_t> pod_matrix(slot_count, 0ULL);
    Plaintext plain_matrix;

///////////////////////////////////////////////////////////////////////////////////////////SEAL///////////////////////////////////////////////////////////////////////////////////////////
   	

    string tablename;
 
    string mode;


    int n;

    char op_1;
    char op_2;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;

    cout<<"Number of columns?";
    cin>>n;

    string name[n];
    int value[n];

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

//
    for(int i = 0; i<n; i++)
    {
        pod_matrix[i] = value[i];
    }
    batch_encoder.encode(pod_matrix, plain_matrix);
    Ciphertext encrypted_matrix;
    encryptor.encrypt(plain_matrix, encrypted_matrix);


    cout<<"ecrypted"<<endl;	

    ////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////

//    ofstream myfile;
//    myfile.open ("encrypt/encrypted.txt");
//
//    myfile<<"SELECT "<<name_1<<" FROM "<<tablename<<" WHERE "<<name_1<<" "<<op_1<<" "<<"value_1"<<" "<<mode<<" "<<name_2<<" "<<op_2<<" "<<"value_2"<<endl;
//
//    encrypted_query_1.save(myfile);
//    encrypted_query_2.save(myfile);
//
//    myfile.close();
//
//	cout<<"ecrypted and saved to file"<<endl;	
//
//    ////////////////////////////////////////////////////////////////////Write to file////////////////////////////////////////////////////////////////////
}