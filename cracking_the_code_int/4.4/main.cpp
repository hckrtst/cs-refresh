#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;

namespace sk {

struct node {
   node* left, *right;
   int data;
};

typedef vector<node*> node_vec;
typedef vector<node_vec> level_vec;

class Tree{
   node *root = nullptr;

   level_vec levelv;
   //level_vec *n1 = new level_vec();

   //void traverse(node *r);
   int get_max_depth(node *n);
   int get_min_depth(node *n);
   node *alloc_node(int data);
   void print_inorder(node *r);
   void clear_postorder(node *r);
   node *insert_r(node* r, int data);
   void insert_bal_r(const int *ar, int start, int end);
public:
   void insert(int data) {
      root = insert_r(root, data);
   }
   void insert_balanced(const int *ar, int length);
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
   int get_height() {
      return get_max_depth(root);
   }
   void build_level_list();

   Tree() {

   }
   ~Tree() {
      clear();
      //delete n1;

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
      cout << "r> data = " << data << endl;
      return r;
   }

   if (data < r->data) {
      cout << "left  " << data << endl;
      r->left = insert_r(r->left, data);
   } else {
      cout << "right  " << data << endl;
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
}

void Tree::print_inorder(node *r) {
   if (r == nullptr) return;
   if (r->left != nullptr) print_inorder(r->left);
   printf(" %d ", r->data);
   if (r->right != nullptr) print_inorder(r->right);
}

void Tree::insert_balanced(const int *ar, int length) {
   insert_bal_r(ar, 0, length - 1);
}

void Tree::build_level_list() {
   if (root == nullptr) return;
   node_vec vec;
   vec.push_back(root);

   while(!vec.empty()) {
      levelv.push_back(vec);
      cout << "list start\n";
      for (auto n: vec) {
         cout << n->data << endl;
      }

      node_vec tmp;
      for (node_vec::iterator it = vec.begin();
           it != vec.end();
           it++) {
         node* n = *it;
         if (n->left) tmp.push_back(n->left);
         if (n->right) tmp.push_back(n->right);
      }
      vec.clear();
      vec = tmp;
      cout << "size of level vector = " << levelv.size() << endl;
   }
}

void Tree::insert_bal_r(const int *ar, int start, int end) {
   if (start == end) {
      // base case
      insert(ar[end]);
      // cout << "base case: inserting " << ar[end] << endl;
   } else {
      // CAUTION!!!! Always check for crossing of boundaries
      if (start < end) {
         // find midpoint
         // int mid = start + (end - start + 1)/2;
         int mid = (start + end)/2;
         cout << "mid = " << mid << endl;
         // insert midpoint first
         insert(ar[mid]);
         // cout << "mid case: inserting " << ar[mid] << endl;
         insert_bal_r(ar, start, mid - 1);
         insert_bal_r(ar, mid + 1, end);
      }
   }
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

int main() {
   sk::Tree tree;

   int ar[11] = {1,2,4,4,5,6,7,8,9, 10, 11};
   int length = sizeof(ar)/sizeof(ar[0]);
   tree.insert_balanced(ar, length);
   tree.print();
   cout << "Height = " << tree.get_height() << endl;
   tree.build_level_list();

   return 0;
}