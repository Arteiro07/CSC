#include "admin.h"
#include "certs.cpp"
#include "sealops.cpp"

using namespace std;

int main(int argc, char *argv[]){

    if(argc < 2){
        cout << "Add the number of clients you want to have.";
        exit(-1);
    }

    create_root_CA();
    client_CA(stoi(argv[1]));
    server_CA();
    generate_database_keys();
    client_Install(stoi(argv[1]));
}