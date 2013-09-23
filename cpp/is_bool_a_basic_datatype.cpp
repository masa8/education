/*!
http://stackoverflow.com/questions/356726/is-bool-a-basic-datatype-in-c

    bool is a fundamental datatype in C++,
    Converting true to an integer type will yeild 1,
    and converting false will yeild 0 (4.5/4 and 4.7/4).

    In C, until C99, there was no bool datatype,
    and people did stuff like
    enum bool {
        false, true 
    }

*/


#include <iostream>



enum _bool {
    _false = 0,
    _true = 1,
    i_dont_know = 2
};

int main() {
    
    bool builtin_datatype = true;
    std::cout << "bool is a buitin data type in C++: " << builtin_datatype 
        << std::endl;

    enum _bool mybool = i_dont_know;
    std::cout << mybool << std::endl;

    

}
