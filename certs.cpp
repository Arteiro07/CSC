#include "admin.h"

using namespace std;

void create_root_CA()
{
    system("rm -r CA");
    system("mkdir CA");
    system("cd CA/ && openssl genrsa -des3 -out my-ca.key 2048");
    system("cd CA/ && openssl req -new -x509 -days 3650 -key my-ca.key -out my-ca.crt -subj \"/C=PT/ST=Lisbon/L=Lisbon/O=CSC/OU=Servidor Web/CN=192.168.1.1\"");
}

void client_CA(int n)
{
    char buffer [256];
    for(int i=1; i<=n; i++)
    {
        sprintf (buffer, "rm -r client_%d",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "mkdir client_%d",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl genrsa -des3 -out client-cert.key 1024",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl req -new -key client-cert.key -out client-cert.csr -subj \"/C=PT/ST=Lisbon/L=Lisbon/O=CSC/OU=Servidor Web/CN=192.168.1.%d\"",(i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl x509 -req -in client-cert.csr -out client-cert.crt -sha1 -CA ../CA/my-ca.crt -CAkey ../CA/my-ca.key -CAcreateserial -days 3650", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl pkcs12 -export -in client-cert.crt -inkey client-cert.key -name \"User Cert %d\" -out client-cert.p12", (i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl pkcs12 -in client-cert.p12 -clcerts -nokeys -info", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && chmod 444 client-cert.p12", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        //Connect and transfer certificate
    }

}

void database_CA()
{
    system("rm -r database");
    system("mkdir database");

}