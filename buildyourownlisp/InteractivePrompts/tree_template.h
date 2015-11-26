#pragma once

/* Copyright (c) 2015 Sanket K (hckrtst)
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *
 */

/*
 * This is a template of a binary tree which allows users to define tree that hold
 * data of any arbitrary type. The macros below allow a rudimentary templating 
 * system.
 * It important for the user to use the macros in the order defined below.
 */ 
#define define_payload(type)            \
        typedef struct payload_t{       \
            type *data;                 \
        }payload_t
 
#define define_node()                   \
        typedef struct node_t {         \
            const payload_t *payload;         \
            struct node_t *left, *right;\
        }node_t

/* "Less than or equal to" function must be supplied by user
 * since we don't know ahead of time how they can be compared.
 * This is similar to a comparator or operator overloading in
 * some languages.
 * Define the prototype for this function here.
 */
#define define_lte() typedef int (*lte_t)(node_t *a, node_t *b)

#define init_payload(payload, dat)   \
    do {                                    \
        payload = (payload_t*)(malloc(sizeof(payload_t))); \
        payload->data = dat;                               \
    }while(0)

#define create_node(node, dat)    \
    do {                    \
        payload_t *payload = NULL; \
        init_payload(payload, dat);      \
        node = (node_t*) malloc(sizeof(node_t)); \
       if (node == NULL) {                          \
            fprintf(stderr, "Cannot allocate node\n"); \
       }                                               \
       node->payload = payload; \
       node->left = NULL; node->right = NULL; \
    }while(0)

#define create_tree(dat) \
    do { \
        node_t *root = NULL; \
        create_node(root, dat); \
        return root; \
    } while (0)

/* Caution: It's up to user to deallocate data
 */
#define free_payload(payload)       \
    do {                            \
    free(payload);                  \
    }while(0)

#define insert_data(root, dat, lte) \
    do { \
        node_t* node = NULL; \
        create_node(node, dat); \
        node_t *cursor = root; \
        while(1) {              \
            if (lte(node, cursor)) { \
                if(cursor->left != NULL) { \
                    printf("continue left from %d\n", *(cursor->payload->data)); \
                    cursor = cursor->left; \
                    continue; \
                } else { \
                    printf("inserting %d left of %d\n", *dat, *(cursor->payload->data));  \
                    cursor->left = node; \
                    break; \
                } \
            }else { \
                if(cursor->right != NULL) { \
                    printf("continue right from %d\n", *(cursor->payload->data)); \
                    cursor = cursor->right; \
                    continue; \
                } else { \
                    printf("inserting %d right of %d\n", *dat, *(cursor->payload->data));  \
                    cursor->right = node; \
                    break; \
                } \
            }\
        }\
    } while(0)


/* TODO walk tree to insert data, use lte 
         * node_t * cursor = root;
         * while(1) {
         *  if (lte(node, cursor)) {
         *      // walk left
         *      if (cursor->left != NULL) {
         *          cursor = cursor->left;
         *          continue;
         *      } else {
         *          cursor->left = node;
         *      }
         *  } else {
         *      // walk right
         *      ...
         *  }
         *  }
         * */

