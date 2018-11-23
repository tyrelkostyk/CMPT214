/*
 * for Lab 10
 *
 * Author: Marina Schmidt
 */

#include "q3_calc.h"

float add(float x,float y)
{
    if (y==0)
        return x;
    return add(++x,--y);
}

float sub(float x,float y)
{
    if (y==0)
        return x;
    return sub(--x,--y);
}

float mult(float x,float y)
{
    if (x ==0.0 || y == 0.0)
        return 0.0;
    if (x==1.0)
        return y;
    if (y==1.0)
        return x;

    return x+mult(x,--y);
}

float power(float x,float y)
{
    
    if (y==0.0)
        return 1;
    return x*power(x,--y);
}

