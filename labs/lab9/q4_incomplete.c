/*
 * Program for Q4 of Lab 9 of Cmpt214
 */
#include <stdio.h>

/* 
 * function to print element [i][j] of an array of type int** 
 * of dimension [num_rows][num_cols].  Address to the start of the
 * contiguous array is provided by argument vec_p.
 */
void print_value( int *vec_p, int num_rows, int num_cols, int i, int j ) {
    int *elem_p;

    if( i >= num_rows ) {
        fprintf( stderr, 
                 "row %d is out-of-bounds in [%d][%d]\n", i, i, j );
        return;
    }
    if( j >= num_cols ) {
        fprintf( stderr,
                 "column %d is out-of-bounds in [%d][%d]\n", j, i, j );
        return;
    }
    // in the next statement, assign to elem_p the address of the element
    //   we are interested in, element [i][j].
    // To do this, use the formula for array access into a contiguously
    //   allocated array shown in class.  The formula will involve i and
    //   Remember that in
    //   arithmetic involving pointers, the compiler automatically
    //   scales by size-of-pointed-to-type.  You cannot use the '&' in
    //   your formula/expression.
    elem_p = // replace this comment with the correct expression 
    printf( "value of element [%d][%d] = %02d\n", i, j, *elem_p );
} 

int main( ){
  int b[5][5] = { {0,1,2,4,5}, {10,11,12,13,14},
                  {20,21,22,23,24}, {30,31,32,33,34},
                  {40,41,42,43,44} };

  int r, c;

  for( r=0; r<5; r++ ) {
      for( c=0; c<5; c++ ) 
          printf( "b[%d][%d] = %02d ", r, c, b[r][c] );
      putchar( '\n' );
  }
  putchar( '\n' );

  print_value( (int *)b, 5, 5, 0, 5 );
  print_value( (int *)b, 5, 5, 5, 0 );
  print_value( (int *)b, 5, 5, 1, 1 );
  print_value( (int *)b, 5, 5, 4, 3 );

  return 0;
}
