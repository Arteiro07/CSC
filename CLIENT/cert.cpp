#include "client.h"

using namespace std;
using namespace seal;


void sign();
{
    system("openssl x509 -sha256 -days 365 -in ../client_1/client/client.crt -signkey ../client_1/CA/ca.key -out client.pem ");
    system("");
}

void server_encrypt();
{



}