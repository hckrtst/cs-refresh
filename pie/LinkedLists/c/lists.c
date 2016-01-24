#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
}node_t;

static node_t *make_list(int data)
{
   node_t *n = NULL;
   n = (node_t*) calloc(1, sizeof(node_t));
   if (n != NULL) {
      n->data = data;
      n->next = NULL;
   }
   return n;
}

static int length(const node_t* head)
{
   const node_t* cur = head;
   int l = 0;
   while(cur != NULL) {
      l++;
      cur = cur->next;
   }
   return l;
}

static void push(node_t **head, int data)
{
   if (*head == NULL) return;
   
   node_t *n = make_list(data);
   if (n == NULL) return;
   
   n->next = *head;

   *head = n;
}

static int find(const node_t * head, int data)
{

   while((head != NULL) &&  (head->data != data)) {
      head = head->next;
   }
   return (head != NULL);
}

int main()
{
   node_t *head;
   head = make_list(3);
   push(&head, -45);
   push(&head, 34);
   push(&head, 99);
   printf("Length  = %d\n", length(head));
  
   // cause seg fault if no null check in find
   // printf("Find %d = %d\n", 9, find(head, 9));
   printf("Find %d = %d\n", 9, find(head, 9));
   printf("Find %d = %d\n", 99, find(head, 99));


}

