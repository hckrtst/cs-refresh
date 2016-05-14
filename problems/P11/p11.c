#include<stdio.h>
#include<assert.h>
#include<string.h>

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
static const char*my_strpbrk(const char* const s1, const char* const s2) {
   for (int i = 0; s1[i] != '\0'; i++) {
      for (int j = 0; s2[j] != '\0'; j++) {
         if (s1[i] == s2[j]) return &s1[i];
      }
   }
   return NULL;
}
int main(int argc, char*argv[]) {
   assert(strpbrk("test", "set") == my_strpbrk("test", "set"));
   printf("PASS\n");
   assert(strpbrk("test", "xqi") == my_strpbrk("test", "xqi"));         
   printf("PASS\n");
   assert(strpbrk("test", "") == my_strpbrk("test", ""));         
   printf("PASS\n");
   assert(strpbrk("", "abc") == my_strpbrk("", "abc"));         
   printf("PASS\n");

   cheers();   
   return 0;
}
