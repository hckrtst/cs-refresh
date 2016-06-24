#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Solver {
   // initialize arrays to 0
   int str1Cnt[26] = {0};
   int str2Cnt[26] = {};
   string s1, s2;
   static int getIndex(const char c);
   static void inline updateCnt(int ar[], const int index) {
      ar[index] += 1;
   }
   static void dumpArray(int a[], size_t sz) {
      //string s;
      printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");  
      for (int i = 0; i < int(sz); i++) {
         printf("%d(%d), ", i,a[i]);
         //s.append(to_string(a[i]));
         //s.append(",");
      }
      printf("\n");
      //cout << s << endl;
      printf("------------------------------------------------------------\n");
   }
   static bool isEqual(int a1[], int a2[], size_t sz) {
      for (int i = 0; i < sz; i++) {
         if (a1[i] != a2[i]) return false;
      }
      return true;
   }
   class BadInput {};
   Solver() {}
public:
   bool isAnagram() throw(BadInput);
   Solver(string s1, string s2):s1(s1), s2(s2){
      cout << "ctor" << endl;
      dumpArray(str1Cnt, sizeof(str1Cnt)/sizeof(str1Cnt[0]));  
      dumpArray(str2Cnt, sizeof(str2Cnt)/sizeof(str2Cnt[0]));  
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

   dumpArray(str1Cnt, sizeof(str1Cnt)/sizeof(str1Cnt[0]));  
   dumpArray(str2Cnt, sizeof(str2Cnt)/sizeof(str2Cnt[0]));

   return isEqual(str1Cnt, str2Cnt, sizeof(str1Cnt)/sizeof(str1Cnt[0]));
}

int main() {
   Solver s("abcd", "cdba");
   if (s.isAnagram()) {
      cout << "We have anagrams!" << endl;
   }
   
   Solver s2("axcdf", "xcderf");
   if (s2.isAnagram()) {
      cout << "We have anagrams!" << endl;
   }
   return 0;
} 
