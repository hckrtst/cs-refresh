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

static char* strip_char_from_str(char s[], const char ref[]) {
  int src, dest, i;

  if ((ref == NULL) || (s == NULL)) return s;


  for(src = dest = 0; s[src] != '\0'; src++)
  {
      for(i = 0; ref[i] != '\0'; i++) {
         if (s[src] == ref[i]) {
            break;
         }
      }
      if (ref[i] == '\0') {
         s[dest++] = s[src];
      }
  }
  s[dest] = '\0';
  return s;
}

static inline void test(const char ref[], const char expected[]) {
   char s[] = "viva las vegas";
   assert(strcmp(strip_char_from_str(s, ref), expected) == 0);
}

int main(int argc, char **argv) {
    test("silo", "vva a vega");
    test("gh", "viva las veas");
    test("", "viva las vegas");
    test("xyz", "viva las vegas");
    cheers();
    return 0;
}
