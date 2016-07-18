#include <iostream>
#include <vector>
using namespace std;

static void print_v1(int ar[][5], int num_row, int num_col) {
   cout << "**** v1 ****" << endl;
   for (int i=0; i<num_row; i++) {
      for (int j=0; j < num_col; j++) {
         printf("%d ", ar[i][j]);
      }
      printf("\n");
   }
}

int main() {
   // columns must be explicitly specified
   // needed by compiler to genrate correct
   // address
   int a[][5] = {
      { 1, 2 ,5 ,6, 5},
      { 3, 4, 5, 1, 10},
      { 1, 2 ,5 ,6, 5},
      { 1, 2 ,5 ,6, 5},
      { 1, 2, 5, 1, 10},
   };
   //print_v1(a, 5, 5);

   for (int r=0; r<4; r++) {
      vector<int> same;

      for (int j=0; j<5; j++) {
         bool found = false;
         //cout << "col=" << j << endl;
         for (int i=r; i < 5; i++) {
            //cout << a[i][j] << " ";
            if (a[r][j] == a[i][j]) same.push_back(a[i][j]);
            else {
               break;
            }
         }
         cout << endl;
      }
      for(auto d: same) {
         cout << d << ",";
      }
      cout << endl;
   }
   return 0;
}