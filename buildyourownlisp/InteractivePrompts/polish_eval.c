// Build with -lm option
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpc.h"
#include "linenoise.h"

#define INPUT_BUFFER_LEN 48
// Declare this as static so as to avoid name collision
// if we link this with another module
static char input_buf[INPUT_BUFFER_LEN];

#define NDEBUG 1

#define dbg(fmt, ...) \
    do { if (NDEBUG) fprintf(stdout, fmt, __VA_ARGS__); } while(0); 


long eval_op(long x, const char* operator, long y) {
    if (strcmp(operator, "+") == 0) return (x + y);
    if (strcmp(operator, "-") == 0) return (x - y);
    if (strcmp(operator, "*") == 0) return (x * y);
    if (strcmp(operator, "/") == 0) return (x / y);
    return 0;
}

long eval(mpc_ast_t *t) {
    /* numbers can be returned directly */
    if (strstr(t->tag, "number")) {
        printf("test\n");
        dbg("got number = %s\n", t->contents);
        return atoi(t->contents);
    }
    
    /* first child is '(' so second child is operator */
    char *op = t->children[1]->contents;

    /* evaluate the first operand and store as 
     * result 
     */
    long result = eval(t->children[2]);

    /* evaluate the rest of the operands and recursively
     * calls their children to get the final output
     */
    int index = 3;
    while (strstr(t->children[index]->tag, "expression")) {
        result = eval_op(result, op, eval(t->children[index]));
        index++;
    }

    return result;
}

int main(int argc, char** argv) {
    /* Create parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* TextOp = mpc_new("textop");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expression = mpc_new("expression");
    mpc_parser_t* Lispy = mpc_new("lispy");
    
    linenoiseClearScreen();

    /* Define them with the language as follows */
    mpca_lang(MPCA_LANG_DEFAULT, 
            " number      : /-?[0-9]+/ ; "
            " textop      : /(mult|div)/ ; "
             " operator    : '+' | '/' | '*' | '-' | <textop> ; "
             " expression  : <number> | '(' <operator> <expression>+ ')' ; "
             " lispy        : /^/ <operator>* <expression> /$/ ; ", Number, TextOp, Operator, Expression, Lispy);
    char *line = NULL;

    while((line = linenoise("Lispy> ")) != NULL ) {
        mpc_result_t result;

        if (mpc_parse("<stdin>" , line, Lispy, &result)) {
            long r = eval(result.output);
            printf("%li\n", r);
            mpc_ast_delete(result.output);
        } else {
            mpc_err_print(result.output);
            mpc_err_delete(result.output);
        }

        free(line);
    }

    mpc_cleanup(5, Number, Operator, Expression, Lispy, TextOp);

    return 0;
   
}

/* 
 * Try this expression:
 * Lispy> (* ( - 6 7 ) 8 )
*/
