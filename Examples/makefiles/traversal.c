/*****
 * Binary Tree example for Cmpt 214 
 *****/

/*
 * Header files
 */

// standard headers
#include <stdio.h>	// for fprintf()
#include <stdlib.h>	// for abort()

// local headers
#include "tree.h"	// for TreePtr, Value
#include "traversal.h"	// for Order

/*
 * Functions for traversing trees
 */

void printValue(Value *vp)
{
    printf( "%d ", *vp );
}

void incrementValue(Value *vp)
{
    *vp += 1;
}

void decrementValue(Value *vp)
{
    *vp -= 1;
}

void executeTree( TreePtr t, Order o, void f(Value*) )
{
    // For an empty tree there is nothing to do
    if( isEmpty( t ) )
	return;

    // handle the tree 
    // The order in which current node, left branch, right branch are handled
    // is dependent on o.  The expression &(t->data) evaluates to the address
    // of the data member of the tnode struct pointed to by t.
    switch (o) {
	case PREORDER:
	    f( &(t->data) );
	    executeTree( t->left, o, f );
	    executeTree( t->right, o, f );
	    break;
	case INORDER:
	    executeTree( t->left, o, f );
	    f( &(t->data) );
	    executeTree( t->right, o, f );
	    break;
	case POSTORDER:
	    executeTree( t->left, o, f );
	    executeTree( t->right, o, f );
	    f( &(t->data) );
	    break;
	default:
	    fprintf(stderr, "Unknown order!\n");
	    abort();
	    break;
    }
    return;
}
