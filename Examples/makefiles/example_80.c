/*****
 * Binary Tree example for Cmpt 214 
 *****/

/*
 * Header files
 */

// standard headers
#include <stdio.h>      // for printf(), fprintf()
#include <stdlib.h>     // for NULL, malloc(), abort(), free()

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
 * Macros
 */

#define TRUE 1  // what C uses for true
#define FALSE 0 // what C uses for false

/*
 * Global, static data
 */

// Test data
Value data1[] = {4, 2, 6, 1, 3, 5, 7};
Value data2[] = {2, 6, 1, 5, 7, 4};

/*
 * Auxiliary Functions
 */

/* 
  Create an empty tree.  Requires no arguments.  Returns a pointer to an
   empty tree.
 */
TreePtr newTree()
{
    return NULL;
}

/* 
  Check whether the tree pointed to by t is empty.  
  Returns true or false as encoded in an int by C.
 */
int isEmpty(TreePtr t)
{
    return( NULL == t );
}

/* 
  Insert a Value v into the tree pointed to by t and return a pointer to the 
  resultant tree.  If v is already in the tree, don't change the tree,
  and return a pointer to the original tree.
  If insertion fails, the program is out of memory and the program
  aborts so a core dump can be generated and a post-mortem performed.
 */
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

/*
  Delete the leaf in the tree pointed to by t where that leaf stores Value
  v.  Free up the memory used by that TreeNode.  If a node with that value
  cannot be found, if the tree is empty, or if the node with that value is not
  a leaf, return the original tree.
 */
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

/* 
  Lookup a Value v in the tree pointed to by t and return an indication
  (true/false) of whether the value was found in the tree.   
  Returns true or false as encoded in an int by C.
 */
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

/* 
  Function to print a value of type Value on standard output.  The value
  is pointed to by vp.
 */
void printValue(Value *vp)
{
    printf( "%d ", *vp );
}

/* 
  Function to increment the value of a variable of type Value, where that
  value is point to by vp.
 */
void incrementValue(Value *vp)
{
    *vp += 1;
}

/* 
  Function to decrement the value of a variable of type Value, where that
  value is point to by vp.
 */
void decrementValue(Value *vp)
{
    *vp -= 1;
}

/* 
 Apply a function (f) to all values in a tree pointed to by t,
 traversing the tree in Order o
 */
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
void test1()
{
    int i, n, *datap;
    TreePtr t;

    // build t
    t = newTree();
    n=(sizeof(data1)/sizeof(Value));
    for (i = 0; i < n; i++)
        t = insertNode(t, data1[i]);

    // print the nodes in t in three different traversal orders
    printf( "optimal tree using preorder, inorder, postorder traversal\n" );
    executeTree(t, PREORDER, printValue);
    printf("\n");
    executeTree(t, INORDER, printValue);
    printf("\n");
    executeTree(t, POSTORDER, printValue);
    printf("\n");

    // Clean up t by removing nodes in the reverse order
    //  to how they were added.  This ordering ensures that
    //  each value will be removed as a leaf.
    printf( "cleanup of optimal tree ..." );
    for( datap=&data1[n-1]; datap >= &data1[0]; --datap )
        t=deleteLeaf( t, *datap );
    // check that the cleanup was successful
    if( isEmpty( t ) )
        printf( ".. successful\n\n" );
    else
        printf( ".. failed\n\n" );
    
    return;
}

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
void test2()
{
    int i, n;
    TreePtr t;

    // build t
    t = newTree();
    n=(sizeof(data2)/sizeof(Value));
    for (i = 0; i < n; i++)
        t = insertNode(t, data2[i]);

    // print the nodes in t in three different traversal orders
    printf( "non-optimal tree using preorder, inorder, postorder traversal\n" );
    executeTree(t, PREORDER, printValue);
    printf("\n");
    executeTree(t, INORDER, printValue);
    printf("\n");
    executeTree(t, POSTORDER, printValue);
    printf("\n");

    // Clean up t by removing nodes in the reverse order
    //  to how they were added.  This ordering ensures that
    //  each value will be removed as a leaf.
    printf( "cleanup of non-optimal tree ..." );
    for( i=n; i > 0; )
        t=deleteLeaf( t, data2[--i] );
    // check that the cleanup was successful
    if( isEmpty( t ) )
        printf( ".. successful\n\n" );
    else
        printf( ".. failed\n\n" );
    
    return;
}

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
void test3()
{
    int i, n, *datap;
    TreePtr t;

    // build t
    t = newTree();
    n=(sizeof(data1)/sizeof(Value));
    for (i = 0; i < n; i++)
        t = insertNode(t, data1[i]);
    printf( "initial optimal tree using inorder traversal\n");
    executeTree( t, INORDER, printValue );
    printf("\n");

    // perform the increment functions
    executeTree( t, PREORDER, incrementValue );
    printf( "optimal tree after preorder increment\n");
    executeTree(t, INORDER, printValue);
    printf("\n");

    // lookup some values in the tree
    if( lookupValue( t, 8 ) ) 
        printf( "value 8 found\n" );
    else
        printf( "value 8 not found\n" );
    if( lookupValue( t, 9 ) ) 
        printf( "value 9 found\n" );
    else
        printf( "value 9 not found\n" );

    // perform decrement functions
    executeTree( t, POSTORDER, decrementValue );
    printf( "optimal tree after postorder decrement\n");
    executeTree(t, INORDER, printValue);
    printf("\n");

    // Clean up t by removing nodes in the reverse order
    //  to how they were added.  This ordering ensures that
    //  each value will be removed as a leaf.
    printf( "cleanup of optimal tree ..." );
    for( datap=&data1[n]; datap > &data1[0]; )
        t=deleteLeaf( t, *--datap );
    // check that the cleanup was successful
    if( isEmpty( t ) )
        printf( ".. successful\n\n" );
    else
        printf( ".. failed\n\n" );
    
    return;
}

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
void test4()
{
    int i, n;
    TreePtr t;

    // build t
    t = newTree();
    n=(sizeof(data2)/sizeof(Value));
    for (i = 0; i < n; i++)
        t = insertNode(t, data2[i]);
    printf( "initial non-optimal tree using inorder traversal\n");
    executeTree(t, INORDER, printValue);
    printf("\n");

    // check whether the tree is empty.  It should not be.
    printf( "isEMPTY " );
    if( isEmpty( t ) )
        printf( "succeeds\n" );
    else
        printf( "fails\n" );

    // try deleting some leaves
    printf( "removing the (non-leaf) node with value 5 results in\n" );
    t=deleteLeaf( t, 5 );
    executeTree(t, INORDER, printValue);
    printf("\n");
    printf( "removing the (leaf) node with value 7 results in\n" );
    t=deleteLeaf( t, 7 );
    executeTree(t, INORDER, printValue);
    printf("\n");

    // Clean up t by removing nodes in the reverse order
    //  to how they were added.  This ordering ensures that
    //  each value will be removed as a leaf.
    printf( "cleanup of non-optimal tree ..." );
    for( i=0; i < n; ++i)
        t=deleteLeaf( t, data2[n-1-i] );
    // check that the cleanup was successful
    if( isEmpty( t ) )
        printf( ".. successful\n\n" );
    else
        printf( ".. failed\n\n" );
    
    return;
}

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
