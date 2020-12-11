#include "admin.h"

using namespace std;

void create_root_CA()
{
    system("rm -r CA");
    system("mkdir CA");
    system("cd CA/ && sudo openssl genrsa -out my-ca.key 2048");
    system("cd CA/ && sudo openssl req -new -x509 -days 3650 -key my-ca.key -out my-ca.crt");
}

void client_CA(int n)
{
    char buffer [50];
    for(int i=0; i<n; i++)
    {
        sprintf (buffer, "rm -r client_%d",(i+1));
        system(buffer);
        sprintf (buffer, "mkdir client_%d",(i+1));
        system(buffer);

    }

}

void database_CA()
{
    system("rm -r database");
    system("mkdir database");

}