/*!
http://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement
*/
/*
The STL allocator is one of the most overlooked topic in most C++
   teachings. They are rarely used explicitly, either via direct client
code, or direct construction of an allocator to be used in a container.
The possible, and perhaps only area, where you might even notice the word
allocator is when you make use of the STL container classes, and
wonder whant that last parameter ( Allocator) actually is.

In this article I will explain 
    the purpose of the allocator,
    What qualifies as a Standard C++ allocator, 
    how can be implemented 

definiton
========
    define type of pointer to  T(pointer)
                   pointer to const T (const_pointer)
                   reference to T(reference)
                   reference to const T(const_reference)
                    type of T itself   (value_type)
                    largest object     ( size_type)
                    represent diffrence ( difference_type)

    The standares thenrequire a template class rebind member,
    whihc should pay heed of the following paragraph from 20.1.5.3


In short given allocator<T>,
we can simply do, allocator::rebind<U>::other.allocate(1) to be
allocating memory large enough to hold an object U.
This is the magic required for STD::LIST to work prpperly,
since givenstd::listint>(allocatro<int>()),std::list
actually need s to allocate memory for Node<int>, and not int.
Thus, they ned to rebindto allcate<int>()::rebind<Node<int>>::other
instead.

Next, we have to provide a functon to simply rturn the address of a 
given object(address). What followers is the heart of the allocator,
a fnciton to allocate memory forn objects of type T but not 
construct theobject (allocte(n,u), wehre u is a hint for object 
memory models)
as well a funciton to deallocate nobject of type T( dealocate(p, n).
object must be destroyed prior to this call.


As mentioned, allocate and deallocate are simply low level memory
management and do not play a part in object construction adn 
destraction. This would mean that the default usgage of the
keyword new and delete would not apply in these funcitons.
as any intermediate C++ programmer should know the following code


A* a = new A;
delete a;

is actually interpreted by the compiler as

A* a = ::operator new(sizeof(A));
a->A::A();

if( a!= 0 ) {
    a->~A();
    ::operater delete(a);
}


Te purpose of the allocator is to allocateraw memory without 
construcotn of objects, as weell as simply deallocate memory whitou the
need to destory them, hence the usage of operatornew and
operator delete dirctory is preferred over the usage of the 
keyword new and delete.

following these are helper funcitons to do:
    copy construction( construciton(p, t)) and
    destory(delete(p))
    getting largest value to allocate (max_size)
    copy construction and default constructor
    equality chekcing ( == and != )

*/

/*! A sample allocator */
#include <cstddef>
#include <memory>
#include <limits>
#include <iostream>
#include <stdio.h>
namespace masaya {

template<typename T>
class Allocator {
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

public:
    template<typename U>
    struct rebind {
        typedef Allocator<U> other;
    };

public:
    inline explicit Allocator(){}
    inline ~Allocator(){}
    inline explicit Allocator(Allocator const&){}
    template<typename U>
    inline explicit Allocator(Allocator<U> const&) {}

    inline pointer address(reference r) { return &r; }
    inline const_pointer address(const_reference r) { return &r; }

    // memory allocate
    inline pointer allocate(size_type cnt,
                typename std::allocator<void>::const_pointer = 0){
            printf("ALLOCATE\n");
            return reinterpret_cast<pointer>(::operator new(cnt*sizeof(T)));
    }

    inline void deallocate(pointer p, size_type){
        printf("DELETE\n");
        ::operator delete(p);
    }         
    
    inline size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    inline void construct(pointer p, const T& t) { 
            printf("CONSTRUCT\n");
            new(p) T(t); 
    }
    inline void destroy(pointer p){ 
            printf("DESTORY\n");
            p->~T(); 
    }

    inline bool operator==( Allocator const& ) { return true; }
    inline bool operator!=( Allocator const& a){ return !operator==(a);}

};

/*! 
    This is the basic implementation of anallocator,
    which should be similar to most std::allocator provided by 
    your compiler's vendor.
    HOWEVER< tothe experienced reader, one could immediately 
    identify a possible error. &r could only workif T did NOT provide 
    an overloaded operator & , and T should , must return the address
    of an object T.
*/

};
#include <vector>
int main(){

    std::vector<int,masaya::Allocator<int> > v;
    v.push_back(1);
    printf("%d\n",v.size());

}








