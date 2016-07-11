#Problem
Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

#Notes
Key point is that data is in ascending order.
If we insert as-is into a tree we will end up with a linked list.

Try drawing a balanced tree. Ah it looks like midpoints are key.


##Constraints and Assumptions

##Examples

#Pseudocode

#Postmortem
* **Don't rely on the compiler to initialize data**
* toolchains can implement this different resulting in seg faults
* **Always check for the cases of start/end crossing each other**
