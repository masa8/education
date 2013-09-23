/*!
	http://stackoverflow.com/questions/11299992/divide-by-zero-prevention
    http://en.wikipedia.org/wiki/Division_by_zero

    In mathematics, dividion by zero is division where the divisor(
    denominator) is zero. Such a division can be formally expressed
    as a/0 where a is the dividend ( numerator).

    Whether this expression can be assigned a well-defined value depends
    upon the mathematical setting. In ordinaly arithmetic ,
    the expression has no meaning as there is no number which ,
    multiplied by 0, gives a , and so division by zero is undefined.
    Since any number multiplied by zeo is zero, the expression 0/0 has 
    no defined value and is called an indeteminate form.
*/
#include <stdio.h>
#include <float.h>
#include <stdexcept>

float dividebyzero(float a, float denomi){
    if ( denomi == 0 ) {
        throw std::overflow_error("divide by zero");
    }
    float result = a/denomi;
    return result;
}
int main()
{
    try{
         dividebyzero(1,0); 
    }catch(std::overflow_error *e){
        printf("%s",e->what());
    }

}

