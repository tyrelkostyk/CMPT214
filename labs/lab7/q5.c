/*
 * Program for Question 5 of Lab 7, Cmpt 214
 */
#include <stdio.h>                     // for puts()
#include <stdlib.h>                    // for EXIT_SUCCESS
#include <string.h>                    // for strcpy()

#define BUFSIZE 100

int main() {
    char* mystr;                       // destination string

    strcpy( mystr, "Hello, World!" );  // copy source string to destination
    puts( mystr );                     // output destination string

    return( EXIT_SUCCESS );
}