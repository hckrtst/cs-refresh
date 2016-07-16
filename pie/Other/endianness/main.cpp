#include <iostream>
using namespace std;

int main() {
   unsigned int a = 1;
   if (*(char*)&a == 1) cout << "Little endian" << endl;
   else cout << "Big endian" << endl;
   return 0;
}