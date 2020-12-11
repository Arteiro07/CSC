#include "example.h"

using namespace std;
using namespace seal;

void create()
{
    ofstream myfile;
  	myfile.open ("/encrypt/encryped.txt");

    string tablename;
    string col1name;
    string aux;
    int n;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;
    cout<<"Number of columns"<<endl;
    cin>>n;
    
    string name[n];
    int type[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Insert column name"<<endl;
                getline(cin >> std::ws, name[i]);
        cout<<"Insert column type, 1 for int, 2 for text"<<endl;
        cin>>type[i];
    }

    cout<<"CREATE TABLE "<<tablename<<" (";
    for(int i=0; i<n; i++)
    {
        cout<<name[i]<<" "<<type[i]<<", ";
    }
    cout<<")";

}