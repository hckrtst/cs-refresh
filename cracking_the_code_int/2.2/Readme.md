#Problem
Write an algorithm to delete the n-th to last node of a singly linked list

#Notes
* singly linked list -> only next pointers
* in order to delete an elem from a SLL we need to keep
the previous pointer


##Constraints and Assumptions


##Examples
1. Normal case 

```
Given
10->12->3->100->24->16->18->99

If we want to del 3rd last element:
10->12->3->100->24->16->18->99
                     ^~~~~ delete the 16
```

2. Empty list
We should bail out gracefully

3. elements less than n
We should bail out gracefully

#Pseudocode
```
p1 = head
p2 = p1
count = n
while(count-- >= 0) {
   p2 = p2->next
}

while(p2->next != NULL) {
   p1 = p1->next;
   p2 = p2->next;
}

delNode(&head, p1, p1->next)

```
#Postmortem
* **Always check for NULL pointers when doing list traversals**
* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper* It's useful to visualize a LL on paper
