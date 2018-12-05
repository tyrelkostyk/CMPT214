/*****
 * Binary Tree example for Cmpt 214 
 *****/

#ifndef TREE_H
#define TREE_H

/*
 * Type definitions
 */

// A TreeNode consists of data of type Value, 
// a left subtree pointer, and a right subtree
// pointer.  A TreePtr is a pointer to a TreeNode, or equivalently,
// a pointer to a tree rooted at that node.
typedef int Value;
typedef struct tnode *TreePtr;
typedef struct tnode {
    Value   data;
    TreePtr left;
    TreePtr right;
} TreeNode;
// example usage:
//   ... f( ..., TreePtr t, ... ) ...
//   t->data = ...
//   t->left =
//   t->right =
//   TreePtr t = (TreePtr)malloc( sizeof( TreeNode ) ); 

/*
 * Macros
 */

#define TRUE 1	// what C uses for true
#define FALSE 0 // what C uses for false
   
/*
 * Prototypes of basic functions for manipulating trees
 */

/* 
  Create an empty tree.  Requires no arguments.  Returns a pointer to an
   empty tree.
 */
TreePtr newTree();

/* 
  Check whether the tree pointed to by t is empty.  
  Returns true or false as encoded in an int by C.
 */
int isEmpty(TreePtr t);

/* 
  Insert a Value v into the tree pointed to by t and return a pointer to the 
  resultant tree.  If v is already in the tree, don't change the tree,
  and return a pointer to the original tree.
  If insertion fails, the program is out of memory and the program
  aborts so a core dump can be generated and a post-mortem performed.
 */
TreePtr insertNode(TreePtr t, Value v);

/*
  Delete the leaf in the tree pointed to by t where that leaf stores Value
  v.  Free up the memory used by that TreeNode.  If a node with that value
  cannot be found, if the tree is empty, or if the node with that value is not
  a leaf, return the original tree.
 */
TreePtr deleteLeaf( TreePtr t, Value v );

/* 
  Lookup a Value v in the tree pointed to by t and return an indication
  (true/false) of whether the value was found in the tree.   
  Returns true or false as encoded in an int by C.
 */
int lookupValue(TreePtr t, Value v);

#endif // TREE_H
