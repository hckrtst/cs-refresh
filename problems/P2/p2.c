#include <stdio.h>
#include "utils.h"
#include <assert.h>

static void cheers() {
  printf("\n\n\nALl done, go have a drink!\n\n\n");
  const char* mug[] = {
      "         _.._..,_,_",
      "        (          )",
      "         ]~,\"-.-~~[",
      "       .=])' (;  ([",
      "       | ]:: '    [",
      "       '=]): .)  ([",
      "         |:: '    |",
      "          ~~----~~\"",
      " - artwork by Paul Martin Howard -"
  };

  int num_elements = sizeof(mug) / sizeof(mug[0]);
   for (int i = 0; i < num_elements; i++) {
      char dest[48];
      snprintf(dest, sizeof(dest), mug[i]);
      printf("%s\n", dest);
   }
   printf("\n\n");
}

static void strip_char(char s[], const char c) {
  int src, dest;

  for(src = dest = 0; s[src] != '\0'; src++)
  {
    if (s[src] != c) {
      s[dest++] = s[src];
    }
  }
  s[dest] = '\0';
}

int main(int argc, char **argv) {
    char s[] = "viva las vegas";
    strip_char(s, 'v');
    printf("\n\nNew string is: %s\n", s);
    cheers();
    return 0;
}