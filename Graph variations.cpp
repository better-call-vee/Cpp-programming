/**
Weighted vs Unweighted

        A----B
            /\
           /  \
          /    \
         /      \
        C--------D
This is an unweighted graph

If I indicate the distances between them, it will be a weighted graph
          5
        A----B
            /\
           /  \
         7/    \7  This is a weighted graph
         /  10  \
        C--------D
**/

/**
Directed vs Undirected

        A----B
            /\     Here, if we can go from A to B & then again can return from
           /  \    B to A, that's undirected/bidirectional graph.(goes both ways)
          /    \
         /      \
        C--------D


        A--->B
            /\   Here, A can only go to B but B can't go to A. the route is a
           /  \  Directed edge and it's a directed graph where the edges are
          /    \ directed. well for the A and B, there can be another edge
        \/_     \directing from A to B.
        C------->D

**/

/**
Bipartite Graph:
     +------+       +------+
     |  A   |-------|  1   |
     +------+       +------+
     +------+       +------+
     |  B   |-------|  2   |
     +------+       +------+
     +------+       +------+
     |  C   |-------|  3   |
     +------+       +------+

     There will be two partisans between two sides. The nodes of each side
     will not be connected in between them. but, they will be connected with
     other part's nodes. Here, A can be connected with 2. But A can't be
     connected with B.
**/

/**
 1 -- 2
  \  /
   \/
   03
It's a complete node where each and every node is connected with each other.
There can be more examples of complete node.
A---B, it's also a complete node with only a single edge.
A, it's also a complete node without an edge.

To calculate the number of edges in a complete graph with n nodes, you need to
know that every node is connected to every other node. Therefore, for each of
the n nodes, there are n - 1 edges connecting it to the other nodes (since it
is not connected to itself).

However, since we count each edge twice (once for each of the two nodes it
connects), we need to divide the total count by 2 to get the total number of
edges in the complete graph. The formula to calculate the number of edges in
a complete graph with n nodes is:

(number of edges = n * (n - 1) / 2)
**/

/**
Tree is an acyclic graph.
FOR TREE, we can't use a path twice
        A---E It's an unrooted tree. if E didn't exist here, it will be a rooted
      /   \   tree. or we can make E the root to make it rooted.
     B     C---D
    /       \
   G         F
if we go like this G->B->A->E->A->C->D. we can't go like this
but, G->B->A->C->D. can go like this only.
       1--2--4
          |
          3--5
It's an unrooted tree also.

**/


/**
DAG(Directed Acyclic Graph)
    A → B → D
    +   +            + is being considered as a down array
      C


**/


When there will be more than one edge between two nodes that is called multi
edge. ///BUT THEY HAVE TO BE IN THE SAME DIRECTION!!

/**
A simple graph is an undirected graph with no loops or multiple edges.
Here are some properties of a simple graph:

A simple graph has no self-loops, which means that a vertex cannot have an
edge connecting it to itself.

A simple graph has no parallel edges, which means that there cannot be multiple
edges connecting the same pair of vertices.

A simple graph can be connected or disconnected. A connected graph is a graph
in which there is a path between any two vertices. A disconnected graph is a
graph in which there are one or more vertices that are not connected to the
rest of the graph.

The degree of a vertex in a simple graph is the number of edges incident to
it. In a simple graph, the degree of a vertex can range from 0 to the total
number of vertices minus one.
      A -- B -- C
      |    |    |
      D -- E -- F
**/


/**
A pseudograph is a type of graph in which loops and multiple edges between
the same pair of vertices are allowed.

In a regular graph, there is only one edge between two vertices, and a vertex
cannot be connected to itself with a loop. However, in a pseudograph, it is
possible for a vertex to be connected to itself with a loop and for there to
be multiple edges between the same pair of vertices.

Pseudographs are often used in situations where it is useful to represent
multiple connections between two vertices or to allow a vertex to have a
self-loop. For example, in a transportation network, a pseudograph could
be used to represent a roundabout, where a vehicle could enter and exit at
multiple points.

It's worth noting that some graph theory textbooks and authors do not consider
pseudographs to be true graphs, as they violate some of the usual assumptions
made about graphs. However, they are still a useful tool in certain contexts
and are often studied in their own right.
**/
