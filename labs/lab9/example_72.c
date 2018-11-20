/*
 * pointer to struct
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // for strlen(), strcpy()

#define MAX_BUF_SIZE 255

struct point {
  float x;
  float y;
  char * color; // color has changed from a char (in example_71) to char *
};

// function to fill in the information in a point structure
//  pointed to by ptr_to_point
void get_point( struct point *ptr_to_point ) {
    char cbuf[MAX_BUF_SIZE];
    float f_value;

    puts( "input two coordinates and a color, all separated by spaces" );
/* get first coordinate */
    scanf( "%f", &f_value );
    ptr_to_point->x = f_value;
/* get second coordinate */
    scanf( "%f", &f_value );
    ptr_to_point->y = f_value;
/* get color */
    scanf( "%s", cbuf );   // note: we do not use &cbuf
    ptr_to_point->color = (char *)malloc( strlen( cbuf )+1 );
                           // allocate one extra byte for terminating null
    strcpy( ptr_to_point->color, cbuf );
/* 
 * why can't we just say
     ptr_to_point->color = cbuf;
 *  ???
 */
/* done */
    puts( "thanks\n--" );
}

int main( ){
  struct point *a = NULL;

  a = (struct point *)malloc( sizeof( struct point ) );
  a->color = NULL;
  get_point( a );

  printf( "%s point at (%f,%f)\n", a->color, a->x, a->y );

  return 0;
}
