#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static char* _strcat(char dest[], const char src[]) {
  int i, j;
  i = j = 0;

  // we shouldn't use dest[i++] here
  // since it causes i to overshoot
  // for the next iteration
  while(dest[i] != '\0') {
    ++i;
  }

  // we inc i and j after each read
  // which is ok here
  while((dest[i++] = src[j++]) != '\0');

  return dest;
}

int main(int argc, char *argv[]) {
    char *mystr = (char*)calloc(8, sizeof(char));
    if (mystr) {
      mystr[0] = 'a';
      mystr[1] = 'b';

      _strcat(mystr, "def");

      printf("Output = %s\n", mystr);
      free(mystr);
    }
    return 0;
}