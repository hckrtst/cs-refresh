#ifndef __GRAPH__
#define __GRAPH__
#include <vector>

namespace sk{

class Graph {
   // forward declare due to
   // interdependency
   struct Vertex;
   struct Edge;

   struct Vertex {
      int id;
      bool visited;
      std::vector<Edge> edges;
   };

   struct Edge {
      Vertex& to;
      float weight;
   };

   std::vector<Vertex> vertices;

public:
   virtual ~Graph();
   bool addVertex(int id);
   bool removeVertex(int id);
   bool addEdge(int from, int to, float weight);
   bool removeEdge(int from, int to);
};

};
#endif