#include <stdio.h>
#include <iostream>
#include <bitset>
/*!  Confirm the bits pattern of type float. */
class Data {
    union 
    {
        float input;
        int   output;
    } _data;
    public:
    void set(float f){ 
        _data.input = f;
    }
    void disp() { 
        std::bitset<32> bits(_data.output);
        std::cout << _data.input << ":\t";
            
        for ( int i = 31; i >= 0; --i){
            std::cout << bits[i];
            if ( i == 31 ) {
                std::cout << " ";
            }else if ( i == 23 ) {
                std::cout << " (1) ";
            }
        }
        std::cout << std::endl;
    }
             
};

int main() {
    Data data;
    data.set(0);
    data.disp();


}

