/*
  program for Question 1 of Lab 07
 */

#include <stdio.h>

int i = 0;

void function( int i ) {
    i = 3;                      // A //                   
}

int main() {
    int sum;

    for ( int i=0; i<7; ++i ) 
    {
        sum += i;               // B //
    }
    printf("%d\n", i);          // C //
    function(i);
    printf("%d\n", i);
}
