#include "blob.h"

using namespace seal;
using namespace std;

int main()
{
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
    auto context = SEALContext(parms);

    ifstream value1file;
    string a;
    string filename = "value1.txt";

    // open sqlite3 database connection
    sqlite3* db;
    sqlite3_open("database.db", &db);

    // insert blob
    {
        sqlite3_stmt* stmtInsert = nullptr;
        sqlite3_prepare_v2(db, "INSERT INTO RH AGE, SALARY, CARS, HOUSES VALUES (27, ?, 10, 3)", -1, &stmtInsert, nullptr);

        value1file.open(filename.c_str(), ofstream::binary);
        getline(value1file, a);
        Ciphertext value1; // your data

        cout<<"value1 var created"<<endl;
        value1.load(context, value1file);
        cout<<"value1 var load"<<endl;

        sqlite3_bind_blob(stmtInsert, 1, value1.data(), static_cast<int>(value1.size() * sizeof(float)), SQLITE_STATIC);

        if (sqlite3_step(stmtInsert) == SQLITE_DONE)
            cout << "Insert successful" << endl;
        else
            cout << "Insert failed" << endl;

        sqlite3_finalize(stmtInsert);
    }

   

    sqlite3_close(db);

    return 0;
}

//int retrieve_blob() {
//
// // retrieve blob
//    {
//        sqlite3_stmt* stmtRetrieve = nullptr;
//        sqlite3_prepare_v2(db, "SELECT vector_blob FROM table_name WHERE id = ?", -1, &stmtRetrieve, nullptr);
//
//        int id = 1; // your id
//        sqlite3_bind_int(stmtRetrieve, 1, id);
//
//        std::vector<float> blobData;
//        if (sqlite3_step(stmtRetrieve) == SQLITE_ROW)
//        {
//            // retrieve blob data
//            const float* pdata = reinterpret_cast<const float*>(sqlite3_column_blob(stmtRetrieve, 0));
//            // query blob data size
//            blobData.resize(sqlite3_column_bytes(stmtRetrieve, 0) / static_cast<int>(sizeof(float)));
//            // copy to data vector
//            std::copy(pdata, pdata + static_cast<int>(blobData.size()), blobData.data());
//        }
//
//        sqlite3_finalize(stmtRetrieve);
//    }
//}