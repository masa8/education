#include <stdio.h>

struct MYDATA { 
    int x;
    int y;
    
    MYDATA(int xin,int yin):x(xin),y(yin){}

};

/*! 
    how to aviod error "no matching function for ..." 
                        instantiated from here.
*/

template <class T>
class MyT {
public: 
    MyT<T>(){}
    MyT(T t) :mt(t){/*mt= t; */ } //initialization list added
    T getData(){ return mt; }
private:
    T mt;

};


int main (){

    int x = 2;
    MyT<int> c(x);
    printf("%d\n",c.getData());
    
    MYDATA m(3,3);
    MyT<MYDATA> xc(m);
    printf("%d %d\n",xc.getData().x,xc.getData().y);
}
