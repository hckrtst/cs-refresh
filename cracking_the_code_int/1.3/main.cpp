#include <iostream>
using namespace std;

void find_and_delete(const char* cursor, char c) {
   if ((cursor == NULL) || (*cursor == '\0')) {
      return;
   }
   
   //src ptr
   char *src = (char*) cursor;
   //dest ptr
   char *dest = src;

   while(*src != '\0') {
      if (*src != c) {
         *dest++ = *src;
      }
      src++;
   }

   // always nul terminate!
   *dest = '\0';
}

void remove_dups(char s[]) {
   if ((s == NULL) || (s[0] == '\0')) {
      cout << "Bad user!" << endl;
      return;
   }

   int i = 0;
   while(s[i] != '\0') {
      find_and_delete(&s[i+1], s[i]);
      i++;
   }
}
int main() {
   int MAX = 64;
   {
      const char *s = "An apple a day keeps the doctor away";
      char src[MAX] = {0};
      snprintf(src, sizeof(src)-1, s);
      remove_dups(src);
      cout << src << endl;
   }

   {
      const char *s = "";
      char src[MAX] = {0};
      snprintf(src, sizeof(src)-1, s);
      remove_dups(src);
      cout << "empty string"  << endl;
   }

   {
      remove_dups(NULL);
      cout << "NULL handled" << endl;
   }
  
   {
      const char *s = "A bag of dust";
      char src[MAX] = {0};
      snprintf(src, sizeof(src)-1, s);
      remove_dups(src);
      cout << src << endl;
   }

   {
      const char *s = "abcdefghi";
      char src[MAX] = {0};
      snprintf(src, sizeof(src)-1, s);
      remove_dups(src);
      cout << src << endl;
   }


   return 0;
} 
