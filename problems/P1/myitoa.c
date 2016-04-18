#include <stdio.h>
#include <stdlib.h>


/*
* We leverage the system stack to ensure that numbers are popped off
* in the correct order
*/
int get_char_r(int i, const char digits[], char outcome[], const int is_neg) {
    if ((i >= 0) && (i <= 9))  {
        int index = 0;
        if (is_neg) {
            index = 1;
        }
        outcome[index] = digits[i];
        return index;
    } else {
        int rem = i % 10;
        int index = (get_char_r(i/10, digits, outcome, is_neg)) + 1;
        outcome[index] = digits[rem];
        return index;
    }
}

void my_itoa(const int i, char **str_val) {
    int j = i;
    const int MAX_CHARS = 12;
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // calloc zeroes out memory
    *str_val = (char*) calloc(MAX_CHARS, sizeof(char));
    int len;
    if (i < 0) {
        len = get_char_r((-1 *j), digits, *str_val, 1);
        (*str_val)[0] = '-';
    } else {
        len = get_char_r(j, digits, *str_val, 0);
    }    
}