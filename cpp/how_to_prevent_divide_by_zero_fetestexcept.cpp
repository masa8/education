#include <stdio.h>
#include <math.h>
#include <fenv.h>
/*!
    http://linux.die.net/man/3/fetestexcept

   Exceptions
   ==========
    The divide-by-zero exception occurs when an operation on finite 
    numbers produces infinity as exact answer.

   Exception Handling 
   ==================
    Exceptions are represented in TWO WAYS as a gingle bit, and 
    these bits correspond in some implementation-defined way 
    with bit positions in an integer.

    Each of the macros FE_DIVBYZERO, ,,, is defined when the implementation
    supports handing of the correspoinding exception, and if so 
    then defines the coresponding bits(s), so that 
    one can call exception handling functions.
    The macro FE_ALL_EXCEPT is the bitwise  OR of all bits correspoinding
    to supported exceptions.

    feclearexcept()     : clear the supported exceptions
    fegetexceptionflag(): store representation of the state of excecp flag
    feraiseexcept()     : raise the supported exceptions
    fesetexceptflag()   : set the complete status
    fetestexeptflag()   : return a word in which the bits are set 
                          that were set in the argument except and
                          for which the corresponding exception is
                          currently set.
*/
int main(void)
{


    float a = 0.0f;
    float b = 1/a; 
    int exception = fetestexcept( FE_DIVBYZERO );
    if ( exception != 0 )
    {
        printf("Exception: 0x%x\n",exception); 
    }


    float c = 0/0.0f;
    int exception_nan = 0;
    exception_nan = fetestexcept( FE_INVALID );
    if ( exception_nan != 0){
        printf("Excpetion: 0x%x\n", exception_nan);
    }
}
