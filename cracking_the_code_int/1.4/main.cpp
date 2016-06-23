#include <iostream>
using namespace std;

class Solver {
   int str1Cnt[26] = {0};
   int str2Cnt[26] = {0};
   string s1, s2;
   static int getIndex(const char c);
   static void inline updateCnt(int ar[], const int index) {
      ar[index] += 1;
   }
   class BadInput {};
   Solver() {}
public:
   bool isAnagram() throw(BadInput);
   Solver(string s1, string s2):s1(s1), s2(s2) {
   }
};

int Solver::getIndex(const char c) {
   if ((c >= 'a') && (c <= 'z')) {
      return (c - 'a');
   }
   else if ((c >= 'A') && (c <= 'Z')) {
      return (c - 'Z');
   } else {
      return -1;
   }
}

bool Solver::isAnagram() throw(BadInput){
   // iterate over each string and update
   // freq of letters
   // int i = getIndex
   throw BadInput();
   return false;
}

int main() {
   Solver s("abcd", "cdef");
   s.isAnagram();
   return 0;
} 
