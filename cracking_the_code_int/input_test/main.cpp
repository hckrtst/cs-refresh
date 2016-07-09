#include <iostream>
using namespace std;

int main() {
   size_t sz;
   cin >> sz;
   int ar[sz] = {0};
   cout << "size of ar = " << sizeof(ar) << endl;
   int i = 0;
   while(i < sz)  {
      // CAUTION: Don't try to do 
      // cin >> ar[i++]
      // The post-increment will happen in correctly and cause
      // a segfault
      cin >> ar[i];
      i++;
   }
   for (int i = 0; i < sz; i++) {
      cout << ar[i] << " ";
   }
   cout << endl;
   return 0;
} 