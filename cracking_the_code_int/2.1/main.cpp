#include <iostream>
#include <unordered_set>

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

   void remove(int d) {
      throw NotImplError();
   }

   void removeAll(int d) {
      throw NotImplError();
   }

   void removeDups(int d) {
       
   }

   void removeAllDupsV1() {
      std::unordered_set<int> vals;
      Node* cur = head;
      Node* prev = cur;
      std::unordered_set<int>::iterator it;
      while(cur != NULL) {
         // if it exists in set then we want to delete
         // the current one
         if (vals.find(cur->data) != vals.end()) {
            deleteNode(&head, prev, cur);
            printf("deleted %d\n", cur->data);
         } else {
            vals.insert(cur->data);\
            printf("Inserted %d\n", cur->data);
         }
         prev = cur;
         cur = cur->next;
      }
   }

   void removeAllDupsV3() {
      Node *cur = head;
      Node *prev = cur;
      while (cur != NULL) {
         Node *tmp = head;
         while (tmp != cur) {
            if (tmp->data == cur->data) {
               deleteNode(&head, prev, cur);
               break;
            }
            tmp = tmp->next;
         }
         prev = cur;
         cur = cur->next;
      }
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
   list.insert(5);

   printf("\n\nTest V1\n\n");
   list.dump();
   list.removeAllDupsV1();
   list.dump();
   

   printf("\n\nTest V3\n\n");
   list.insert(5);
   list.insert(20);
   list.insert(120);
   list.insert(2220);
   list.insert(13);

   list.dump();
   list.removeAllDupsV3();
   list.dump();
   list.purge();
   //list.removeAll(20);
   return 0;
} 
