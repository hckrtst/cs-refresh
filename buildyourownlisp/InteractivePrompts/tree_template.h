#pragma once


#define define_payload(type) \
        typedef struct payload_t{ \
            type *data; \
        }payload_t
 
#define define_node() \
        typedef struct node_t { \
            payload_t *payload; \
            struct node_t *left, *right; \
        }node_t


#define define_lte() typedef int (*lte)(payload_t *a, payload_t *b)

#if 0
#define insert_data(type, data) \
    do \
    
    insert(type *data) 
    wiile(0)
#endif
