#CheatSheet

# Containers

## vector
* Like array, contiguous chunk of memory
* fast access, insert at end O(1), but insert in middle inefficient
* resizing is not efficient as new chuink of memory allocated and contents copied
* beware of **iterator invalidation** when insertion causes resize (see TICPP v2 pg.463)
* Most eficient if you :
   * `reserve()` the correct amount of storage upfront to avoid reallocations
   *  you only add/remove elements front/back

## deque (pronounced "deck")
* O(1) for insert/delete at either end
* accessing elements O(?)
* No issues of reallocation like vector
* Each element stored in a separate chunk

> Note
> ---
> Using `[]` is intuitive but using `at()` allows you to handle exception as it does bounds checking

### Resource
* http://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container

## list
* implemented as a doubly linked list
* designed for rapid insertion and deletion from anywhere
* slow when randomly accessing elements of container
* best used when traversing sequence in order
* some memory overhead of forward and backward pointer
* `merge()` can be used to build a bigger list but is typically effective if both lists sorted (?)

## priority queue
* implemented as a [heap](http://interactivepython.org/runestone/static/pythonds/Trees/PriorityQueueswithBinaryHeaps.html)
* A curious C-based implementation [here](http://robin-thomas.github.io/max-heap/). Although beware of the cowboy pointer arithmetic
and lack of allocation failure checks.

## map
* Usually implemented as red-black trees

# Data Structures
## Tree
* For non-recursive trversals can use a stack to keep track
## Stack
TODO
## Heap
TODO
## Trie
TODO

### Resource
* [Cheatsheet on selecting STL containers](http://stackoverflow.com/a/471461)
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

# OOP Concepts

## Mixins
Units of functionality are created in a class and "mixed in" with other classes.

```python
# This class now includes the ability to fork threads per request
class ThreadingTCPServer(ThreadingMixIn, TCPServer):
  pass
```


##References
* [examples](pie/Concurrency)
* http://homes.cs.washington.edu/~arvind/cs422/lectureNotes/deadlock-6.pdf
* https://www.cs.princeton.edu/courses/archive/fall11/cos318/lectures/L9_Deadlocks.pdf

