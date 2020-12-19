#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stdout, "%s: \n\n", (const char*)data);

    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

    int query(std::string filename);
    std::string readFile(std::string fileName);