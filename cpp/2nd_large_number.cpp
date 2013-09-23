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
        bits.reset();
        bits = std::bitset<32>(_data.output);
    }
    void setNaN(){
        /* e=255, m!=0 => NaN */
        bits.reset();
        bits.flip();
        bits.flip(31);    
    }
    void setInf(){
        /*! e=255, m==0 => inf */
        bits.reset();
        for ( size_t i = 23; i < 32; ++i ) {
                bits.flip(i);
        }

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
    void set14and5(){
        bits.reset();
        bits.flip(30);
        bits.flip(24);
        bits.flip(22);
        bits.flip(21);
        bits.flip(19);
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

    Data omake;
    omake.set14and5();
    omake.disp();
    omake.setInf();
    omake.disp();
    omake.set(0.1f);
    omake.disp();
}

