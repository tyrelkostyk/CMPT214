/*
    Use the sizeof operator to show the size of various
    C/C++ datatypes
*/
#include <stdio.h>

// sizeof() is used to obtain the size of a datatype.  It returns a
//  value of type size_t.  According the man page for printf(3), the
//  appropriate format specifier for data of type size_t is zd
int main()
{
  printf("char:     %zd bytes\n", sizeof(char));
  printf("short:    %zd bytes\n", sizeof(short));
  printf("int:      %zd bytes\n", sizeof(int));
  printf("unsigned: %zd bytes\n", sizeof(unsigned));
  printf("float:    %zd bytes\n", sizeof(float));
  printf("double:   %zd bytes\n", sizeof(double));

  return 0;
}
