#CheatSheet

# Data Structures
## Tree
* For non-recursive trversals can use a stack to keep track
## Stack
TODO
## Heap
TODO
## Trie
TODO

##Graph
* Edges can be represented by adjacency list or matrix
   * Matix is O(1) for access but wastes space since mostly 0's
   * A list is more space efficient but slower to search

#Algorithms

##Sorting

###Bucket sort

###Selection sort

###Merge sort

###Quick sort

###Bubble sort
Naïve way of sorting.
Worst case: O(n^2)
```
bubble_sort(vector<T> data) {
   swapped = false
   do {
      for (i = 1; i < i.data; i++) {
         if (data[i] < data[i-1]) {
            swap(i-1, i)
            swapped = true
         }
      }
   }
   } while(swapped)
}
```

##Searching

##Concurrency

##Livelock

##Deadlock

##Starvation

##Dining Philosophers
* Ad hoc
Let first philosopher try to pick up the forks in the opposite order to break
the cycle
* Chandy Misra
[TODO]
* Waiter approach
[TODO]

# C++ template programming


##References
* [examples](pie/Concurrency)
* http://homes.cs.washington.edu/~arvind/cs422/lectureNotes/deadlock-6.pdf
* https://www.cs.princeton.edu/courses/archive/fall11/cos318/lectures/L9_Deadlocks.pdf
