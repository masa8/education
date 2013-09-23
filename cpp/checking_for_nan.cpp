#include <cmath>
#include <iostream>

int main(){

    float a = 0, b = 0;
    float nan = a/b;
    
    
    bool rtn = std::isnan(nan);     //use standard api
    std::cout << rtn << std::endl;

    if ( nan == nan ){
        std::cout << "nan eq nan" << std::endl;
    }
    else {
        /*! Nan is not equal to any number, INCLUDING ITSELF.*/
        std::cout << "nan always not eq nan" << std::endl;
    }

}

