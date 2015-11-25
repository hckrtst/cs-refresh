/**
 * Simple Binary trees
 *
 * *** WIP ***
 * Supports commands:
 * - ins <num>
 * - rem <num>
 * - find <num> --> returns true or false to output
 * - count leaf --> returns num leaves
 * - count branch --> returns num branches
 * - show --> draws the tree
 **/


#include<stdio.h>
#include<stdlib.h>

#include "mpc.h"
#include "linenoise.h"
#include <string.h>

/* definitions */
typedef struct node_t {
    void *data;
    struct node *left, *right;
}node_t;

typedef struct tree_t {
    node_t *root;
    node_t *left, *right;
}tree_t;

/* local vars */
static tree_t *tree; 

/* local functions */
// TODO use macros to generate a generic insert function
static int insert(void * data) {
}

static void print_tree(tree_t* t) {
    
}


/* global functions */
int main(int argc, char **argv) {
    int a = 10;

    // don't initialize left on purpose
    node test1 = {.data = &a, .right = NULL};

    printf(" test1 data = %d, left = %p right = %p \n", *((int*)test1.data), test1.left, test1.right);

    node *ptest2 = (node*)malloc(sizeof(node));

    // we must inialize data to print or causes seg fault when deref 
    ptest2->data = (void*) &a;
    ptest2->left = &test1;
    
    printf(" ptest2 data = %d, left = %p right = %p \n", *((int*)ptest2->data), ptest2->left, ptest2->right);

    free(ptest2);
    
    return 0;
}
