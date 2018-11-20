#include <stdio.h>

/* 
 * function to print element [2][2] of an array of type int** 
 * of dimension [num_rows][num_cols].  Address to the start of the
 * contiguous array is provided by argument vec_p.
 */
void print_value( int *vec_p, int num_rows, int num_cols ) {
    int *elem_p;

    // implement the formula for array access into a contiguously allocated
    //  array to get the address of the
    //  element we are interested in, [2][2]
    elem_p = vec_p + (( 2 * num_cols ) + 2);
    // note that in the above statement, the operations are scaled
    //  by the size of type int so that the addresses work out correctly
    printf( "value of element [2][2] = %02d\n", *elem_p );
    (void)num_rows;   // dummy access to num_rows
} 

int main( ){
  int b[4][3] = { {0,1,2}, {10,11,12},
                  {20,21,22}, {30,31,32} };

  printf( "value of b[2][2] = %02d\n", b[2][2] );
  print_value( (int *)b, 4, 3 );

  return 0;
}
