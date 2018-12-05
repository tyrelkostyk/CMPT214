//
// Q1 for Lab 11
//

// Program inspired by  a sample of code from 
// "A Book on C", 4th Ed. by Al Kelley and Ira Pohl

#include <stdio.h>      // for printf(), fprintf()
#include <stdlib.h>     // for EXIT_SUCCESS, EXIT_FAILURE

#define NUM_GROCERIES 3

// something of type color_t is red, white, blue, green, orange, or yellow
typedef enum { red, white, blue, green, orange, yellow } color_t;

// something of type grocery_t is a flower, fruit, or vegetable
typedef enum /* replace this comment with the rest of the definition of grocery_t */

// declare structures flower_s, fruit_s, and vegetable_s.
// Each starts with an enum grocery_t.  The next field in
// each structure is a pointer to a string, the name of the
// grocery item.  The remainder of the structure is grocery_t-dependent.
// It is either a color (of type color_t), an int, or a float.
struct flower_s {
   grocery_t type;
   char *    name;
   color_t   color;
};

struct fruit_s {
   grocery_t type;
   char *    name;
   int       calories;
};

struct vegetable_s {
   grocery_t type;
   char *    name;
   float     cooking_time; // in minutes
};

// "ffv" stands for "flower, fruit, or vegetable".
// An ffv is a union of a grocery_t, a flower_s struct, a fruit_s
// struct, or a vegetable_s struct.
union ffv {
  grocery_t          grt;
  struct flower_s    flr;
  struct fruit_s     frt;
  struct vegetable_s veg;
};

// main program entry point
int main( ) {
    union ffv groceries[NUM_GROCERIES];         // our groceries
    union ffv * grocery_pt;                     // pointer to an ffv
    int i;

    // define each grocery item in our vector of groceries
    groceries[0].flr.type = flower;
    groceries[0].flr.name = "marigold";
    groceries[0].flr.color = yellow;

    groceries[1].frt.type = fruit;
    groceries[1].frt.name = "tomato";
    groceries[1].frt.calories = 22;

    groceries[2].veg.type = vegetable;
    groceries[2].veg.name = "brocolli";
    groceries[2].veg.cooking_time = 2.5;

    // In real programs use either array indexing or pointers for accessing
    // an array within a loop, and do NOT mix both methods.  It is being
    // done in this program only to illustrate both methods of access
    // in a short portion of code.
    grocery_pt = &(groceries[0]);       // get pointer to our array of unions

    // examine each grocery item in our vector of groceries,
    // outputting information appropriate to its grocery_t value
    for( i=0; i < NUM_GROCERIES; ++i ) {
        switch( groceries[i].grt ) {
        case flower:
            printf( "a %s is a flower\n", grocery_pt->flr.name );
            /* replace with the most appropriate, correct statement */
        case fruit:
            printf( "a standard %s has %d calories\n", 
                     groceries[i].frt.name,
/* replace with expression that is the calories member of the frt interpretation of groceries[i] */
                  );
            break;
        case vegetable:
            printf( "don't cook your %s more than %.2f minutes\n",
                     grocery_pt->veg.name, 
/* replace with expression that is the cooking_time member of the veg interpretation of the union pointed to by groceries_pt */
                  );
            break;
        // we should never get to this point.  But just in case we do ...
        default:
            fprintf( stderr, "something's rotten in the grocery bag!\n" );
            return EXIT_FAILURE;
        }
    // advance to the next grocery item
    ++grocery_pt;
    }

    // all done
    return EXIT_SUCCESS;
}

    
