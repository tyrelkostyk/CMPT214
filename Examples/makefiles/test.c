/*****
 * Binary Tree example for Cmpt 214 
 *****/

/*
 * Header files
 */

// standard headers
#include <stdio.h>	// for printf(), fprintf()

// local headers
#include "tree.h"	// for TreePtr, Value
#include "traversal.h"	// for Order
#include "test.h"

/*
 * Global, static data only know to functions in this file
 */

// Test data
static Value data1[] = {4, 2, 6, 1, 3, 5, 7};
static Value data2[] = {2, 6, 1, 5, 7, 4};

/*
 * Testing Functions
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
