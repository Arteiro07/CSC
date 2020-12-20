#include "client.h"

using namespace std;
using namespace seal;

int main()
{

	//vanila declarations
	int selection;
	bool valid;
	string garbage;

	cout<<"Print the type of query you want to excute:"<<endl;
	cout<<"0- quit"<<endl;
	cout<<"1- Create"<<endl;
	cout<<"2- Insert"<<endl;
	cout<<"3- Query"<<endl;
	cout<<"4- Sum"<<endl;
	do
	{
		cout << endl << "> Run (1 ~ 4) or exit (0): ";
		if (!(cin >> selection))
		{
			valid = false;
		}
		else if (selection < 0 || selection > 6)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}
		if (!valid)
		{
			cout << "  [Beep~~] valid option: type 0 ~ 4" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!valid);

	switch (selection)
	{
	case 1:
		create();
		break;

	case 2:
		insert();
		break;

	case 3:
		query();
		break;

	case 4:
		sum();
		break;

	case 0:
		return 0;
	}

	sign();
	//Encrypt();
	cout<<"Wait for response from database, press enter when ready."
	cin>>garbage;



}