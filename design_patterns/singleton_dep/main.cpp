#include <iostream>
using namespace std;

class Singleton1 {
   Singleton1() {
      cout << "Singleton1()" << endl;
   }
public:
   Singleton1(const Singleton1&) = delete;
   Singleton1& operator=(Singleton1&) = delete;
   static Singleton1& instance() {
      static Singleton1 s;
      return s;
   }
};

class Singleton2 {
   Singleton1& s;
   Singleton2(Singleton1& s):s(s) {
      cout << "Singleton2(s)" << endl;
   }
public:
   Singleton2& operator=(Singleton2&) = delete;
   Singleton2(const Singleton2&) = delete;
   static Singleton2& instance() {
      static Singleton2 single(Singleton1::instance());
      return single;
   }
   Singleton1& getS1() {
      return s;
   }
};

int main() {
   Singleton1& s = Singleton2::instance().getS1();
   return 0;
}