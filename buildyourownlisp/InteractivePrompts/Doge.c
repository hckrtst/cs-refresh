#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpc.h"

#define INPUT_BUFFER_LEN 48
// Declare this as static so as to avoid name collision
// if we link this with another module
static char input_buf[INPUT_BUFFER_LEN];

int main(int argc, char** argv) {
    mpc_parser_t* Adjective = mpc_or(4,
            mpc_sym("wow"), mpc_sym("many"),
            mpc_sym("so"), mpc_sym("such")
    );

    mpc_parser_t* Nound = mpc_or(5,
            mpc_sym("lisp"), mpc_sym("book"),
            mpc_sym("hammer"), mpc_sym("laser"),
            mpc_sym("rocket")
    );

    return 0;
   
}
