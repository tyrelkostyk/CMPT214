/*
 * Program for Q5 of Lab 9 of Cmpt214
 *  originally written by Erik Frederiksen, esf791
 *
 * This program performs a mysterious calculation on 5x5 matrices.
 */

#include <assert.h>     // for assert()
#include <stdio.h>      // for fprintf(), fgets(), printf()
#include <stdlib.h>     // for atof(), NULL, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>     // for strstr(), 

/* NUM_ROWS must equal NUM_COLS */
#define NUM_ROWS 5
#define NUM_COLS 5

#define LINE_LEN 128

enum matrix_indicator { FILL_A, FILL_B };       // which matrix is being filled

/* function to print 2D matrix pointed to by m */
void print( float m[NUM_ROWS][NUM_COLS] );      // function prototype only;
                                                // actual function defined
                                                // later on

int main( ) {
        int r, c, num_elem;
        int i, j, k;
        float accum;
        float* a_p;
        float* b_p;

        enum matrix_indicator fill_first = FILL_A;
                                                // start filling matrix a first
        float a[NUM_ROWS][NUM_COLS];
        float b[NUM_ROWS][NUM_COLS];
        float first_result[NUM_ROWS][NUM_COLS];
        float second_result[NUM_ROWS][NUM_COLS];
        
        char* line_ptr;
        char line_buf[LINE_LEN];

        /* enforce that the matrix is square */
        assert( NUM_ROWS == NUM_COLS );

        /* read in the data from stdin */
        // for each row
        for ( r=0; r < NUM_ROWS; ++r ) {
                // get one line of input
                if ( fgets( line_buf, LINE_LEN, stdin ) == NULL ) {
                        fprintf( stderr, "Early EOF!\n" );
                        return EXIT_FAILURE;
                }

                line_ptr = line_buf; 
                // for each column
                for ( c=0; c < NUM_COLS; ++c ) {
                        // Get the next value.  It goes in the [r][c] position.
                        // If fill_first is FILL_A, the value goes in a[r][c]
                        // else put it in b[r][c]
                        if ( fill_first == FILL_A ) {
                                a[r][c] = atof( line_ptr );
                        }
                        else {
                                b[r][c] = atof( line_ptr );
                        }
                        // Advance to the next value in the buffer
                        line_ptr = strstr( line_ptr+1, " " );
                        // When we reach the null byte at the end of the 
                        // buffer, we are done
                        if ( line_ptr == NULL ) {
                                break;
                        }
                }
                // If we have read NUM_ROWS rows and we were filling matrix
                //  a, reset so that we are now going to fill b with 
                //  NUM_ROWS rows of values.
                if ( (r == NUM_ROWS - 1) && (fill_first == FILL_A) ) {
                        fill_first = FILL_B;
                        r = -1; // at the end of the loop, r will be incremented
                                // to 0, so we will start filling row 0 of
                }               // matrix b
        }

        /* Calculation performed using the first method. */
        num_elem = NUM_COLS;    // set the number of elements.  Since
                                // NUM_ROWS==NUM_COLS, this could be set to
                                // either NUM_ROWS or NUM_COLS
        for ( i=0; i < NUM_ROWS; ++i ) {
                for ( j=0; j < NUM_COLS; ++j ) {
                        a_p = &(a[i][0]);
                        b_p = &(b[0][j]);
                        accum = 0;
                        // recall num_elem == NUM_ROWS == NUM_COLS
                        for ( k=0; k < num_elem; ++k ) {
                                accum += (*a_p) * (*b_p);
                                a_p++;
                                b_p += NUM_COLS;
                        }
                        first_result[i][j] = accum;
                }
        }
        
        /* Calculation performed using the second method. */

        for ( i=0; i < NUM_ROWS; ++i ) {
                for ( j=0; j < NUM_COLS; j++ ) {
                        accum = 0;
                        // recall num_elem == NUM_ROWS == NUM_COLS
                        for ( k=0; k < num_elem; k++ ) {
                                accum += // complete the rest of this statement 
                        }
                        second_result[i][j] = accum;
                }
        }
        
        /* output input data and results */

        printf( "a:\n" );
        print( a );
        printf( "\n" );
        printf( "b:\n" );
        print( b );
        printf( "\n" );
        printf( "Result using first method:\n" );
        print( first_result );
        printf( "\n" );
        printf( "Result using second method:\n" );
        print( second_result );
        printf( "\n" );
        
        return EXIT_SUCCESS;
}

/* 
 *function to print 2D matrix of NUM_ROWS rows and NUM_COLS columns
 * where the matrix is pointed to by m
 */
void print( float m[NUM_ROWS][NUM_COLS] ) {
        int r, c;

        for ( r=0; r < NUM_ROWS; ++r ) {
                for ( c=0; c < NUM_COLS; ++c ) {
                        printf( "%.2f ", m[r][c] );
                }
                printf( "\n" );
        }
}
