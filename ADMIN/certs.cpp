#include "admin.h"

using namespace std;

void create_root_CA()
{
    system("rm -r CA");
    system("mkdir CA");
    system("cd CA/ && openssl genrsa -des3 -out ca.key 2048");
    system("cd CA/ && openssl req -new -x509 -days 3650 -key ca.key -out ca.crt -subj \"/C=PT/ST=Lisbon/L=Lisbon/O=CSC/OU=Servidor Web/CN=192.168.1.1\"");
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
        sprintf (buffer, "cd client_%d && openssl genrsa -des3 -out client.key 1024",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl req -new -key client.key -out client.csr -subj \"/C=PT/ST=Lisbon/L=Lisbon/O=CSC/OU=Servidor Web/CN=192.168.1.%d\"",(i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl x509 -req -in client.csr -out client.crt -sha1 -CA ../CA/ca.crt -CAkey ../CA/ca.key -CAcreateserial -days 3650", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl pkcs12 -export -in client.crt -inkey client.key -name \"User Cert %d\" -out client.p12", (i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && openssl pkcs12 -in client.p12 -clcerts -nokeys -info", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && chmod 444 client.p12", (i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
    }
}

void server_CA()
{
    system("rm -r server");
    system("mkdir server");
    system("cd server/ && openssl genrsa -out server.pem 1024");
    system("cd server/ && openssl req -new -key server.pem -out server.csr -subj \"/C=PT/ST=Lisbon/L=Lisbon/O=CSC/OU=Servidor Web/CN=192.168.1.1\"");
    system("cd server/ && openssl x509 -req -in server.csr -out server.crt -sha1 -CA ../CA/ca.crt -CAkey ../CA/ca.key -CAcreateserial -days 3650");
    system("cd server/ && chmod 444 *.crt");
}

void client_Install(int n)
{
    char buffer [256];
    for(int i=1; i<=n; i++)
    {
        sprintf (buffer, "ssh user@192.168.1.%d ""mkdir -p ~/KEYS/CA/""",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "ssh user@192.168.1.%d ""mkdir -p ~/KEYS/client/""",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "ssh user@192.168.1.%d ""mkdir -p ~/KEYS/server/""",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "ssh user@192.168.1.%d ""mkdir -p ~/KEYS/database/""",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd CA && sudo scp ca.crt user@192.168.1.%d:~/KEYS/CA/",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && sudo scp client.crt user@192.168.1.%d:~/KEYS/client/",(i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd client_%d && sudo scp client.p12 user@192.168.1.%d:~/KEYS/client/",(i+1),(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd server && sudo scp server.crt user@192.168.1.%d:~/KEYS/server/",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf (buffer, "cd database && sudo scp database_public_key.txt user@192.168.1.%d:~/KEYS/database/",(i+1));
        system(buffer);
        memset(buffer, 0, sizeof(buffer));
    }
}