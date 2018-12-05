/*****
 * Binary Tree example for Cmpt 214 
 *****/

/*
 * Header files
 */

// local headers
#include "test.h"	// for test1(), test2(), test3(), test4()

/* 
 * Function main()
 */

/*
  Main() does not use command-line arguments.  It simply returns an exit
  status
 */
int main(void)
{

    // test a tree in optimal order
    test1();
    
    /* Test a tree in non-optimal order */
    test2();

    /* Test incrementValue, decrementValue, lookup */
    test3();

    /* Test deleteLeaf and isEmpty */
    test4();

    return 0;
}
