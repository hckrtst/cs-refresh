#Problem
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one.

#Notes

##Constraints and Assumptions
* Let's assume a BST and implement a simple insertion and traversal. Although BST is not necessary but building
tree might be a bit easier that way

##Examples


#Pseudocode
```
struct node {
   node *left, *right;
   int data;
}

is_balanced(node * root) {
   if (get_max_depth(root) - get_min_depth(root)) <= 1 then return true
   return false
}

```

#Postmortem

