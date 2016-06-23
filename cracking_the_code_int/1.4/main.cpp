#include <iostream>
using namespace std;

class Solver {
   int str1Cnt[26] = {};
   int str2Cnt[26] = {};
   string s1, s2;
   static int getIndex(const char c);
   static void inline updateCnt(int ar[], const int index) {
      ar[index] += 1;
   }
   static void dumpArray(int a[], size_t sz) {
      string s;
      for (int i = 0; i < int(sz); i++) {
         s.append(to_string(a[i]));
         s.append(",");
      }
      cout << s << endl;
   }
   class BadInput {};
   Solver() {}
public:
   bool isAnagram() throw(BadInput);
   Solver(string s1, string s2):s1(s1), s2(s2) {
      cout << "ctor" << endl;

      dumpArray(str1Cnt, sizeof(str1Cnt));  
      dumpArray(str2Cnt, sizeof(str2Cnt));  

   }
};

int Solver::getIndex(const char c) {
   if ((c >= 'a') && (c <= 'z')) {
      return (c - 'a');
   }
   else if ((c >= 'A') && (c <= 'Z')) {
      return (c - 'A');
   } else {
      return -1;
   }
}

bool Solver::isAnagram() throw(BadInput){
   // iterate over each string and update
   // freq of letters
   // int i = getIndex
   string::iterator iter = s1.begin();

   // TODO put this in private method
   while(iter != s1.end()) {
      int i = getIndex(*iter);
      if (i == -1) throw BadInput();
      updateCnt(str1Cnt, i);
      iter++;
   }

   iter = s2.begin();
   while(iter != s2.end()) {
      int i = getIndex(*iter);
      if (i == -1) throw BadInput();
      updateCnt(str2Cnt, i);
      iter++;
   }

   dumpArray(str1Cnt, sizeof(str1Cnt));  
   dumpArray(str2Cnt, sizeof(str2Cnt));  
   return false;
}

int main() {
   Solver s("abcd", "cdbA");
   if (s.isAnagram()) {
      cout << "We have anagrams!" << endl;
   }
   return 0;
} 
