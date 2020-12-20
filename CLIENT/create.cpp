#include "client.h"

using namespace std;
using namespace seal;

void create()
{

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

    cout<<"CREATE TABLE "<<tablename<<" (";
    for(int i=0; i<n; i++)
    {
        cout<<name[i];
        if(i < (n-1))
        {
            cout<<", ";
        }
    }
    cout<<")"<<endl;

    ofstream myfile;
    myfile.open ("encrypt/encrypted.txt");
    myfile<<"1 "<<n<<" "<<tablename<<" ";
    for(int i=0; i<n; i++)
    {
        myfile<<name[i]+" ";
    }
    myfile.close();
}