/* Cmpt 214 Assignment 2 Question 3 */
/* Tyrel Kostyk, 11216033, tck290 */

#include <stdio.h>
#include <string.h>

/* Global variables.  Accessible from all functions. */
int global_count = 0;


/* Function prototypes. */
int strlen_iter( char* string );
int strlen_recursive_return( char* string );
int strlen_recursive_global( char* string, int accum );


/* Main function. */
int main( int argc, char* argv[] ) {

    char *input_string;
    int string_length;

    // if a command-line argument was given, process it
    if( argc > 1 ) {

        input_string = argv[1];
        printf( "input string: '%s'\n", input_string );
        string_length = strlen_iter( input_string );
        printf( "Calculating string length iteratively: %d\n", string_length );
        string_length = strlen_recursive_return( input_string );
        printf( "Calculating string length recursively returning a value: %d\n",
                string_length );
        if( strlen_recursive_global( input_string, 0 ) ) {
                printf( "Calculating string length recursively " );
                printf( "using a global variable: %d\n", global_count );
	}
    }
    // done
    return 0;
}

int strlen_iter( char* string ) {
  int i;
  for (i = 0; string[i] != '\0'; ++i);
  // increment for each char in string; increment before leaving loop to get full length

  return i;
}


int strlen_recursive_return( char* string ) {
  int len = 0;

  if (string[len] != '\0') {
    len = 1 + strlen_recursive_return(string + 1);  // recursive case: no null char
  } else {
    return 1;  // base case: string == '\0' (null char)
  }
  return len;  // return 1 + addition of all other chars
}

int strlen_recursive_global( char* string, int accum ) {

  if (string[0] != '\0') {
    // recursive case: no null char; return after increment string & accum
    return strlen_recursive_global(string+1, accum+1);
  } else {
    // base case: null char. Assign global var, and return 1
    global_count = accum;
    return 1;
  }

  return 0;  // if anything fails
}
