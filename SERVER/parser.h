#include <fstream>
#include <iostream>
#include <string>
#include "seal/seal.h"

using namespace std;
using namespace seal;

string parser(string filename);
string create(int n_cols, ifstream &file);
string insert(int n_cols, ifstream &file);
string selectfrom(int n_cols, ifstream &file);
string selectsum(int n_cols, ifstream &file);