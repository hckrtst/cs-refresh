#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
   sk::Graph g;
   g.addVertex(1);
   g.addVertex(2);
   g.addVertex(3);
   g.addVertex(4);
   g.addVertex(5);
   g.addVertex(6);
   g.addVertex(7);

   g.addEdge(1, 2, 3.14);
   g.addEdge(2, 3, 45);
   g.addEdge(2, 4, 13.23);
   g.addEdge(4, 2, 3.11);
   g.addEdge(4, 5, 8.00);
   g.addEdge(4, 6, 0.34);
   g.addEdge(4, 7, 0.78);
   g.addEdge(7, 2, 99);

   g.isRoute(2, 7);
   g.isRoute(4,10);
   g.isRoute(7,5);
   g.isRoute(7,1);
   return 0;
}