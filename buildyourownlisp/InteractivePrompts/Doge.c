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

int main(int argc, char** argv) {
    /* Create parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expression = mpc_new("expression");
    mpc_parser_t* Lispy = mpc_new("lispy");
    
    linenoiseClearScreen();

    /* Define them with the language as follows */
    mpca_lang(MPCA_LANG_DEFAULT, 
            " number      : /-?[0-9]+/ ; "
             " operator    : '+' | '/' | '*' | '-' ; "
             " expression  : <number> | '(' <operator> <expression>+ ')' ; "
             " lispy        : /^/ <operator>* <expression> /$/ ; ", Number, Operator, Expression, Lispy);
    char *line = NULL;

    while((line = linenoise("Lispy> ")) != NULL ) {
        mpc_result_t result;

        if (mpc_parse("<stdin>" , line, Lispy, &result)) {
           mpc_ast_print(result.output);
           mpc_ast_delete(result.output);
        } else {
            mpc_err_print(result.output);
            mpc_err_delete(result.output);

        }

        free(line);
    }

    mpc_cleanup(4, Number, Operator, Expression, Lispy);

    return 0;
   
}

/* 
 * Try this expression:
 * Lispy> (* ( - 6 7 ) 8 )
 * /
