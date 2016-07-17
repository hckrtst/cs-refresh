#include <iostream>
#include <array>
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

// for arrays on heap
// passed by value on decayed type
static void print_v2(int (*ar)[5], size_t rows) {
   cout << "**** v2 ****" << endl;
   for (size_t i = 0; i < rows; i++) {
      for (int j = 0; j < 5; j++) {
         cout << ar[i][j] << "\t";
      }
      cout << endl;
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
   print_v1(a, 5, 5);
   print_v2(a, 5);

   int (*b)[5] = {};
   for (int i = 0; i < 5; i++) {
      b[i] = i;
   }
   print_v2(b, 5);

   return 0;
}