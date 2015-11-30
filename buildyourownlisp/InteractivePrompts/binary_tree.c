#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "binary_tree.h"

#define TIMEOUT 250

static struct timespec ts = {.tv_sec = 0, .tv_nsec = 100000000};

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
void destroy_tree(node_t** node) {
   // error case
   if (*node == NULL) {
       fprintf(stderr, "Dang it, you gave me a null node!\n");
       return;
   }

    if ((*node)->left != NULL) {
        destroy_tree(&((*node)->left));
    }
    if ((*node)->right != NULL) {
        destroy_tree(&((*node)->right));
    }

    say("I am destroying node %c:\n", *((*node)->payload->data));
    free((*node)->payload->data);
    free((void*) (*node)->payload);
    free(*node);
    *node = NULL;
}

static inline void pause() {
    nanosleep(&ts, NULL);
}

static void check_user_input() {
    int ch = getch();
    if (ch == 27) {
            wclear(stdscr);
            int row, col;
            getmaxyx(stdscr, row, col);
            attron(A_REVERSE);
            mvprintw(row/2, col/2, "Bye now!");
            refresh();
            nanosleep(&ts, NULL);
            endwin();
            exit(0);
    } else if (ch == ERR){
        getch();
    } else{
        // include case that ch == ERR for no input
        // do nothing
     }
}

static void draw_edge(const int row, const int col, int *row_1, int *col_1, int is_right) {
    int delta_row= 1;
    int delta_col = 1;
    *row_1 = row;
    *col_1 = col;

    if (is_right == 0) {
        delta_col=-1;
    }

    pause();
    for(int i =0; i < 8; i++) {
        *row_1+=delta_row;
        *col_1+=delta_col;
        mvaddch(*row_1, *col_1, '*');
        refresh();
    }

    check_user_input();
}

#if 0
static int cnt = 0;
static void dump_node(node_t *node, int row, int col) {
    cnt++;
    mvprintw(30+cnt ,30, "Node %c at %d %d",*(node->payload->data), row, col);
}
#endif

static void draw_subtree(const node_t *root, const int row, const int col) {
    int row_1 = 0, col_1 = 0;

    if (root == NULL) {
        fprintf(stderr, "Bad node\n");
        return;
    }


    // visit node
    mvprintw(row, col, "[%c]", *(root->payload->data));
    //dump_node(root, row , col);
    refresh();
    pause();
    

    // draw the edge and get updated x,y and
    // visit left
    if (root->left != NULL) {
        draw_edge(row, col, &row_1, &col_1, 0);
        draw_subtree(root->left, row_1, col_1);     
    }

    pause();  
    if (root->right != NULL) {
        draw_edge(row, col, &row_1, &col_1, 1);
        draw_subtree(root->right, row_1, col_1);     
    }
    check_user_input();
}


void draw_tree_internal(const node_t *root) {
    int row, col;
    initscr();
    raw();
    timeout(TIMEOUT);
    noecho();
    
    getmaxyx(stdscr, row, col);

    
    draw_subtree(root, row/3, col/3);
    
    pause();
    pause();
    pause();

    wclear(stdscr);

    endwin();


}

node_t *build_tree(const int c, const char s[]) {
    node_t* root = make_tree(&s[0]);
    for(int i=1; i < c; i++) {
        insert_data(root, &s[i], less_than_equal);
    }
    return root;
}


void draw_tree(const node_t* root) {
    draw_tree_internal(root);
}

/*
 * 
 * 
 */
static void reorg_subtree(node_t * node) {
    
}
enum find_ret_val remove_element(node_t **prev_child, node_t *node, type item) {
    /*
     * check for root case first
     * if root then prev_child is not applicable since there is no parent
     *
     * check current node
     *  if found then 
     * check left
     *  if found th
     *
     * check right
     */ 
    
    return BST_NOT_FOUND;
}
int main(int argc, char**argv) {
 
    {
        const char s1[] = { 'M', 'a', 'n', 'a', 's', 'i'};
        node_t* root = build_tree(sizeof(s1), s1);
        draw_tree(root);

    }
    
    {
        const char s[] = { 'S', 'a', 'n', 'k', 'e', 't'};
        node_t* root = build_tree(sizeof(s), s);
        draw_tree(root);

    }
    
    {
        const char s[] = { 'O', ' ', 'C', 'a', 'n', 'a', 'd', 'a'};
        node_t* root = build_tree(sizeof(s), s);
        draw_tree(root);

    }

    return 0;
}
