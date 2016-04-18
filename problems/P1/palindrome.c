#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *s;
    my_itoa(345500, &s);
    printf("Outcome = %s \n", s);
    free(s);
    my_itoa(9, &s);
    printf("Outcome = %s \n", s);
    free(s);
    my_itoa(-13456789, &s);
    printf("Outcome = %s \n", s);
    free(s);
    
    return 0;

}
