#Problem
How would you design a stack which, in addition to push and pop, also has a function
min which returns the minimum element? Push, pop and min should all operate in
O(1) time.

#Notes


##Constraints and Assumptions
* min function should have time of O(1)
* No constraints on space complexity

##Examples

#Pseudocode

namespace sk {
   class MyStack {
      stack data_stack;
      stack min_stack;
      int minv = MAX_INT;

      void push(data) {
         data_stack.push(data)
         min_stack.push(min(data, minv))
      }

      int pop() {
         if
      }
   }

}

#Postmortem
* The proposed solution is book extends Stack, but **prefer Composition over inheritance**
instead.


