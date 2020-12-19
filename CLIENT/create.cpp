#include "example.h"

using namespace std;
using namespace seal;

void create()
{
    ofstream myfile;
  	myfile.open ("/encrypt/encryped.txt");

    string statement;
    string type="1 ";
    string tablename;
    string col1name;
    string aux;
    int n;

    cout<<"Insert tablename"<<endl;
    cin>>tablename;
    cout<<"Number of columns"<<endl;
    cin>>n;
    
    string name[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Insert column name"<<endl;
                getline(cin >> std::ws, name[i]);
    }

    statement=type+to_string(n)+" "+tablename+" ";

    cout<<"CREATE TABLE "<<tablename<<" (";
    for(int i=0; i<n; i++)
    {
        cout<<name[i]<<" "<<", ";
        statement=statement+name[i]+" ";
    }
    cout<<")";

    myfile<<statement;

}