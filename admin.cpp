#include "admin.h"
#include "certs.cpp"

using namespace std;

int main(int argc, char *argv[]){

    if(argc < 2){
        cout << "Add the number of clients you want to have.";
        exit(-1);
    }

    create_root_CA();
    client_CA(stoi(argv[1]));
   // database_CA();

}