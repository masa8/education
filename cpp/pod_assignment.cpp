#include <iostream>

struct POD {
    int x;
    int y;
};
/*!
        http://en.cppreference.com/w/cpp/language/as_operator

    Trivial copy assignment operator
    
    The implicitly-declaredcopy assignment operator for classT
    is trivial if all of the following is true:
    + T has no virtual funcitons
    + T has no virtual base classes
    + The copy assignment operator selectef ofr every direct base of T
      is trivial
    + The copy assignment operator selected every non-static class type
      member of T is trivial

    =>A trivial copy assignmet operator makes a copy of the object 
        representationas if by std::memmove. all data types compatible
        with the C language(POD types) are trivially copy-assignable.

*/
int main () {

    POD a, b;
    a.x = 1;
    a.y = 1;

    std::cout << b.x << " " << b.y << std::endl;
    b = a;
    std::cout << b.x << b.y << std::endl;
    
    

}
