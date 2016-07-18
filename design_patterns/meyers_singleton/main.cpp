#include <iostream>
using namespace std;

class Singleton {
private:
   static Singleton inst;
   Singleton(int x):val(x) {
      cout << "Ctor" << endl;
   };
public:
   int val;
   // Object is instantiated once
   // when instance() called first
   // a.k.a lazy initialization
   static Singleton& instance() {
      static Singleton inst(314);
      return inst;
   }
   // no copy
   Singleton(const Singleton&) = delete;
   // no assignment
   Singleton&
      operator=(Singleton&) = delete;
};

int main() {
   cout << "Enter Main" << endl;
   Singleton& s1 = Singleton::instance();
   cout << "s1.val=" << s1.val << endl;
   Singleton& s2 = Singleton::instance();
   s2.val = 413;
   cout << "s1.val=" << s1.val << endl;
   // not allowed
   // s1 = s2;
   // Singleton s3(s2);
   return 0;
}