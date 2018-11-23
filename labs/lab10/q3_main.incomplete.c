/*
 * for Lab 10
 *
 * Author: Marina Schmidt
 */

#include <stdlib.h>
#include <stdio.h>

// place the fix here

int main(void)
{

    float a= 5.0;
    float b= 6.0;

    printf("Performing the following calculations on %f and %f\n",a,b);
    printf("addition:  %f\n",add(a,b));
    printf("subtraction: %f  \n",sub(a,b));
    printf("Multiplication: %f\n",mult(a,b));
    printf("Power: %f\n",power(a,b));

    return 0;
}
