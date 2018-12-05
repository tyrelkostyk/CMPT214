/*****
 * Binary Tree example for Cmpt 214 
 *****/

/*
 * Type definitions
 */

// standard headers
#include <stdio.h>	// for fprintf()
#include <stdlib.h>	// for NULL, malloc(), abort(), free()

// local headers
#include "tree.h"	// for TreePtr, TreeNode, Value, TRUE, FALSE

/*
 * Basic functions for manipulating trees
 */

TreePtr newTree()
{
    return NULL;
}

int isEmpty(TreePtr t)
{
    return( NULL == t );
}

TreePtr insertNode(TreePtr t, Value v)
{
    TreePtr new_node;

    // if t is empty, then create a new node that becomes the root of 
    // a new (sub)tree
    if( isEmpty(t) ) {
       // Try to allocate the new tree node
       if( NULL == (new_node = (TreePtr)malloc( sizeof( TreeNode ) )) ) {
	    fprintf( stderr, "out of memory\n" );
            abort();
        }
        new_node->data = v;
        new_node->left = new_node->right = NULL;
        return( new_node );
    }
    // Else the tree is not empty, so insert the value into
    // the appropriate spot in this existing tree and add
    // the new tree as the appropriate branch to tree t
    // If value v is less then current node
    //  add the value to the left subtree
    if (v < t->data)
        t->left = insertNode(t->left, v);
    // If value v is higher then current node ...
    //  add the value to the right subtree 
    if (v > t->data)
        t->right = insertNode(t->right, v);
    // If the value is already in the tree, don't add it again

    // return the (sub)tree rooted at t
    return t;
}

TreePtr deleteLeaf( TreePtr t, Value v )
{
    // can't delete an empty tree
    if( isEmpty( t ) )
        return( t );
    // if we have found the node in the tree storing Value v
   if( t->data == v) {
       // if this is a leaf node we can delete it
       if( (NULL == t->right) && (NULL == t->left) ) {
           free( t );
           t = NULL;
       } // otherwise it's not a leaf node and we can't delete it
       return( t );
    } 
    // else the node with that value must be elsewhere.  Try deleting
    // it on the left branch or the right branch, depending on whether
    // v is less that or greater than, respectively, the value at the
    // current node.  Return the resultant tree.
    if( v < t->data )
        t->left = deleteLeaf( t->left, v );
    else if( v > t->data )
        t->right = deleteLeaf( t->right, v );
    else {
        // there is something wrong; the impossible has happened
            fprintf( stderr, "problem deleting node in tree at %p\n", t );
            abort();
    }
    return( t );
}

int lookupValue(TreePtr t, Value v)
{
    // if t is empty, then v is not present 
    if( isEmpty(t) )
        return( FALSE );
    // else the tree is not empty, so check whether v is in the tree
    // If value v is at the current node, we are done
    if( v == t->data)
        return( TRUE );
    // If value v is less than the current node, v must be in the left
    //  subree if it is in the tree at all
    else if( v < t->data )
        return( lookupValue(t->left, v) );
    // If value v is greater than the current node, v must be in the right
    //  subtree if it is in the tree at all
    else if (v > t->data)
        return( lookupValue(t->right, v) );
    else {
    // there is something wrong; the impossible has happened
        fprintf( stderr, "problem looking up value in tree at %p\n", t );
        abort();
    }
}
