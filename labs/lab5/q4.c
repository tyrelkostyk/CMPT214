/*
 * Program for Q4 of Lab 5 in Cmpt 214
 */
#include <stdio.h>

int main() {
  unsigned int i = 34567;
  unsigned int ci;
  float x;

  ci = ~i;
  // print the bitwise complement in hexadecimal and octal
  printf( "The one's complement of %d is %#x or %#o\n", i, ci );

  x  = 3.14 + 7.23;
  printf( "x = %f\n", x );

  return 0;
}
