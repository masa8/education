/*!
    http://yebisu.cc.kyushu-u.ac.jp/~watanabe/RESERCH/MANUSCRIPT/KOHO/FLOATING/float.pdf

    x^4 - 4y^2 - 4y^4 = 1 (x = 665857, y =  470832 )

    x^4 = 196573006004558194713601
    4y^2= 196573006003671463624704
    4y^4=             886731088896
*/
#include <stdio.h>
#include <iostream>
#include <math.h>

#define NUM_TYPE float

 

int main () {
    
 

    NUM_TYPE x,y;
    x = 665857.0;
    y = 470832.0;
    
    NUM_TYPE part = x*x*x*x;
    NUM_TYPE part2 = 4*y*y;
    NUM_TYPE part3 = 4*y*y*y*y;
    
    printf("Correct ANS: =\t196573006004558194713601\n");
    printf("x^4:\t\t%lf\n", part);
    
    printf("Correct ANS: =\t            886731088896\n");
    printf("4*y^2:\t\t%031lf\n",part2);

    printf("Correct ANS: =\t196573006003671463624704\n");
    printf("4*y^4:\t\t%lf\n",part3);
    std::cout << std::endl;

    NUM_TYPE part12 = part-part2;
    printf("part1-part2:\t%lf\n",part12);
    NUM_TYPE part123 = part12 - part3;
    printf("part1-part2-part3\t%lf\n",part123);    
    NUM_TYPE result = (x*x*x*x)-(4*y*y)-(4*y*y*y*y);
    printf("RESULT:\t%lf",result);

    
}


