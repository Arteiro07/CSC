#include <iostream>

int const BITS = 8;  //Define number of bits for data
class CompaResult;

    bool get_bit(int val, int position);

    void val_to_bin(int val, bool* val_bin);

    void printbin(bool* val_bin);
    
    CompaResult digital_compare(bool* A, bool* B);
    
    void client_Install();