#include <iostream>
#include <cmath>
//using namespace std;

namespace mytest {
class List {
   class Node {
      friend class List;
      int data;
      Node* next;
      
      // cannot copy
      Node(const Node&) = delete;
      Node() = delete;
      Node(int data, Node* next = NULL):data(data),
         next(next) {
      }
      static void print(Node &n) {
         printf("data = %d, next = %d\n", n.data, n.next); 
      }
   };
   
   Node* head = NULL;

public:
   void insertAtHead(int data) {
      Node *n = new Node(data, head);
      head = n; 
   }

   void append(int data) {
      Node * n = new Node(data);
      Node *cur = head;
      if (head == NULL) {
         head = n;
         return;
      }
      while ((cur->next) != NULL) {
         cur = cur->next;
      }
      cur->next = n;
   }

   Node *getHead() {
      return head;
   }
   
   int listToNum() {
      int rv = 0;
      Node * cur = head;
      int e = 0;
      while (cur != NULL) {
         rv += (cur->data) * int(std::pow(10.0, e++));
         cur = cur->next;
      }
      return rv;
   }

   void genListFromInt(int num) {
      int rem = 0;
      while(num > 0) {
         rem = num % 10;
         append(rem);
         num /= 10;
      }
   }

   void dump() {
      Node * cur = head;
      while (cur != NULL) {
         printf("data = %d,next = 0x%x ", cur->data, cur->next);
         cur = cur->next;
      }
      printf("\n");
   }
};

};
int main() {
   mytest::List list1;
   list1.genListFromInt(80009);
   list1.dump(); 

   mytest::List list2;
   list2.genListFromInt(3456);
   list2.dump();

   int num1 = list1.listToNum();
   int num2 = list2.listToNum();
   int sum = num1 + num2;
      
   printf("num1 = %d, num2 = %d, sum = %d\n", num1, num2, sum);
   
   mytest::List list3;
   list3.genListFromInt(sum);
   list3.dump();

   return 0;
} 
