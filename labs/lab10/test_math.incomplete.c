/*
 * for Lab 10
 */

#include <stdio.h>
#include <stdlib.h>   // for EXIT_FAILURE, EXIT_SUCESS
#include <math.h>

int main( int argc, char *argv[] ) {
    float value;

    if( (argc < 2) ||
        (sscanf( argv[1], "%f", &value ) != 1) ) {
        fprintf( stderr, "usage: %s <floating-point number>\n", argv[0] );
        exit( EXIT_FAILURE );
    }
    printf( "sin(%f) is %f\n", value, /* provide function call */ );
    return EXIT_SUCCESS;
}
