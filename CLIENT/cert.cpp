#include "client.h"

using namespace std;
using namespace seal;


void sign();
{
    //check if the cert is signed by the ca
    system("openssl dgst -sha256 -verify ../client_1/CA/ca.crt -signature /tmp/sign.sha256 ./client_1/client_1/client.p12");
    system("");
}

void server_encrypt();
