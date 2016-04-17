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

char *my_itoa(const int i) {
    int j = i;
    const int MAX_CHARS = 12;
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // calloc zeroes out memory
    char *s = (char*) calloc(MAX_CHARS, sizeof(char));
    int len;
    if (i < 0) {
        len = get_char_r((-1 *j), digits, s, 1);
        s[0] = '-';
    } else {
        len = get_char_r(j, digits, s, 0);
    }
    
    return s;    
}  

int main(int argc, char **argv) {
    {
        char *s = my_itoa(345500);
        printf("Outcome = %s \n", s);
        free(s);
    }

    {
        char *s = my_itoa(9);
        printf("Outcome = %s \n", s);
        free(s);
    }

    {
        char *s = my_itoa(-13456789);
        printf("Outcome = %s \n", s);
        free(s);
    }



}