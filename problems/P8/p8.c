#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv) {

    printf("Not so random numbers\n");
    my_srand(31456);
    for (int i = 0; i < 20; i ++) {
        printf("random num = %d\n", my_rand());
    }

    
    return 0;
}