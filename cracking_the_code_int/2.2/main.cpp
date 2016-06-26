#include <iostream>
using namespace std;

namespace sk {

class List {
   
   class NotImplError {};

   class Node {
      friend class List;
      Node* next;
      int data;
      //Disallow empty constructor
      //as node must be provided
      //with parameters
      Node() = delete;
      Node(int data, Node* _next = NULL):data(data),
         next(_next) {
         this->next = _next;   
         printf("data = %d, next = 0x%x\n", this->data, this->next);
      }
      // Supress the copy ctor
      // Bad joojoo if we shallow copy a 
      // node
      Node(const Node& that) = delete;
      
      /*friend std::ostream&
         operator<<(std::ostream& out, const Node& rv) {
         out << " Data=" << rv.data << " next=" 
            << rv.next
            << std::endl;         
      }*/

      static void printNode(Node* self) {
         printf("data = %d, next = 0x%x\n", self->data, self->next);
      }
      
      void operator delete(void *ptr) {
         std::cout << "deleting..." << std::endl;
      }
   };

   Node *head = NULL;
   void deleteNode(Node** head, Node* prev, Node *cur) {
      //first node is special case
      //since we should update the head
      if (cur == *head) {
         *head = cur->next;
      } else {
         prev->next = cur->next;
      }
      delete cur;
   }

public:

   /* Need to revisit this and see if operator overloading
    * can be used
   //overload <<
   friend std::ostream&
      operator<<(std::ostream& out, const List& rv);
   */
   //overload delete
   void insert(int data) {
      printf("Insert %d\n", data);
      if (head == NULL) {
         head = new Node(data);
      } else {
         //insert at head and update head
         Node *tmp = new Node(data, head);
         head = tmp;
      }
   }

   void dump() {
      Node* n = head;
      printf("******* dump ******\n");
      while(n != NULL) {
         Node::printNode(n); 
         n = n->next;
      }
      printf("*******************\n");
      //std::cout << std::endl;
   }

   void purge() {
      Node* n = head;
      while(n != NULL) {
         printf("Deleting ");
         Node::printNode(n); 
         Node *tmp = n;
         n = n->next;
         delete tmp;
      }

   }

   void remNthToLast(int n) {
      if ((head == NULL) or (n < 0)) {
         cout << "Empty list or bad value of n!" << endl;
         return;
      }

      Node* p1 = head;
      Node* p2 = p1;
      
      while((n >= 0) && (p2->next != NULL)) {
         p2 = p2->next;
         n--;
      }

      if (n > 0) {
         cout << "N too large" << endl;
         return;
      }

      while (p2->next != NULL) {
         p2 = p2->next;
         p1 = p1->next;
      }

      deleteNode(&head, p1, p1->next);

   }
   
};

/*   std::ostream&
      operator<<(std::ostream& out, const List& rv) {
         Node* n = rv.head;
         while (n != NULL) {
            out << "Data: " << n->data  << "Next= " << n->next
               << std::endl;
            n = n->next;
         }
       return out;
   }
*/

};

int main() {
   sk::List list;
   list.insert(20);
   list.insert(5);
   list.insert(13);
   list.insert(11);
   list.insert(50);

   list.dump();

   list.remNthToLast(3);
   list.remNthToLast(9);

   list.dump();
   list.purge();
   //list.removeAll(20);
   return 0;
} 
