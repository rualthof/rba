//http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html

#include "t5.h"
#include <stdio.h>

int main()
{
    int x = 4;
    int y = 5;

    int z1 = Addition::twoValues(x,y);
    printf("\nAddition Result: %d\n", z1);

    int z2 = Multiply::twoValues(x,y);
    printf("Multiply Result: %d\n", z2);

    //delete corporation;
    return 0;
}

