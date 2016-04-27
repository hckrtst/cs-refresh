#include <stdio.h>
#include <assert.h>
#include <string.h>

int _strlen(const char *s) {
    if (s == NULL) return 0;
    register const char* c = s;
    while (*c) { c++; }
    return (c - s);
}

int main(int argc, char ** argv) {
    const char *test = "this is a test";
    printf("my strlen is %d\n", _strlen(test));
    assert(_strlen(test) == strlen(test));  

    printf("empty strlen is %d\n", _strlen(NULL));
    
}