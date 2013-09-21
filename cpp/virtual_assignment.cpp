#include <stdio.h>
class X {
public:
    int x;
    X(int inx): x(inx) {}
    virtual void doSomething() = 0;
    virtual void print() { printf("X(%d)\n",x); }
    virtual X& operator=(const X& rhs) {
        printf("X& X::operator=() \n");
        x = rhs.x;
        return *this;
    }
};


class Y : public X {
public:
    int y;
    Y(int inx,int iny) : X(inx), y(iny) {}
    void doSomething() { printf("Hi, I'm Y."); }
    virtual void print() { printf("Y(%d,%d)\n",x,y); }  
    virtual X& operator=(const X& rhs);
    Y& operator=(const Y& rhs);
};

X& Y::operator=(const X& rhs) {
    printf("X& Y::operator=() \n");
    const Y& obj = dynamic_cast<const Y&>(rhs);
    X::operator=(rhs);
    y = obj.y;
    return *this;
}

Y& Y::operator=(const Y& rhs) {
    printf("Y& Y::operator=() \n");
    X::operator=(rhs);
    y = rhs.y;
    return *this;
}

int main()
{
    Y a(1,2);
    Y a2(3,4);
    X& r = a;
    r = a2; /* I made X (which has a pure function). */
        /* and made its assignment operator public. */
        /* I would like to avoid slicing problem. */
        /* So, X's assignment operator need to be overrided. */
        /* Anyway, I could call abstract base class's assignment operator! */
    r.print();      
}

