#include "example.h"

using namespace std;
using namespace seal;

int main()
{

	//vanila declarations
	int selection;
	bool valid;


	cout<<"Print the type of query you want to excute:"<<endl;
	cout<<"0- quit"<<endl;
	cout<<"1- Create"<<endl;
	cout<<"2- Insert"<<endl;
	cout<<"3- Query"<<endl;
	cout<<"4- Sum"<<endl;
	do
	{
		cout << endl << "> Run (1 ~ 4) or exit (0): ";
		if (!(cin >> selection))
		{
			valid = false;
		}
		else if (selection < 0 || selection > 6)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}
		if (!valid)
		{
			cout << "  [Beep~~] valid option: type 0 ~ 4" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!valid);

	switch (selection)
	{
	case 1:
		create();
		break;

	case 2:
		insert();
		break;

	case 3:
		query();
		break;

	case 4:
		sum();
		break;

	case 0:
		return 0;
	}

}



//
	//EncryptionParameters parms(scheme_type::bfv);
    //size_t poly_modulus_degree = 4096;
    //parms.set_poly_modulus_degree(poly_modulus_degree);
//
    //parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
	//parms.set_plain_modulus(1024);
	//SEALContext context(parms);
//
	////Remove comments to check params
	////print_line(__LINE__);
    ////cout << "Set encryption parameters and print" << endl;
    ////print_parameters(context);

	//KeyGenerator keygen(context);
    //SecretKey secret_key = keygen.secret_key();
    //PublicKey public_key;
    //keygen.create_public_key(public_key);
//
    //Encryptor encryptor(context, public_key);
//
	//Ciphertext encrypted_query;
//	
	//	Plaintext p_query(query);//plaintext query
	//	//cout<< p_query.to_string()<< endl;
	//	encryptor.encrypt(p_query, encrypted_query);
	//	cout<<"ecrypted"<<endl;	
//
	//	Plaintext x_decrypted;    	
//
	//	Decryptor decryptor(context, secret_key);
    //	decryptor.decrypt(encrypted_query, x_decrypted);
    //	cout << "0x" << x_decrypted.to_string() << " ...... Correct." << endl;
	//
	//}
	//
	//return 0;

//