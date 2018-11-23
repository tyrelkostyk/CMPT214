/* 
 * program to determine the size, in bytes, of more standard datatypes
 * used by C/C++
 *
 * Author: Tony Kusalik
 */
#include <stdint.h>
#include <stdio.h>

int main( void ) {
  printf( "sizeof int32_t is %zd\n", /* fill in argument */ );
  printf( "sizeof uint64_t is %zd\n", /* fill in argument */ );
  printf( "sizeof long int is %zd\n", /* fill in argument */ );
  printf( "sizeof long double is %zd\n", /* fill in argument */ );
  printf( "sizeof pointer-to-void is %zd\n", /* fill in argument */ );

  return 0;
}
