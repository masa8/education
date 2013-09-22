#include <stdio.h>
#include <iostream>
#include <bitset>
/*!  Confirm the bits pattern of type float. */
class Data {
    std::bitset<32> bits;
    union 
    {
        float input;
        int   output;
    } _data;
    public:
    void set(float f){ 
        _data.input = f;
        bits = std::bitset<32>(_data.output);
    }
    void setNaN(){
        bits.reset();
        bits.flip();
        bits.flip(31);    
    }
    void setMax(){
        bits.reset();
        bits.flip();
        bits.flip(23);
        bits.flip(31);
    }
    void set2nd(){
        bits.reset();
        bits.flip();
        bits.flip(23);
        bits.flip(31);
        bits.flip(0);
    }
    float getfloat() {
        float *p;
        unsigned long templ = bits.to_ulong();
        p = reinterpret_cast<float *>(&templ);
        return *p;
    }
    void disp() { 
        printf("%1.10e ",getfloat());        
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
    Data max, second;
    max.setMax();
    max.disp();
    second.set2nd();
    second.disp();
    float diff = max.getfloat() - second.getfloat();
    std::cout << "max - 2nd = " << diff << std::endl;
}

