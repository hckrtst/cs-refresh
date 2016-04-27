#include <stdio.h>

#define MAXLINE 1000

// local functions
static int _getline(char s[], int len);
static int copyline(const char src[], const int len, char dest[]);

// local vars
static int maxlen = 0;
static char maxline[MAXLINE] = {'\0'};

int main(int argc, char **argv) {
    int len = 0;
    char line[MAXLINE] = {'\0'};
    while ((len = _getline(line, MAXLINE)) > 0) {
      if (len > maxlen) {
        copyline(line, MAXLINE, maxline);
        maxlen = len;
      }  
    }
    
    printf("Longest line ==> Length = %d,  Line = %s\n", maxlen, maxline);
    return 0;
}

// local functions

static int _getline(char s[], int len) {
    if (s == NULL) {
        printf("null line\n");
        return 0;
    }

    char c;
    int i = 0;
    for (i = 0; 
        (i < len - 1) && ((c = getchar()) != EOF) && (c != '\n'); 
        i++) {
        
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

static int copyline(const char src[], const int len, char dest[]) {
    if ((src == NULL) || (dest == NULL)) {
        return 0;
    }

    for (int i = 0; i < len && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return 1;
}