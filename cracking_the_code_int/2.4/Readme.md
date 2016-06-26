#Problem
You have two numbers represented by a linked list, where each node contains a sin-
gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of

the list. Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE

Input: (3 -> 1 -> 5) + (5 -> 9 -> 3)

Output: 8 -> 0 -> 9


#Notes

##Constraints and Assumptions
* We can convert linkd list to number and vice versa
* Assume we have defined a linked list and Node classes

##Examples

#Pseudocode
```
int listToNum(List& list) {
   int ret = 0;
   cur = list.head
   int e = 0;
   while (cur != NULL) {
      ret += (cur->data)*pow(10, e++);
      cur = cur->next
   }
   return ret;
}

List& numToList(int num) {
   List *list = new List();
   int rem = 0;
   while (num > 0) {
      rem = num % 10;
      list->insertAtHead(rem);
      num /= 10;
   }
   return *list;
}

main() {
num1 = List::listToNum(list1)
num2 = List::listToNum(list2)

sum = num1 + num2

list3 = numToList(sum)
}

```

#Postmortem

