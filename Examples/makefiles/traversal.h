/*****
 * Binary Tree example for Cmpt 214 
 *****/

#ifndef TRAVERSAL_H
#define TRAVERSAL_H

/*
 * Header files
 */

// local headers
#include "tree.h"	// for TreePtr, Value

/*
 * Type definitions
 */

// Order is a possible traversal order.  Values correspond to
// pre-order (PREORDER), in-order (INORDER), or post-order (POSTORDER)
typedef enum { PREORDER, INORDER, POSTORDER } Order;
// example usage:
//   switch( o ) {
//     case PREORDER:  ..., break;
//     case INORDER:   ..., break;
//     case POSTORDER: ..., break;
//     default: abort(); break;

/*
 * Prototypes of functions for traversing trees
 */

/* 
  Function to print a value of type Value on standard output.  The value
  is pointed to by vp.
 */
void printValue(Value *vp);

/* 
  Function to increment the value of a variable of type Value, where that
  value is point to by vp.
 */
void incrementValue(Value *vp);

/* 
  Function to decrement the value of a variable of type Value, where that
  value is point to by vp.
 */
void decrementValue(Value *vp);

/* 
 Apply a function (f) to all values in a tree pointed to by t,
 traversing the tree in Order o
 */
void executeTree( TreePtr t, Order o, void f(Value*) );

#endif // TRAVERSAL_H
