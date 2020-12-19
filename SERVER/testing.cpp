#include "testing.h"
#include "data.cpp"

using namespace std;

int main() {
    int x,y;
    bool a[BITS], b[BITS];
    int continuar = 0;
    
    do
    {
        cout << "Type X: ";
        cin >> x;
        cout << "Type Y: ";
        cin >> y;
        val_to_bin(x, a);
        cout<<"X (binary): ";
        printbin(a);
        val_to_bin(y, b);
        cout<<"Y (binary): ";
        printbin(b);
        cout<<"Comparando... "<<endl;
        CompaResult result = digital_compare(a, b);

        if (result.bigger)
        {
            cout << "X maior que Y";
            cout<<endl;
        }
        else if (result.lesser)
        {
            cout<<"X menor que Y";
            cout<<endl;
        }
        else if (result.equals)
        {
            cout<<"X igual a Y";
            cout<<endl;
        }
        else
        {
            cout<<"Nao conseguiu comparar";
            cout<<endl;
        }
        
        cout << "Continuar? Sim(1) ou Nao(0): ";
        cin >> continuar;

    } while (continuar);

    return 0;
}
