#include <stdio.h>
#include <string.h>
#include <algorithm>

struct ID {
    int age;
    int size;
    char *name;

    /*! Copy Ctor */
    ID(const ID& rhs):
    age(rhs.age),
    size(rhs.size),
    name(size ? new char[size]():NULL)
    {
        printf("CopyCtor(%d,%d)\n",rhs.age,rhs.size);
        std::copy(rhs.name,rhs.name + rhs.size,name);
    }
    /*! Default Ctor */
    ID():
    age(0),
    size(), 
    name(size ? new char[size]():NULL){ printf("DCtor\n");}
    
    ID(int age_in,int size_in):
    age(age_in),
    size(size_in),
    name(size ? new char[size]() : NULL)
    { printf("Ctor(%d,%d)\n",age,size);}

    /*! Dtor */
    ~ID(){ printf("Dtor[%s][size%d]\n",name,size); delete [] name; }
    

    void setName(const char * in_name) {
        if (size == 0 ){
            return;
        }
        strncpy(name,in_name,size - 1);
    }

    ID& operator= (/*const*/ ID/*&*/ rhs){
        printf("Assign!\n");
        swap(this,&rhs);
        return *this;
        /*
        if( this == &rhs ){
            return *this;
        }

        age = rhs.age;
        char * temp = rhs.size ? new char[size]():NULL;
        std::copy(rhs.name, rhs.name + rhs.size, temp);
        delete [] name;
        name = temp;
        size = rhs.size;

        return *this;*/
    }

    void swap(ID *original, ID *copied){
        std::swap(original->size,copied->size);
        std::swap(original->name,copied->name);
        std::swap(original->age,copied->age);
    }
};
int main(){

    ID a(6,11),b;
    a.setName("HelloWorld");
    printf("---%s (size:%d)\n",b.name,b.size);
    printf("---%s (size:%d)\n",a.name,a.size);
    
    b = a;
    printf("===%s (size:%d)\n",b.name,b.size);
    printf("===%s (size:%d)\n",a.name,a.size);

}
