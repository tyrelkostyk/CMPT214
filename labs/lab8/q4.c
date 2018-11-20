/*
 * Program for Q4 of Lab 08
 */
#include <stdlib.h>
#include <stdio.h>

void square()
{
    int  a = 5;
    int sa = 5;

    // square the two variables
    a = a*a;
    sa = sa*sa;

    printf("a: %d, sa: %d\n", a, sa);
    // functions of type void don't need a return statement
}

int main(void)
{
    int i;
    // call square() ten times
    for(i=0; i<10; i++)
    {
        square();
    }

    return 0;
}

