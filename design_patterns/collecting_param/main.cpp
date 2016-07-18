#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CollectingParameter : public vector<string> {};

class Filler {
public:
   void a(CollectingParameter& cp) {
      cp.push_back("at");
   }
   void b(CollectingParameter &cp) {
      cp.push_back("the beach.");
   }
};

int main() {
   CollectingParameter cp;
   cp.push_back("A day");
   Filler filler;
   filler.a(cp);
   filler.b(cp);
   for(auto d: cp) {
      cout << d << " ";
   }
   cout << endl;
   return 0;
}