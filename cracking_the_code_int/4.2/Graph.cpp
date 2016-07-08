#include "Graph.h"
#include <iostream>
#include <queue>

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
               return true;
               break;
            }
         it++;
         }
      }
      return false;
   }

   bool Graph::doesRouteExist(Vertex& src, Vertex& dest) {

      // clear all visited
      std::vector<Vertex>::iterator it = vertices.begin();
      while (it != vertices.end()) {
         it->visited = false;
         it++;
      }
      // Do depth first search

      // Track elements via a queue
      std::queue<Vertex*> q;
      q.push(&src);

      // Get list of neighbors of src

      while(!q.empty()) {
         Vertex *v = q.front();
         q.pop();
         cout << "Visiting " << v->id << endl;
         v->visited = true;
         for (auto e: v->edges) {
            if (!e.to.visited) {
               if (e.to.id == dest.id) {
                  cout << "Route exists from " << src.id << " to " << dest.id << endl;
                  return true;
               } else {
                  cout << "push " << e.to.id << endl;
                  q.push(&(e.to));
               }
            }
         }
      }
      cout << "No Route from " << src.id << " to " << dest.id << endl;
      return false;

   }

   bool Graph::isRoute(int from, int to) {
      // get the src node
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

         // get the dest node
         it = vertices.begin();
         while (it != vertices.end()) {
            if (it->id == to) {
               cout << "Found to = " << to << endl;
               return doesRouteExist(src, *it);
               //break;
            }
         it++;
         }
      }
      cout << "Invalid vertex found" << endl;
      return false;
   }

   Graph::~Graph() {
      // TODO clean up all vertices and edges ?
   }

};