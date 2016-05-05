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

static int _strlcat(char dest[], const char src[], const size_t size) {
  int i,j;
  i = j = 0;


  while ( i < size && dest[i] != '\0') {
    ++i;
  }

  if ( i == size) return i;

  while (i < size && (dest[i++] = src[j++]) != '\0');

  // adjust overshoot of i
  --i;

  if (i <= size) {
    dest[i+1] = '\0';
  }

  return (size - i - 1);
}

int main(int argc, char *argv[]) {
    {
      char *mystr = (char*)calloc(8, sizeof(char));
      if (mystr) {
        mystr[0] = 'a';
        mystr[1] = 'b';

        _strcat(mystr, "def");

        printf("Output = %s\n", mystr);

        // clean up
        free(mystr);
      }
    }

    /** Enable to see stack getting smashed

    char mystr2[] = {'a', 'b', 'c', 'd', '\0'};

    _strcat(mystr2, "efghijklmnopqrstuvwxyzsdjskdjdkjdksdjskdjdksjdksjdskdjskdjskjskdjskdjskjskjskjd");
    printf("Output = %s\n", mystr2);

    */

    {
      const size_t MAXS = 15 * sizeof(char);
      char *mystr = (char*)calloc(15, sizeof(char));
      if (mystr) {
        mystr[0] = 'a';
        mystr[1] = 'b';

        int ret_val = _strlcat(mystr, "cdefghijklmnopqrstuvwxyz", MAXS);

        printf("sizeof input = %lu, Output = %s, ret val = %d\n", MAXS, mystr, ret_val);

        // clean up
        free(mystr);
      }
    }

      {
       const size_t MAXS = 15 * sizeof(char);
      char *mystr = (char*)calloc(15, sizeof(char));
      if (mystr) {
        mystr[0] = 'a';
        mystr[1] = 'b';

        int ret_val = _strlcat(mystr, "cdefgh", MAXS);

        printf("sizeof input = %lu, Output = %s, ret val = %d\n", MAXS, mystr, ret_val);

        // clean up
        free(mystr);
      }
    }


    return 0;
}