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
#include <assert.h>

int _isneg(const char c) {
    if (c == '-') return 1;
    return 0;
}

/*
 remove extra spaces and check for signs
*/
int _trim(const char* const s, char **cursor) {
    int res = 1;
    // remove any extra spaces
    while (**cursor == ' ') {
        (*cursor)++;
    }
    
    if (_isneg(**cursor)) {
        res = -1;
        (*cursor)++;
    } else if (**cursor == '+') {
        (*cursor)++;
    }

    while (**cursor == ' ') {
        (*cursor)++;
    }

    return res;
}

// TODO handle overflow/underflow
int _extract_digits(char ** cursor) {
    int acc = 0;
    while (*cursor != NULL && **cursor >= '0' && **cursor <= '9') {
        acc = acc * 10 + (**cursor - '0');

        // CAUTION: Always add an incrementor in while loops right away!!!!!!
        (*cursor)++;
    }
    return acc;   
}

int str_to_int(const char* const s) {
    if (s == NULL) return 0;

    int sign = 0;
    char *cursor = s;
    sign = _trim(s, &cursor);

    int res = _extract_digits(&cursor);

    return (res * sign);
}

int main(int argc, char **argv) {
    int n = str_to_int("+3456");
    assert(n == 3456);

    n = str_to_int("-234");
    assert(n == -234);

    n = str_to_int("   -   0");
    assert(n == 0);

    n = str_to_int("- + 56");
    assert(n == 0);

    printf("All passed\n");
}
