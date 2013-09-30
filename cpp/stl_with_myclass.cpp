#include <stdio.h>
#include <vector>
#include <algorithm>

class MyC {
    public:
    int x;
    int y;

    MyC(int xin, int yin):x(xin),y(yin){}

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
    v.push_back(a);
    v.push_back(b);
    functor f;
    std::for_each(v.begin(),v.end(),functor());




}
