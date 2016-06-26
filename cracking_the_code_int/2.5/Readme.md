#Problem
Given a circular linked list, implement an algorithm which returns the node at the beginning of the loop.

#Notes
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

##Constraints and Assumptions
* Since no constraints we could use a simple set to keep track of the node values
as we traverese the linked list

##Examples
input: A -> B -> C -> D -> E -> C [the same C as earlier, so we have a cycle]

output: C

#Pseudocode
```
//we have a set of addresses of linked list nodes
set<int> nodes

while (head != NULL) {
   if (nodes.find(head) != nodes.end()) {
      return head
   } else {
      nodes.insert(head)
   }
   head = head->next
}
return NULL

```

If there are constraints of only using pointers and not using additional
data structures then we can use the Flyod algorithm

[TODO] Go through the resource and test the solution.

[Related problem solved here](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/submissions/code/22713135). [TODO] Go through and extend this to find start of cycle.

## Resource
* http://stackoverflow.com/a/6110767/1006334


#Postmortem

