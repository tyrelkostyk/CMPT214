/*
 * compare with example_67
 */
#include <stdio.h>	// for fprintf(), printf(), putchar()
#include <stdlib.h>	// for NULL, calloc()

#define NUM_ROWS 4
#define NUM_COLS 6
#define DYNAMIC		// include "DYNAMIC" code in the rest of the file

int main( void ){
  int i, j;

  // set up 2D storage in variable d
#ifdef CONTIGUOUS
  int d[NUM_ROWS][NUM_COLS];
  printf( "using contiguously allocated array for d\n" );
#else // not CONTIGUOUS
  int **d=NULL;
#endif // CONTIGUOUS
#ifdef DYNAMIC
  printf( "using a vector of pointers to vectors array for d\n" );  
  d=(int **)calloc( NUM_ROWS, sizeof( int * ) );
  for( i=0; i<NUM_ROWS; ++i )
    d[i]=calloc( NUM_COLS, sizeof( int ) );
#endif // DYNAMIC

  // initialize values in d
  for( i=0; i<NUM_ROWS; i++ ) {
    for( j=0; j<NUM_COLS; j++ ) {
      d[i][j] = 10*i+j;
    }
  }

  // print values in d
  for( i=0; i<NUM_ROWS; i++ ) {
    for( j=0; j<NUM_COLS; j++ ) {
      printf( "d[%d][%d]=%02d ", i, j, d[i][j] );
    }
    putchar( '\n' );
  }

  return 0;
}
