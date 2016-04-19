#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/*
 Solution2 - without the need to create a string.
 Strip high and low numbers of integere and compare
 */
int is_palindrome2(const int num) {
    if (num < 0) return 0;

    int result = 1;
    // get number of digits 
    int d = num;
    int cnt = 0;
    while (d != 0) {
        cnt++;
        d /= 10;
    }

    d = num;
    while (cnt > 0) {
        cnt--;
        // strip the lowest digit
        int low = d % 10;
        int high = d / pow(10, cnt);
        if (low != high) {
            result = 0;    
            break;
        }

        // strip high
        d = d - (high * pow(10, cnt));
        //stip low
        d /= 10;
        cnt--;
    }

    return result;
}

/* 
Solution3
Create a number which is reverse of the given one and compare with original
*/
int is_palindrome3(const int num) {
    int d = num;
    int acc = 0;

    while (d > 0) {
        acc = acc * 10 + d % 10;
        d /= 10;
    }

    if (acc == num) return 1;

    return 0;
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

    printf("345000 palin = %d\n", is_palindrome2(345000));
    
    printf("89998 palin = %d\n", is_palindrome2(89998));
    
    printf("-234 palin = %d\n", is_palindrome2(-234));

    printf("345676543 panin = %d\n", is_palindrome3(345676543));

    printf("0 palin = %d\n", is_palindrome3(0));

    printf("1234 palin= %d\n", is_palindrome3(1234));
     
    return 0;

}
