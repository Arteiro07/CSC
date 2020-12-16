#include "sealops.h"

using namespace std;
using namespace seal;

void generate_database_keys(){
    system("rm -r database");
    system("mkdir database");

    // Define contexto e parametros para gerar as chaves
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
    auto context = SEALContext(parms);

    // Gerando as chaves
    KeyGenerator keygen(context);
    Serializable<PublicKey> database_public_key = keygen.create_public_key();
    SecretKey database_secret_key = keygen.secret_key();

    // Salvando as chaves em arquivos
    ofstream publickeyfile;
    publickeyfile.open("database_public_key.txt", ofstream::binary);
    database_public_key.save(publickeyfile);
    publickeyfile.close();
    ofstream secretkeyfile;
    secretkeyfile.open("database_secret_key.txt", ofstream::binary);
    database_secret_key.save(secretkeyfile);
    secretkeyfile.close();

    // Movendo os arquivos para o lugar correto
    system("sudo cp database_public_key.txt database");
    system("sudo rm -r database_public_key.txt");
    system("sudo cp database_secret_key.txt database");
    system("sudo rm -r database_secret_key.txt");
}