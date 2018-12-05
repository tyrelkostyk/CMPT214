/*****
 * Binary Tree example for Cmpt 214 
 *****/

#ifndef TEST_H
#define TEST_H

/*
 * Testing Functions
 */

/*
  Function to create and print the tree corresponding to the first
  test data set. That data set results in a tree that is optimal and
  balanced.  That tree is
                                   4
                                  / \
                                 2   6
                                / \ / \
                               1  3 5  7
  The tree nodes are printed using the three possible traversal methods:
  pre-order, in-order, and post-order.  Output is sent to standard output.  
 */
void test1();

/*
  Function to create and print the tree corresponding to the second
  test data set. That data set results in a tree that is is non-optimal
  and imbalanced.  That tree is
                                   2
                                  / \
                                 1   6
                                    / \
                                   5   7
                                  / 
                                 4   
  The tree nodes are printed using the three possible traversal methods:
  pre-order, in-order, and post-order.  Output is sent to standard output.  
 */
void test2();

/*
  Function to test the increment, decrement, and lookup functions
  on the tree corresponding to the first
  test data set. That data set results in a tree that is is balanced
  and balanced.  That tree is
                                   4
                                  / \
                                 2   6
                                / \ / \
                               1  3 5  7
 */
void test3();

/*
  Function to test the deleteLeaf and isEmpty functions using the
  non-optimal and imbalanced tree.  That tree is
                                   2
                                  / \
                                 1   6
                                    / \
                                   5   7
                                  / 
                                 4   
 */
void test4();

#endif // TEST_H

