#include "Graph.h"
#include <iostream>
using std::cout;
using std::endl;

namespace sk {
   bool Graph::addVertex(int id) {
      // if id already exists then don't add
      std::vector<Vertex>::iterator it = vertices.begin();
      while (it != vertices.end()) {
         if (it->id == id) {
            cout << "Vertex already exists" << endl;
            return false;
         }
         it++;
      }

      Vertex v;
      v.id = id;
      v.visited = false;
      vertices.push_back(v);

      cout << "Inserted " << id << endl;

      return true;
   }

   bool Graph::addEdge(int from, int to, float weight) {
      // TODO check if vertices exist

      std::vector<Vertex>::iterator it = vertices.begin();
      while (it != vertices.end()) {
         if (it->id == from) {
            cout << "Found from = " << from << endl;
            break;
         }
         it++;
      }
      if (it != vertices.end()) {
         Vertex &src = *it;

         it = vertices.begin();
         while (it != vertices.end()) {
            if (it->id == to) {
               cout << "Found to = " << to << endl;
               Edge e = {*it, weight};
               src.edges.push_back(e);
               break;
            }
         it++;
         }
      }





      return true;
   }

   Graph::~Graph() {
      // TODO clean up all vertices and edges ?
   }

};