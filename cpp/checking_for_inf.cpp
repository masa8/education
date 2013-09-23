#include <cmath>
#include <iostream>

int main(){

    float a = 1, b = 0;
    float inf = a/b;
    
    
    bool rtn = std::isinf(inf);     //use standard api
    std::cout << rtn << std::endl;
    bool rtn_isfinite = std::isfinite(inf); //use another api
    std::cout << rtn_isfinite << std::endl;

}

