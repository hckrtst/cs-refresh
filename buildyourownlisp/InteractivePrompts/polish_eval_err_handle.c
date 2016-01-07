#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpd.h"
#include "linenoise.h"


#define INPUT_LEN 48
static char input_buf[INPUT_LEN];

#define NDEBUG 1

long eval_op(long x, const char* operator, long y) {
    if (strcmp(operator, "+") == 0) return (x + y);
    if (strcmp(operator, "-") == 0) return (x - y);
    if (strcmp(operator, "*") == 0) return (x * y);
    if (strcmp(operator, "/") == 0) return (x / y);
    return 0;
}

long eval(mpc_ast_t *t, int tabsize) {
    
}


