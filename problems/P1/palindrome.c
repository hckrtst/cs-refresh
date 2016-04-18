#include <stdio.h>
#include <stdlib.h>

int is_neg(char c) {
    if (c == '-') return 1;
    return 0;
}
// asumme string is well-formed (no spaces etc.)
// assume negative numbers and single digits are not palindromes
int is_palindrome(const char* const s) {
    if (is_neg(s[0])) return 0;
    int len = strlen(s);
    if (len == 1) return 0;
    int res = 1;
    int t = len - 1;
    for (int i = 0; i < len / 2; i++, t--) {
        if (s[i] != s[t]) {
            res = 0;
            break;
        }
    }
    return res;
}

int main(int argc, char **argv) {
    char *s;
    my_itoa(345500, &s);
    printf("Outcome = %s palin = %d\n", s, is_palindrome(s));

    free(s);
    my_itoa(9, &s);
    printf("Outcome = %s \n", s);
    free(s);
    my_itoa(-13456789, &s);
    printf("Outcome = %s \n", s);
    free(s);

    my_itoa(123454321, &s);
    printf("Outcome = %s, palin = %d\n", s, is_palindrome(s));
    free(s);

    
    return 0;

}
