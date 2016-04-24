#include <stdio.h>

#define WC_LINE_INDEX   0
#define WC_WORD_INDEX   1
#define WC_CHAR_INDEX   2
#define WC_SPACE        ' '
#define WC_NEWLINE      '\n'
#define WC_TAB          '\t'

int main(int argc, char **argv) {
    char c = 0;
    int is_word = 0;

    printf("\n\n");
    
    // lines, words, chars
    int counts[] = {0, 0, 0};

    while ((c = getchar()) != EOF) {
        counts[WC_CHAR_INDEX] += 1;
        if (c == WC_SPACE || c == WC_NEWLINE || c == WC_TAB) {
            if (is_word) {
                counts[WC_WORD_INDEX] += 1;
                is_word = 0;
            }
            if (c == WC_NEWLINE) {
                counts[WC_LINE_INDEX] += 1;
            }
        } else {
            if (!is_word) {
                is_word = 1;    
            }
        }
    }
    printf("lines: %d\twords: %d\tcharacters: %d\n", 
        counts[WC_LINE_INDEX],
        counts[WC_WORD_INDEX],
        counts[WC_CHAR_INDEX]);
    printf("*** Copyright 2016 (C) Flying Coyote Software *** \n\n");
    return 0;
}