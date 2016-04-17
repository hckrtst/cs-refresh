#include <stdio.h>

int get_char_r(int i, const char[] digits, char[] outcome) {
    if ((i >= 0) && (i <= 9))  {
        outcome[0] = digits[i];
        return 0;
    } else {
        int rem = i % 10;
        int index = (get_char_r(i/10, digits, outcome)) + 1;
        outcome[index] = digits[rem];
        return index;
    }
}

char *my_itoa(const int i) {
    int j = i;
    const int MAX_CHARS = 12;
    char digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];

    char *s = (char*) malloc(sizeof(char) * MAX_CHARS);
    (void) get_char_r(j, digits, s);
    return s;    
}  

int main(int argc, char **argv) {
    char *s = my_itoa(345500);
    printf("Outcome = %s", s);
    free(s);
}