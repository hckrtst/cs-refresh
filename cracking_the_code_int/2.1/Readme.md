#Problem
Remove duplicates from an unsorted linked list.

#Notes

##Constraints and Assumptions
* If we have an additional constraint that no extra buffers may be used then how do we approach this?

##Examples

#Pseudocode
```
// version using set --> O(n)
fn removeDupsV1(head)
   cur = head
   while (cur is not NULL)
      if set.find(cur->data)
         if cur == head
            deleteNode(head, head, cur)
         else 
            deleteNode(head, prev, cur)
         endif
      else
         set.add(cur->data)
      endif
      prev = cur
      cur=cur->next      
   endwhile
endfn

//version without any additional data structure --> O(n^2)?
void removeDupsV2(head) {
   cur = head
   while (cur is not NULL) {
      p1 = cur
      p2 = p1->next
      while(p2 is not NULL) {
         //delete node
         if (cur->data == p2->data) {
            deleteNode(head, p1, p2) 
         } else {
            p1 = p2
         }
         p2 = p2->next         
      }
      cur = cur->next
   }   
}

//similar to solution for this in book
void removeDupsV3(head) {
   cur = head
   while (cur != NULL) {
      if (head != cur) {
         if (seenEarlier(cur))) {
            // then delete current one
            deleteNode(head, prev, cur)
         }
      }
      prev = cur
      cur = cur->next
   }
}

//Assuming a class/struct called Node
fn insertNodeAtHead(Node ptr head, data)
   elem = allocate(data)
   tmp = head
   head = elem
   elem->next = tmp
endfn

fn deleteNode(head, prev, elem)
   if head == prev
      head = elem->next
   else   
      prev->next = elem->next
   endif

   delete elem
endfn

```
#Postmortem

* Recall that `struct`s are Plain Old Datatypes (POD's) until you give it a constructor
* For crying out loud...**ALWAYS INITIALIZE pointers to NULL!!!!**
* When deleting node *remember this*
```c
prev->next = cur->next
```
```


