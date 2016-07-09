#include <iostream>
#include <cmath>

using namespace std;

// TODO 
// figure out how to pass in the 
// 2d aray into functions!
//template<typename T, size_t row, size_t col> 
/*int calc_primary_diag(size_t sz, const int (**ar)) {
   cout << __func__ << endl;
   int sum = 0;
   size_t i = 0, j = 0;
   while(i < sz && j < sz) {
      sum += ar[i][j];
      i++;
      j++;
   }
   return sum;
}*/

int main() {
   size_t sz;
   //cout << "size? ";
   cin >> sz;
   int ar[sz][sz];
   for(int i =0; i < sz; i++) {
      for(int j= 0; j < sz; j++) {
         //cout << "element[" << i <<"][" << j << "]? ";
         cin >> ar[i][j];
      }
   }

   /*cout << "\n You entered: \n"; 
   for(int i =0; i < sz; i++) {
      for(int j= 0; j < sz; j++) {
         cout << ar[i][j] << ", ";
      }
      cout << endl;
   } */  

   //int s1 = calc_primary_diag(sz, ar[sz][sz]);

int s1,s2;
{
   s1 = 0;
   size_t i = 0, j = 0;
   while(i < sz && j < sz) {
      s1 += ar[i][j];
      i++;
      j++;
   }

   //cout << "primary diagonal sum = " << sum << endl;
}

{
s2 = 0;
   size_t i = 0, j = sz - 1;
   while(i < sz && j >= 0 ) {
      s2 += ar[i][j];
      i++;
      j--;
   }
   //cout << "secondary diagonal sum = " << sum << endl;
}
   
   cout << abs(s1 - s2) << endl;
   return 0;
} 