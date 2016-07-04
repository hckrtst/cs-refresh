#include <iostream>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;


namespace sk {

struct node {
   node* left, *right;
   int data;
};

class Tree{
   node *root;
   //void traverse(node *r);
   int get_max_depth(node *n);
   int get_min_depth(node *n);
   node *alloc_node(int data);
   void print_inorder(node *r);
   void clear_postorder(node *r);
   node *insert_r(node* r, int data);
public:
   void insert(int data) {
      root = insert_r(root, data);
   }
   void print() {
      printf("\nPrinting inorder tree\n");
      print_inorder(root);
      printf("\n");
   }
   void clear() {
      clear_postorder(root);
      root = nullptr;

   }
   bool is_balanced() {
      if ((get_max_depth(root) - get_min_depth(root)) <= 1) return true;
      return false;
   }

};//end Tree

node* Tree::alloc_node(int data) {
   node *n = new node;
   n->data = data;
   n->left = n->right = nullptr;
   return n;
}

node *Tree::insert_r(node* r, int data) {
   if (r == nullptr) {
      r = alloc_node(data);
      return r;
   }

   if (data < r->data) {
      r->left = insert_r(r->left, data);
   } else {
      r->right = insert_r(r->right, data);
   }
    return r;
}

// Use post order traversal
void Tree::clear_postorder(node *r) {
   if (r == nullptr) return;

   if (r->left != nullptr) {
      clear_postorder(r->left);
   }
   if (r->right != nullptr) {
      clear_postorder(r->right);
   }
   cout << "deleting " << r->data << endl;
   delete r;
   //r = nullptr;
}

void Tree::print_inorder(node *r) {
   if (r == nullptr) return;

   if (r->left) print_inorder(r->left);
   printf(" %d ", r->data);
   if (r->right) print_inorder(r->right);

}

// void Tree::traverse(node* r) {
//    if (r == nullptr) return;
//    traverse(r->left);

// }

int Tree::get_min_depth(node *n) {
   if (n == nullptr) return 0;
   return (1 + std::min(get_min_depth(n->left), get_min_depth(n->right)));
}

int Tree::get_max_depth(node *n) {
   if (n == nullptr) return 0;
   return (1 + std::max(get_max_depth(n->left), get_max_depth(n->right)));
}

};// end namespace


void run() {
   sk::Tree tree;
   std::string cmd;
   cout << "Tree v0.1 \n Type help to get started" << endl;
   while(cin) {
      cout << "main>>";
      cin >> cmd;
      if (cmd == "help") {
         printf("Commands: ins, isbal, bye, show, clr, help\n");
      } else if (cmd == "bye") {
         break;
      } else if (cmd == "ins") {
         // quick demo of input validation
         // ** FIXME ** - CTRL + D at insert
         // makes the program go bezerk
         while(cin) {
            int val;
            cout << "insert>>";
            cin >> val;
            if (val == EOF) {
               cout << "exit insert" << endl;
               break;
            }
            if ((cin.fail()) || (val < -1)) {
               cout << "\nbad input...try again\n";
               cin.clear();
               cin.ignore(1000, '\n');
               continue;
            }
            cout << "-->" << val << endl;
            tree.insert(val);

         }
         cout << endl;
      } else if (cmd == "show") {
         tree.print();
      } else if (cmd == "clr") {
         tree.clear();
      } else if (cmd == "isbal") {
         if (tree.is_balanced()) {
            cout << "balanced" << endl;
         } else {
            cout << "not balanced" << endl;
         }
      }
   }
}
int main() {
   /*int inp = 0;
   while (cin >> inp) {
      cout << "-->" << inp << endl;
      if (inp == 314) {
         cout << "Bye!" << endl;
         break;
      }
   }*/
   run();

   return 0;
}