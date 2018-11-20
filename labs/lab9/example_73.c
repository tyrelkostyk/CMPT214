/*
 * arrays of structures
 */
#include <stdio.h>
#include <stdlib.h>

// declare a struct that has a tag "point"
struct point {
  float x;
  float y;
  char * color;
};

int main( ) {
  // define a table of 4 point structures
  // and initialize the items in that table
  struct point pointTab[] = {
    { -1, 4, "green" },
    { 34.5, 0.4, "red" },
    { 1.003, -4, "pink" },
    {0, 0, NULL} };
  struct point *point_p;
  int i, n;

  // determine number of elements. Subtract 1 since last row is null.
  n=(sizeof( pointTab )/sizeof( *pointTab))-1; 
  // note that sizeof(*pointTab) can be evaluated at compile time.
  // sizeof(*pointTab) is the same as sizeof(struct point)
 
  // access pointTab like an array
  for( i=0; i<n; ++i)
     printf( "point color is %s\n", pointTab[i].color );

  putchar( '\n' );

  // access pointTab using pointers and autoincrement
  point_p = pointTab;

  // note the use of both ways of dereferencing the pointer
  // to the structure and accessing a member of the structure
  while( point_p->color != NULL ) {
     printf( "point color is %s\n", (*point_p).color );
     ++point_p;
  }

  return 0;
}
