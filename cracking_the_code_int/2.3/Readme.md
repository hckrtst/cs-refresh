#Problem
Given a pointer in the middle of a singly linked list (head is not provided)
```
a->b->c->d->e

```
Make the linked list look like this
```
a->b->d->e
```

#Notes


##Constraints and Assumptions
Head is not provided

##Examples

#Pseudocode
```
void sneakyRem(Node* n) {
   // check error case first
   if ((n == NULL) || (n->next == NULL))
      return;
   while(n->next != NULL) {
      n->data = n->next->data;
      n = n->next;
   }
   delete n;
}
```

#Postmortem
* It's good to check the failure cases first, otherwise we can
end up with a crash on the last delete
