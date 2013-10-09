#include <stdio.h>
#include <map>
/*!
    Reason Value object must have DCtor:
    When operator [] called, and fi the map does not already contan such an
    object, opator [] inserts the DEFAULT OBJECT for value.

*/
class MyValue {
public:
    int x;
    int y;
    MyValue():x(),y(){}
    MyValue(int xin,int yin):x(xin),y(yin){}

};


int main (){

    std::map<int,MyValue> mymap;
    mymap[0] = MyValue(0,0);
    printf("size:%d\n",mymap.size());
}
