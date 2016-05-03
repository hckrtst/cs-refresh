#include <stdio.h>
#include "utils.h"
#include <assert.h>

/*

         _.._..,_,_
        (          )
         ]~,"-.-~~[
       .=])' (;  ([
       | ]:: '    [
       '=]): .)  ([
         |:: '    |
          ~~----~~
art by Paul Martin Howard
*/

static void cheers() {
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

int main(int argc, char **argv) {
    printf("Running test suite\n");
    assert(my_htoi("   0x4ac") == 0x4ac);
    printf("Test 1 pass\n");

    assert(my_htoi("aab") == 0xaab);
    printf("Test 2 pass\n");

    assert(my_htoi("") == 0);
    printf("Test 3 pass\n");

    assert(my_htoi("12abcg") == 0);
    printf("Test 4 pass\n");

    printf("\n\n\nAll tests passed, go have a drink!\n\n\n");
    cheers();
    return 0;
}