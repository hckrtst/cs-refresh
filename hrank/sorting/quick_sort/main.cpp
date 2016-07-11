#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;

//private
static int partition(int * ar, int sz, int first, int last);
static void quick_sort_r(int *ar, int sz, int first, int last);
static void swap(int *a, int *b);
static void show(int* ar, int sz);

// public
void quick_sort(int *ar, int sz);

// The core of the algorithm lives in the
// partitioning
int partition(int * ar, int sz, int first, int last) {
   // Use first element as pivot
   int pivot_val = ar[first];
   printf("pivot value = %d\n", pivot_val) ;
   show(ar, sz);

   int left = first + 1;
   int right = last;
   while (true) {
      // advance left if value already
      // smaller than pivot
      while ((left <= right) &&
                  (ar[left] <= pivot_val))
         left = left + 1;
      // decrement right right if value
      // already larger than pivot
      while ((right >= left) &&
                  (ar[right] >= pivot_val))
         right = right - 1;

      // once right has crossed over left
      // or vice versa then we can stop
      // and swap with pivot and return
      // the partition point
      if (left > right) break;

      // else we continue swapping left and right
      // values so they are on the correct side of the
      // future partition
      swap(&ar[left], &ar[right]);
      printf("swapped %d and %d\n", ar[left], ar[right]);
      show(ar, sz);
   }

   // finally swapt the pivot in the correct position
   // and let caller know this position
   swap(&ar[first], &ar[right]);
   printf("positioned pivot\n");
   show(ar, sz);
   return right;
}

void quick_sort(int * ar, int sz) {
   if (ar == nullptr) return;
   //int num_elems = sizeof(ar)/sizeof(ar[0]);
   quick_sort_r(ar, sz, 0, sz - 1);
}

void quick_sort_r(int *ar, int sz, int first, int last) {
   if (first < last) {
      // Split the current array
      int partition_point = partition(ar, sz, first, last);
      // Sort the halves
      quick_sort_r(ar, sz, first, partition_point - 1);
      quick_sort_r(ar, sz, partition_point + 1, last);
   }
}

void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

void show(int *ar, int sz) {
   printf("[");
   for (int i = 0; i < sz; i++) {
      printf("%d,", ar[i]);
   }
   printf("\b]\n");
}

int main() {

   //int a[] = {23, 6, 45, 21, 8, 9, 12};
   int sz;
   cout <<"Size of array? ";
   cin >> sz;
   cout << "Space separated values? ";
   // Note: Apple's clang does not like this initialization :'(
   //int a[sz] = {};
   int a[sz];
   for (int i = 0; i < sz; i++) {
      cin >> a[i];
   }
   if (sz == 1) {
      cout << a[0] << std::endl;
   } else {
      quick_sort(a, sizeof(a)/sizeof(a[0]));
   }
   return 0;
}