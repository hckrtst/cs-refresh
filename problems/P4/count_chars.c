#include <stdio.h>

int main(int argv, char** argc) {
    char line[32];
    int index = 0;
    char c;
    while ((c = getchar()) != EOF) {
        line[index++] = c;

    }
    printf("%s\n", line);        
}