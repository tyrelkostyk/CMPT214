/***
CMPT214 Assignment 3
Nov 21 2018
Tyrel Kostyk
tck290
11216033
***/

/****** INCLUDED LIBRARIES ******/
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


/****** DATATYPES & CONSTANTS ******/

typedef enum boolean {FALSE=0, TRUE=1} bool;

typedef struct time_spec_fields {
  uint8_t n1;
  uint8_t n2;
  uint8_t n3;
  uint8_t n4;
  uint8_t n5;
  uint8_t n6;
} time_spec_t;

typedef uint32_t num_seconds_t;


/****** FUNCTION STUBS ******/

bool is_legal_time_spec( char *time_spec_str );
bool is_legal_seconds( char *seconds_str );
num_seconds_t string_to_seconds( char *str );
time_spec_t *string_to_time_spec( char *time_spec_str );
time_spec_t *seconds_to_time_spec( num_seconds_t seconds_in);
num_seconds_t time_spec_to_seconds( time_spec_t *time_spec );
void print_time_spec( time_spec_t *time_spec );
bool get_time_arg( char *in_str, num_seconds_t *seconds_p );
void usage(void);

/****** MAIN PROGRAM FUNCTIONS ******/

void usage(void) {
  puts( "Usage: time_calc help" );
  puts( " time_calc conv <time>" );
  puts( " time_calc {add,subt,comp} <time1> <time2>" );
}


