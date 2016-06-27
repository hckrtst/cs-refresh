#Problem
How to use a single array to implement three stacks

#Notes
A stack involves two basic operations: push and pop.
An array is a fixed chunk of memory.
We know the size and start/end of the array.


##Constraints and Assumptions

##Examples

array of size 20

alloc 0-5 for first stack
alloc 6-11 for second stack
alloc 12 - 19 for thrid stack

int push(data) {
   if ((sp + 1) > stack_max) {
      return -1 // out of mem
   }
   arr[++sp] = data;
}

int pop() {
   if ((sp - 1) < stack_min) return -1;
   return arr[sp--];
}

#Pseudocode

#Postmortem
