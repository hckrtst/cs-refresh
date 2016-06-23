#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

char *find_tail(const char* p) {
   char *t = (char*) p;
   while (*t++ != '\0');
   // 2 because we also want to
   // exclude the \0
   t-=2;
   return t;
}

void swap(char *h, char *t) {
   cout << "swapping" << *h << " and " << *t << endl;
   char tmp = *h;
   *h = *t;
   *t = tmp;
}


void reverse_in_place(char txt[]) {
   if (txt == NULL) {
      cout << "Bad user!" << endl;
      return;
   }
   // find end of string
   char *head = txt;
   char *tail = find_tail(txt);

   while(head <= tail) {
      swap(head++, tail--);
   }
}


int main() {
   const int MAX = 64;
   {
   const char *str1 = "greenday";
   char src[MAX] = {0};
   snprintf(src, sizeof(src) - 1, str1);
   reverse_in_place(src);
   cout << src << endl;
   assert(strncmp(src, "yadneerg", strlen(src)) == 0);
   }

   {
   const char *str1 = "";
   char src[MAX] = {0};
   snprintf(src, sizeof(src) - 1, str1);
   reverse_in_place(src);
   assert(strncmp(src, "", strlen(src)) == 0);
   }

   {
   reverse_in_place(NULL);
   assert(1);
   }



   return 0;
} 