bool overflowed(char *str, num_seconds_t val) {
  /* Returns TRUE if overflow; FALSE otherwise
     Used for checking on both seconds & time_specs */
  char *new_str = (char *)malloc( sizeof(char) * strlen(str) );

  // ignore leading spaces, then zeros, as they are accepted
  while (isspace( *str )) {
    str++;
  }
  while ( (*str == '0') && (strlen(str) > 1) ) {
    str++;
  }

  sprintf(new_str, "%u", val);
  int str_cmp = strcmp(new_str, str);  // compare original & new string
  if (str_cmp != 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}


bool is_legal_seconds( char *seconds_str ) {
  /* Returns TRUE if input str is valid seconds. FALSE otherwise  */
  // ignore leading spaces, then zeros, as they are accepted
  while (isspace( *seconds_str )) {
    seconds_str++;
  }
  while ( (*seconds_str == '0') && (strlen(seconds_str) > 1) ) {
    // this allows a single "0" input
    seconds_str++;
  }

  // check seconds using strspn to ensure all chars are numerical digits
  // then compare to actual length of input string (if diff: illegal seconds)
  int input_dig_len = strspn(seconds_str, "0123456789");
  int input_len = strlen(seconds_str);

  if ((input_dig_len != input_len) || (input_len == 0)) {
    fprintf(stderr, "Illegal values in seconds input\n");
    return FALSE;
  } else if ( (seconds_str == '\0') || (seconds_str == NULL) ) {
  // check for null char or NULL str
    return FALSE;
  }

  num_seconds_t sec = atol(seconds_str);  // type cast char to int

  if (sec >= 3155760000) {
  // check if over legal limit
    fprintf(stderr, "Error: Over Maximum Legal Seconds Value\n");
    return FALSE;
  } else if ( overflowed(seconds_str, sec) ) {
  // check for overflow
    fprintf(stderr, "Error: Overflow Condition; illegal number of seconds\n");
    return FALSE;
  } else {
  // passed all cases
    return TRUE;
  }
}


bool is_legal_time_spec( char *time_spec_str ) {
  /* Returns TRUE if given valid time_spec; FALSE otherwise */
  unsigned int years, months, days, hours, minutes, seconds;
  char *s_char = (char *)malloc( sizeof(char) * strlen(time_spec_str) );
  char *trailing = (char *)malloc( sizeof(char) * strlen(time_spec_str) );
  int vals_read = sscanf(time_spec_str, " %uy %un %ud %uh %um %u%c %s",
         &years,&months,&days,&hours,&minutes,&seconds, s_char, trailing);

  // this checks for incorrect formatting (7 vals will be read if correct)
  if (vals_read != 7) {
    fprintf(stderr,"Error: Incorrect time_spec (%d values read)\n", vals_read);
    return FALSE;
  }

  // check for valid time_spec bounds
  if ( (years > 99) || (months > 11) || (days > 30)
        || (hours > 59) || (minutes > 59) || (seconds > 59) ) {
    fprintf(stderr, "Error: Improper time_spec bounds given.\n");
    return FALSE;
  }

  return TRUE;
}


time_spec_t *string_to_time_spec( char *time_spec_str ) {
  /* Returns a time_spec struct; assumes valid time_spec string */
  time_spec_t *time_spec = (time_spec_t *)malloc(sizeof(time_spec_t));

  // extract time_spec values from string
  unsigned int years, months, days, hours, minutes, seconds;
  char *s_char = (char *)malloc( sizeof(char) * strlen(time_spec_str) );
  char *trailing = (char *)malloc( sizeof(char) * strlen(time_spec_str) );
  sscanf(time_spec_str, " %uy %un %ud %uh %um %u%c %s",
         &years,&months,&days,&hours,&minutes,&seconds, s_char, trailing);

 time_spec->n1 = years;
 time_spec->n2 = months;
 time_spec->n3 = days;
 time_spec->n4 = hours;
 time_spec->n5 = minutes;
 time_spec->n6 = seconds;

 return time_spec;
}


num_seconds_t time_spec_to_seconds( time_spec_t *time_spec ) {
  /* Returns seconds equal to time_spec representation.
     Assumes valid time_spec given */
  num_seconds_t seconds_tot = 0;
  uint8_t years, months, days, hours, minutes, seconds;

  years = time_spec->n1;
  months = time_spec->n2;
  days = time_spec->n3;
  hours = time_spec->n4;
  minutes = time_spec->n5;
  seconds = time_spec->n6;

  seconds_tot += (years*31557600);
  seconds_tot += (months*2629800);
  seconds_tot += (days*86400);
  seconds_tot += (hours*3600);
  seconds_tot += (minutes*60);
  seconds_tot += (seconds);

  return seconds_tot;
}


time_spec_t *seconds_to_time_spec( num_seconds_t seconds_in ) {
  /* Convert legal seconds val to time_spec, return time_spec struct */
  time_spec_t *time_spec = (time_spec_t *)malloc(sizeof(time_spec_t));

  unsigned int remain_sec = seconds_in;
  uint8_t years = remain_sec / 31557600;
  remain_sec = remain_sec % 31557600;
  uint8_t months =  remain_sec / 2629800;
  remain_sec = remain_sec % 2629800;
  uint8_t days = remain_sec / 86400;
  remain_sec = remain_sec % 86400;
  uint8_t hours = remain_sec / 3600;
  remain_sec = remain_sec % 3600;
  uint8_t minutes = remain_sec / 60;
  remain_sec = remain_sec % 60;
  uint8_t seconds = (uint8_t)remain_sec;

  time_spec->n1 = years;
  time_spec->n2 = months;
  time_spec->n3 = days;
  time_spec->n4 = hours;
  time_spec->n5 = minutes;
  time_spec->n6 = seconds;

  return time_spec;
}


num_seconds_t string_to_seconds( char *str_sec ) {
  /* Return num_seconds_t specified by string. Assume legal seconds */
  num_seconds_t sec = (num_seconds_t)atol(str_sec);
  return sec;
}


void print_time_spec( time_spec_t *time_spec ) {
  uint8_t years = time_spec->n1;
  uint8_t months = time_spec->n2;
  uint8_t days = time_spec->n3;
  uint8_t hours = time_spec->n4;
  uint8_t minutes = time_spec->n5;
  uint8_t seconds = time_spec->n6;

  printf("%dy %dn %dd %dh %dm %ds\n", years,months,days,hours,minutes,seconds);
}


bool get_time_arg( char *in_str, num_seconds_t *seconds_p ) {
  /* Return TRUE if input string can be successfully interpreted as legal
     seconds, FALSE otherwise. If TRUE, puts num_seconds_t into the location
     pointed to by seconds_p. */

  if (is_legal_seconds(in_str)) {
    // get seconds from valid str input
    *seconds_p = string_to_seconds( in_str );

    return TRUE;

  } else if (is_legal_time_spec(in_str)) {
    // generate time_spec struct from valid string input
    time_spec_t *time_spec_in = string_to_time_spec( in_str );
    // convert the time_spec struct to seconds
    *seconds_p = time_spec_to_seconds( time_spec_in );

    return TRUE;

  } else {
    fprintf(stderr, "Error: Unable to get_time_arg - Incorrect Input!\n");
    return FALSE;
  }
}



/********* MAIN *********/

int main (int argc, char *argv[]) {

  // Start with initial error checking
  if ( (argc < 3) && ( strcmp(argv[1], "help") != 0 ) ) {
  // not a valid program call
    fprintf(stderr, "Error: time_calc requires at least two func arguments.\n");
    usage();
  } else if ( strcmp(argv[1], "help") == 0 ) {
    usage();
  } else if ( (argc == 3) && (strcmp(argv[1], "conv")) ) {
  // 3 args, and no conv arg
    fprintf(stderr, "Error: 2 func args, no conv arg given.\n");
    usage();
  } else if ( (argc == 3) && (strcmp(argv[1], "conv") == 0) ) {
  // 3 args, including conv. (good to attempt conversion)
    if (is_legal_seconds( argv[2] )) {
      // get seconds from valid str input
      num_seconds_t in_seconds = string_to_seconds( argv[2] );

      // create new time spec from valid seconds input
      time_spec_t *new_time_spec = seconds_to_time_spec( in_seconds );

      // print new time spec to stdout
      print_time_spec(new_time_spec);

    } else if (is_legal_time_spec( argv[2] )) {
      // generate time_spec struct from valid string input
      time_spec_t *time_spec_in = string_to_time_spec( argv[2] );

      // convert the time_spec struct to seconds
      num_seconds_t new_seconds = time_spec_to_seconds( time_spec_in );

      // print the converted number value to stdout, if legal
      if (new_seconds < 3155760000) {
        printf("%u\n", new_seconds);
      } else {
        fprintf(stderr, "Error: time_spec yields illegal amount of seconds\n");
      }

    } else {
      fprintf(stderr, "Error: Incorrect conv Input!\n");
    }

  } else if ( (argc == 4)
  // 4 args, no add/subt/comp arg
        && (strcmp(argv[1], "add") != 0  )
        && (strcmp(argv[1], "subt") != 0 )
        && (strcmp(argv[1], "comp") != 0  ) ) {
    fprintf(stderr, "Error: 3 func args, but no add/subt/comp args.\n");
    usage();
  } else if ( (argc == 4)
  // 4 args, has add/subt/comp arg
        && ((strcmp(argv[1], "add") == 0 )
        || (strcmp(argv[1], "subt") == 0 )
        || (strcmp(argv[1], "comp") == 0  )) ) {

    // create pointer to num_seconds_t variable
    num_seconds_t *time1s_p = (num_seconds_t *)malloc(sizeof(num_seconds_t));
    num_seconds_t *time2s_p = (num_seconds_t *)malloc(sizeof(num_seconds_t));

    // Test & grab both input values in seconds, to either add or subt or cmp
    bool time1_valid = get_time_arg( argv[2], time1s_p );
    bool time2_valid = get_time_arg( argv[3], time2s_p );

    if ( !((time1_valid) && (time2_valid)) ) {
    // check for validity of both time inputs
      fprintf(stderr, "Error: Invalid time inputs on %s function.\n", argv[1]);
    } else if (strcmp(argv[1], "add") == 0) {
    // add times
      num_seconds_t *add_result=(num_seconds_t *)malloc(sizeof(num_seconds_t));

      // check for possible positive int overflow
      if (*time1s_p < 3155760000 - *time2s_p) {
        // calculate & print correct result!
        *add_result = *time1s_p + *time2s_p;

        time_spec_t *result = (time_spec_t *)malloc(sizeof(time_spec_t));
        result = seconds_to_time_spec( *add_result );

        print_time_spec(result);

      } else {
        fprintf(stderr,"Error: add operation failed. Result too big! :o\n");
      }

    } else if (strcmp(argv[1], "subt") == 0) {
    // subtract times
      if (*time1s_p < *time2s_p) {
        fprintf(stderr, "Error: subt operation failed, Result is Negative.\n");
      } else {
        num_seconds_t *subt_result=(num_seconds_t *)malloc(sizeof(num_seconds_t));
        *subt_result = *time1s_p - *time2s_p;

        time_spec_t *result = (time_spec_t *)malloc(sizeof(time_spec_t));
        result = seconds_to_time_spec( *subt_result );

        print_time_spec(result);
      }

    } else if (strcmp(argv[1], "comp") == 0) {
    // compare times
      if (*time1s_p > *time2s_p) {
        printf("greater\n");
      } else if (*time1s_p < *time2s_p) {
        printf("less\n");
      } else {
        printf("equal\n");
      }
    }

  } else {
    fprintf(stderr, "Error: time_calc requires no more than 4 arguments.\n");
    usage();
  }
}
