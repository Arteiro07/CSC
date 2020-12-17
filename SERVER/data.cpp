#include "data.h"


using namespace std;

class CompaResult {         // The class
  	public:               // Access specifier
    bool bigger=false;
    bool lesser=false;
    bool equals=false;

	CompaResult(bool big, bool less, bool eq) { // Constructor with parameters
        bigger=big;
        lesser=less;
        equals=eq;
    }
};

//Busca o bit de determinada posiçao de um valor numerico
bool get_bit(int val, int position)
{
	bool bit = val & (1 << position);
	return bit;
}

//Converte um valor numerico em binário
void val_to_bin(int val, bool* val_bin) {
    for (int i = 0; i < BITS-1; i++)
    {
        val_bin[i]=get_bit(val,i);
    }
    
}

//Imprime para o terminal a representaçao binaria de uma variavel
void printbin(bool* val_bin) {
		for(int i = BITS-1; i >= 0; i--) {
			if(val_bin[i]) {
				cout << "1 ";
			}else{
				cout << "0 ";
			}		
		}
		cout << "(" << (sizeof(val_bin)/sizeof(*val_bin)) << " bits)";
		cout << endl;
    }

CompaResult digital_compare(bool* A, bool* B) {
    bool i_A_bigger_B=false, i_A_lesser_B=false, i_A_equals_B=true;
    bool o_A_bigger_B=false, o_A_lesser_B=false, o_A_equals_B=false;
    bool nand_aux=false;
    for (int i = BITS-1; i >=0 ; i--)
    {
        //cout<<"i: "<<i+1<<endl;
        if (i_A_bigger_B) {
            o_A_bigger_B = true;
            break;
        }
        else if (i_A_lesser_B) {
            o_A_lesser_B = true;
            break;
        }
        else if (i_A_equals_B) {
            o_A_bigger_B = A[i]*!B[i];
            o_A_lesser_B = !A[i]*B[i];
            nand_aux = !(!(A[i]*A[i]) * !(B[i]*B[i]));
            o_A_equals_B = !(nand_aux * !(A[i]*B[i]));
            //cout<<"bigger: "<<o_A_bigger_B<<endl;
            //cout<<"lesser: "<<o_A_lesser_B<<endl;
            //cout<<"equals: "<<o_A_equals_B<<endl;

        }
        i_A_bigger_B = o_A_bigger_B;
        i_A_lesser_B = o_A_lesser_B;
        i_A_equals_B = o_A_equals_B;
    }
    CompaResult result(o_A_bigger_B, o_A_lesser_B, o_A_equals_B);
    return result;
}