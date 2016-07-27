#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
using subset_t = set<int>;
using supaset_t = set<subset_t>;

static void pr_set(subset_t s) {
   for (auto e: s) {
      cout << e << ",";
   }
   cout << endl;
}

supaset_t getSubSet(subset_t s) {
   
   if (s.empty()) {
      cout << "empty" << endl;
      return supaset_t();
   }

   if (s.size() == 1) {
      cout << "elem" << *(s.begin()) << endl;
      supaset_t su;
      su.insert(s);
      return su;
   }
   
   int a = *(s.begin());
   s.erase(a);
   supaset_t sup = getSubSet(s);
   for (supaset_t::iterator it = sup.begin(); it != sup.end(); it++) {
      subset_t sub = *it;
      sub.insert(a);
      sup.insert(sub);
   }
   subset_t sub;
   sub.insert(a);
   sup.insert(sub);
   for (auto e: sup) {
      pr_set(e);
   }
   cout << endl;
   return sup;
}

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
   
   getSubSet(input);    
   
   return 0;
}

