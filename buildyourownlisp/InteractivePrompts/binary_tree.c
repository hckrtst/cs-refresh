#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


int less_than_equal(node_t *a, node_t *b) {
    return (*(a->payload->data) <= *(b->payload->data))?1:0;
}
        
void inorder_traverse_r(const node_t *node) {
    // error case
    if (node == NULL) {
        fprintf(stderr, "Dang it, you gave me a null node!\n");
        return;
    }

    // look on the left
    if (node->left != NULL) {
        inorder_traverse_r(node->left);
    }
    say("I visited node %c:\n", *(node->payload->data));
    if (node->right != NULL) {
        inorder_traverse_r(node->right);
    }
}

/* We need to do post order traversal 
 * for destroy
 */
void destroy_tree(node_t * node) {
   // error case
   if (node == NULL) {
       fprintf(stderr, "Dang it, you gave me a null node!\n");
       return;
   }

    if (node->left != NULL) {
        destroy_tree(node->left);
    }
    if (node->right != NULL) {
        destroy_tree(node->right);
    }

    say("I am destroying node %c:\n", *(node->payload->data));
    free(node->payload->data);
    free((void*) node->payload);
    free(node);
}

int main(int argc, char**argv) {
    

    char c = 'm';
    node_t* root = make_tree(&c);

    printf("Created tree with root value of %c\n", *(root->payload->data));
   
    c = 'a';
    insert_data(root, &c, less_than_equal);
   
    c = 'n';
    insert_data(root, &c, less_than_equal);

    c = 'a';
    insert_data(root, &c, less_than_equal);

    c = 's';
    insert_data(root, &c, less_than_equal);

    c= 'i';
    insert_data(root, &c, less_than_equal);

    inorder_traverse_r(root);

    destroy_tree(root);
    root = NULL; // We need to do this

    inorder_traverse_r(root);

    return 0;
}
