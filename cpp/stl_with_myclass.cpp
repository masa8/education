#include <stdio.h>
#include <vector>
#include <algorithm>
/*!
    For std::vector<T> to compile,

        Default-Constructible   Option(when you use resize(), MUST)
        Copy-Constructive       MUST
        Copy-assignable         MUST

    NOTE*
    you explicitly declare absolutely any constructor
    for a class, the compiler STOPs providing the implicit
    default constructor.        
 
*/ 
class MyC {
    public:
    int x;
    int y;

    MyC(int xin, int yin):x(xin),y(yin){}
    private:
    MyC():x(0),y(0){}
};
class MyCC {
public:
    MyCC(){}
    MyCC(const MyCC&) {}
    MyCC& operator =(const MyCC&) {}
};
class functor {
public:
    void operator()(MyC& i){
        printf("%d %d\n", i.x,i.y);
    }
};
int main(){
    
    MyC a(1,1);
    MyC b(1,2);

    std::vector<MyC> v;
    //v.resize();  //When uncomment, you must make DCtor public.
    v.push_back(a);
    v.push_back(b);
    functor f;
    std::for_each(v.begin(),v.end(),functor());

    std::vector<MyCC> vc;
    MyCC c;
    vc.push_back(c);




}
