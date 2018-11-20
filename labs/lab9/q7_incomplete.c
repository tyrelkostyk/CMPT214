/*
 * A program for Q7 of Lab 9 that
 * illustrates arrays of dynamically-allocated structures.
 * It is an extension of example_73.c from class. 
 */
#include <err.h>        // for err()
#include <stdio.h>      // for printf()
#include <stdlib.h>     // for EXIT_FAILURE, NULL
#include <string.h>     // for strlen(), strcpy()

// declare type string to be the same as type char *
typedef // replace this comment with the rest of the declaration

// declare a struct that has a tag "point"
struct point {
  float x;
  float y;
  string color;
} ;

#define MAX_POINTS 100

// Dynamically allocate a new point structure and save the information
// in the formal arguments x, y, and color into the corresponding fields
// of the new point structure.  On success return a pointer to the structure.
// On allocation error, cause program exit with failure.
struct point * create_point( float x, float y, string color ) {
    struct point * new_point;
    int color_len;

    new_point = (struct point *)malloc( sizeof( struct point) );
    if( new_point == NULL )
        err( EXIT_FAILURE, "allocating new point" );
    if( color == NULL )
        new_point->color = NULL;
    else {
        color_len = strlen( color );
        new_point->color = (string)malloc( color_len + 1 );
        if( new_point->color == NULL )
            err( EXIT_FAILURE, "allocating space for color" );
        strcpy( new_point->color, color );
    }
    new_point->x = x;
    new_point->y = y;

    return new_point;
}
   
int main( ) {
  // define a table of MAX_POINTS pointers to point structures
  struct point *pointTab[MAX_POINTS];
  // variable point_p is a pointer to the elements of pointTab
  // replace this comment with the definition of point_p of correct type
  int i;

  // initialize the first 4 items in table pointTab
  pointTab[0] = create_point( -1, 4, "green" );
  pointTab[1] = create_point(  34.5, 0.4, "red" );
  pointTab[2] = create_point(  1.003, -4, "pink" );
  pointTab[3] = create_point( 0, 0, NULL );

  // Print the colors of the points stored in structures pointed
  // to by pointTab.  Access pointTab like an array.
  for( i=0; (i<MAX_POINTS) && (pointTab[i]->color != NULL); ++i)
     printf( "point color is %s\n", pointTab[i]->color );

  putchar( '\n' );

  // Print the colors of the points stored in structures pointed
  // to by pointTab.  Access pointTab using pointers and autoincrement.  
  // First step: Set up point_p to point to the beginning of pointTab.
  point_p = pointTab;

  // While we haven't encountered a pointed-to structure with a color (pointer)
  // value of NULL ...
  while( (*point_p)->color != NULL ) {
     // print the color of the point
     printf( "point color is %s\n", // replace this comment with a correct expression );
     // advance point_p to to next pointer in pointTab
     ++point_p;
  }

  return EXIT_SUCCESS;
}
