#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
using subset_t = set<int>;
using supaset_t = set<subset_t>;
set<int> supaset;

int main() {
   // given set
   set<int> input;
   input.insert(2);
   input.insert(3);
   input.insert(4);
   input.insert(5);
   for (auto e: input) {
      cout << e << ",";
   }
   cout << endl; 
   
   supaset_t supa;
   for (auto e: input) {
      subset_t s;
      s.insert(e);
      supa.insert(s);
   }
   
   
   return 0;
}

