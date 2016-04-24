#include <stdio.h>



int main(int argv, char** argc) {
    const int MAX_CHARS = 32;
    char line[MAX_CHARS];
    int index = 0;
    
    // Note: you can enter many chars here which goes into a special input buffer
    // everything here after first char will get added to line[] on subsequent
    // getchars()
    
    char c = getchar();
    putchar(c);
    putchar('\n');

    printf("FYI: value of EOF on your platform is  %d, on linux/mac press Ctrl-D for EOF\n", EOF);
    // Use an array to save counts
    // 0 -> space
    // 1- > tab
    // 2 -> newline
    int char_counts[] = {0, 0 , 0};

    while ((c = getchar()) != EOF) {
        if (index >= MAX_CHARS) {
            printf("Output truncated!\n");
            break;
        }

        switch(c) {
            case ' ':
                char_counts[0]++;
                line[index++] = '\\';
                line[index++] = 's';
                break;
            case '\t':
                char_counts[1]++;
                line[index++] = '\\';
                line[index++] = 't';
                break;
            case '\n':
                char_counts[2]++;
                line[index++] = '\\';
                line[index++] = 'n';
                break;
            default:
                line[index++] = c;
                break;
        }
    }
    printf("Got input of: %s\n", line);
    printf("There are %d spaces, %d tabs and %d newlines\n", 
        char_counts[0],
        char_counts[1],
        char_counts[2]);

}