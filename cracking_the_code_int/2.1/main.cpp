#include <iostream>

namespace sk {

class List {
   
   class Node {
      Node* next;
      int data;
      Node() {}
   public:
      Node(int data):data(data) {
      }
      // Supress the copy ctor
      // Bad joojoo if we shallow copy a 
      // node
      Node(const Node& that) = delete; 
            
   };
};

};

int main() {
   
   sk::List list;
   return 0;
} 
