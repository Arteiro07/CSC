#include "database.h"
#include "parser.cpp"

using namespace std;

int query(string filename) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string fcontent;
    char *sql;
    const char* data = "Query result";
    int a; //TESTE//
    //ifstream MyReadFile(filename);

    /* Open database */
    rc = sqlite3_open("databse.db", &db);

    if( rc ) {
        fprintf(stdout, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    //fcontent = readFile(filename);
    fcontent = parser(filename);
    cout<<fcontent<<endl;
    if (fcontent.empty()) {
        cout << "Couldn't open file or content is empty" << endl;
        return (0);
    }

    sql = &fcontent[0];

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stdout, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Query performed successfully\n");
    }
    sqlite3_close(db);
    return 1;
}

string readFile(string fileName) 
{  
    ifstream input(fileName); 
 
    if (!input.good()) 
    { 
        return("");
    } 
 
    string line; 
    getline(input, line);
    input.seekg(0); 
    string contents; 
 
    { 
        ostringstream output; 
        output << input.rdbuf(); 
        contents = output.str(); 
    }

    return contents; 
}


//TESTING//
int main() {
    string filename;
    cerr << "Introduce filename: ";
    cin >> filename;
    query(filename);
}