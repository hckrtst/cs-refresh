#Problem
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

#Notes
A graph consists of vertices and edges. An edge also may have an associated cost.
Graph can be directed or undirected. In this example it is known to be directed.

We can define a vertex as:
```
class Vertex {
   int data
   using VecData = pair<Vertex, int>
   vector<VecData> neighbors
}

class Graph {
   unordered_set<Vertex> vertices
}

```
##Constraints and Assumptions

##Examples

#Pseudocode
```


```
#Postmortem

## Recognizing graph problems
* Finding shortest trip between two cities
* best way to route something (water through pipes, data through a network, etc.)
* Little red riding hood is lost in the woods, and can only take certain points out of the forest...

# References
* https://ece.uwaterloo.ca/~cmoreno/ece250/2012-03-26--graphs-implementation.pdf
