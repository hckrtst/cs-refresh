#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int less_than_equal(node_t *a, node_t *b) {
    return (*(a->payload->data) <= *(b->payload->data))?1:0;
}
        
int main(int argc, char**argv) {
    

    int *d1 = (int*) malloc(sizeof(int));
    *d1 = 10;
    node_t* root = make_tree(d1);

    printf("Created tree with root value of %d\n", *(root->payload->data));
   
    int *d2 = (int*)malloc(sizeof(int));
    *d2 = 200;
    insert_data(root, d2, less_than_equal);
    
    int *d3 = (int*)malloc(sizeof(int));
    *d3 = 9;
    insert_data(root, d3, less_than_equal);

    free(d1);
    free(d2);
    free(d3);

    // TODO destroy nodes

    return 0;
}
