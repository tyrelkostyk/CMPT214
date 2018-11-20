/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>


/* DATATYPE DEFS */

// create 'bool' unsigned char enum datatype, enum named boolean
typedef enum boolean {FALSE='0', TRUE='1'} bool;

typedef struct time_spec_fields {
  uint8_t n1;
  uint8_t n2;
  uint8_t n3;
  uint8_t n4;
  uint8_t n5;
  uint8_t n6;
} time_spec_t;

typedef uint32_t num_seconds_t;


/* SUPPORTING FUNCTION STUBS */

bool is_legal_time_spec( char * );
bool is_legal_seconds( char *seconds );
num_seconds_t string_to_seconds( char * );
time_spec_t *string_to_time_spec( char * );
time_spec_t *seconds_to_time_spec( char * );
num_seconds_t time_spec_to_seconds( time_spec_t *time_spec );
  // time_spec->n1; // how to grab n1 from time_spec_t pointer, time_spec
                 // ^ equivalent to time_spec.n1, if it weren't a pointer
void print_time_spec( time_spec_t *time_spec );
bool get_time_arg( char *in_str, num_seconds_t *seconds_p );


/* MAIN PROGRAM */

bool is_legal_seconds( char *seconds ) {
  int sec = atol(seconds);  // type cast char to int
  if ( (sec >= 0) && (sec < 3155760000) ) {
    return TRUE;
  } else {
    return FALSE;
  }
}


int main (int argc, char *argv[]) {

  // Start with initial error checking
  if (argc < 3) {
  // not a valid program call
    printf("Error: time_calc requires at least two arguments. See help for more info.\n");
  } else if ( (argc == 3) && (strcmp(argv[1], "conv")) ) {
  // 3 args, no conv arg. Improper conv call, or missing args for add/subt/cmp call
    printf("Error: Improper conv call, or missing add/subt/cmp args.\n");
  } else if ( (argc == 4) && ( (strcmp(argv[2], "add")) || (strcmp(argv[1], "subt")) || (strcmp(argv[1], "cmp")) ) ) {
  // 4 args, missing add/subt/cmp arg. Improper add/subt/cmp call, or too many conv args
    printf("Error: Improper add/subt/cmp call, or too many conv args.\n");

  } else if ( (argc == 3) && (strcmp(argv[1], "conv") == 0) ) {
  // 3 args, including conv. (good)
    bool check = is_legal_seconds( argv[2] );

    if (check) {
      printf("Correct");
    } else {
      printf("Incorrect");
    }

  }
}
