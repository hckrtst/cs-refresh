#include <iostream>
using namespace std;
typedef unsigned long long loong;

int main() {
   unsigned int sz;
   cin >> sz;
   unsigned long long int N[sz] = {0}, M[sz] = {0}, S[sz] = {0};
   for (int i = 0; i < sz; i++) {
      cin >> N[i] >> M[i] >> S[i];
   }   
   
   for (int i = 0; i < sz; i++) {
      // give out sweets from S until N
      unsigned long long distributed = (N[i] - S[i]) + 1;
      // candies already given out!
      if (distributed >= M[i]) {
         //cout << "a>"; 
         cout << (S[i] + M[i] - 1) << endl;
      } else {
         // more candies left over
         loong left = M[i] - distributed;
         // if candies more than number of prisoners then
         // we can start wrapping around N
         if (left > N[i]) {
            loong a = left % N[i];
            //cout<<"b>";
            cout  << a  << endl;
         }  else {
            //cout<<"c>";
            cout << left << endl;
         }   
      } 
   } 

   return 0;
} 