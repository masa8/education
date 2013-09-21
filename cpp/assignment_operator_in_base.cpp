#include <stdio.h>
/*!
	http://en.wikipedia.org/wiki/Object_slicing
	

	Object slicing is also used to a more subtle, problematic, case
	in which an object assignment by value appears to be to a 
	superclass instance but is actually to a SUBCLASS INSTANCE..

	From the perspective of object memory layout,
	the member variables of the source instance can be though of as 
	having been "sliced off", leaving the corresponding membe variables
	in the destination instance UNCHANGED.
	
	It is this partial assignment ( arguably a more apt term) that 
	often surprises programmers and leads to unintended consequences.

	It is not possible in the D lang. which allows object inheritance
	only through reference types.
*/
struct A {
    int a;
    A(int arg):a(arg){}
    virtual ~A(){}
public: /*! making this method public makes a = b compatible. */
    virtual A& operator=(const A& rhs){ a = rhs.a; printf("A::=\n"); }
public:
    virtual void print() { printf("A::a %d\n",a); } 
};

struct B : public A {
    int b;
    B(int arg1, int arg2): A(arg1), b(arg2){}
public: /*! makeing this method pubic makes b1 = b2 compatible. */
    virtual B& operator=(const B& rhs){ 
	A::operator=(rhs);
	b = rhs.b;
	printf("B::=\n"); 
    }
public:
    virtual void print() { printf("B::a %d b %d\n", a,b); }
};


int main()
{
	
{
   printf("Case 1: assign b(1,2) to a1(5).\n \
 			Slicing happen. but it's expected.\n");
    A a1(5);
    B b1(1,2);
    a1 = b1; //slicing happen. but it's ok.
    a1.print();
}
{    
    printf("Case 2: assign b(1,2) to b2(3,4). \n \
			Slicing is NOT happen.\n");
    B b1(1,2), b2(3,4);

    b2= b1; //ok
    b2.print();
}
{
    printf("Case 3: assign b2(3,4) to reference of A which points to a1(5). \n \
			Slicing is happen. but it's expected.\n"); 
    A a1(5);
    B b2(3,4);
    A& r = a1;
    r = b2;
    r.print();
}
{
    printf("Case 4: assign b(1,2) to reference of B2(3,4) via A&.\n \
			Slicing is happen. and B::b is NOT updated. \n \
			This is NOT expected.\n");
    B b1(1,2), b2(3,4);
    A& r = b1; 
    r = b2;
    r.print();

}


} 
