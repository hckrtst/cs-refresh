/* 

Problem:

1.Convert string to signed int
Input: "-3456"
Output: -3456

input: "-0000021"
output:-21

input: "-     34"
output:-32

input: "+ 34"
output: 34

input:"-0"
output:0

input:"+-345"
output: 0

input: -345+
output: -345


Handle integer overflow/underflow gracefully

2.Convert signed int to string
*/

#include <stdio.h>

int _isdigit(const char c) {
    if (c == '+' || c == '-') return 1;
    return 0;
}

/*
 remove extra spaces and check for signs
*/
int _trim(const char* const s, char **cursor) {
    int result = 1;
    // remove any extra spaces
    while (**cursor == ' ') {
        (*cursor)++;
    }

    int is_sign_found = 0;

    if (_isdigit(**cursor)) {
        is_sign_found = 1;
        (*cursor)++;
    }

    while (**cursor == ' ') {
        (*cursor)++;
    }

    if (**cursor < '0' || **cursor > '9') result = 0;
}

int _extract_digits(char ** cursor) {
    int acc = 0;
    while (*cursor != NULL && **cursor >= '0' && **cursor <= '9') {
        acc = acc * 10 + (**cursor - '0');
    }
    return acc;   
}

int str_to_int(const char* const s) {
    if (s == NULL) return 0;

    int res = 0;
    char *cursor = s;
    res = _trim(s, &cursor);

    if (res) {
        res = _extract_digits(&cursor);
    } else {
        printf("Illegal char \n");
    }

    return res;
}

int main(int argc, char **argv) {
    int n = str_to_int("3456");
    assert(n == 3456);

    n = str_to_int("-234");
    assert(n == -234);
}
