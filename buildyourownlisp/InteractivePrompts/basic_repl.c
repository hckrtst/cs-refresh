#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linenoise.h"

#define INPUT_BUFFER_LEN 48
// Declare this as static so as to avoid name collision
// if we link this with another module
static char input_buf[INPUT_BUFFER_LEN];


void completion(const char *buf, linenoiseCompletions *lc) {
    if (buf[0] == 'h') {
        linenoiseAddCompletion(lc, "hello user");
        linenoiseAddCompletion(lc, "hello kitty");
        linenoiseAddCompletion(lc, "hello sanket");
    } else if (buf[0] == 'q') {
        linenoiseAddCompletion(lc, "quit");
    }
}

int main(int argc, char** argv) {
    linenoiseClearScreen();
    puts("** Welcome to mini Lisp\'s playground\n");
    puts("Press Ctrl + c to exit\n");
    linenoiseSetCompletionCallback(completion);

    linenoiseHistoryLoad("history.txt");
   
    char *line = NULL;
    while((line = linenoise("lispy> ")) != NULL) {
       if (strcmp(line, "quit") == 0) {
           puts("Bye for now!\n");
           exit(0);
       } else if (line[0] != '\0') {
           printf("echo: %s \n", line); 
           linenoiseHistoryAdd(line);
           linenoiseHistorySave("history.txt");
       }
       free(line);
    }
}
