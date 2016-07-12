#include <iostream>
using namespace std;
bool binary_search(int *ar, int start, int end, int target);

// Get the first index which matches its value else -1
// REQUIREMENT: array must be sorted in ascending order
int get_index_match(int *ar, int start, int end);

void print_ar(int* ar, int start, int end) {
   printf("[");
   for (int i=start; i <= end; i++) {
      printf("%d,", ar[i]);
   }
   if (start <= end) printf("\b]\n");
   else printf("]\n");
}

// REQUIREMENT: array must be sorted in ascending order
bool binary_search(int *ar, int start, int end, int target) {
   if (ar == nullptr) return false;
   print_ar(ar, start, end);

   if (start <= end) {
      int mid = (start + end)/2;
      if (target < ar[mid]) {
         return binary_search(ar, start, mid-1, target);
      } else if (target > ar[mid]) {
         return binary_search(ar, mid + 1, end, target);
      } else {
         return true;
      }
   }
   return false;
}

int get_index_match(int *ar, int start, int end) {
   if (ar == nullptr) return -1;
   print_ar(ar, start, end);

   if (start <= end) {
      int mid = (start + end)/2;
      if (ar[mid] > mid) {
         // if the value is larger than mid
         // and since all values are unique and ascending
         // the following values can never match the index
         return get_index_match(ar, start, mid-1);
      } else if (ar[mid] < mid) {
         return get_index_match(ar, mid+1, end);
      } else {
         return mid;
      }
   }
   return -1;
}


int main() {
   cout << "\nBasic binary search\n" << endl;
   bool found = false;
   int ar[8] = {2, 5 ,6, 13, 15 ,16, 19, 30};
   int length = sizeof(ar)/sizeof(ar[0]);

   found = binary_search(ar, 0, length - 1, 19);
   cout << "19 exists? " << found << endl;

   found = binary_search(ar, 0, length - 1, -300);
   cout << "-300 exists? " << found << endl;

   cout << "\nIndex match\n" << endl;
   int idx = -1;
   idx = get_index_match(ar, 0, length-1);
   cout << "Found index " << idx << endl;

   int ar2[8] = {-6, 1 ,3, 5, 6, 26, 19, 30};
   idx = get_index_match(ar2, 0, length-1);
   cout << "Found index " << idx << endl;

   return 0;
}