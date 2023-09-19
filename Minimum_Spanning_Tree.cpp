/*
Imagine a group of islands in the ocean. Each island is connected to some other islands by bridges,
and each bridge has a cost to build. Your task is to connect all the islands with the minimum total
cost, but you should ensure every island is reachable from every other island. To achieve this,
you would try to find the set of bridges that connect all the islands together with the least
total cost. This set of bridges represents the Minimum Spanning Tree!

In graph theory, a tree is a graph that is connected (there's a path between every pair of vertices)
and has no cycles (closed loops). A spanning tree of a graph is a tree that includes all the
vertices of the graph. When a graph has weights (or costs) associated with each edge, a Minimum
Spanning Tree (MST) is a spanning tree that has the minimum total weight.

N.B__
1)  An MST will have V−1V−1 edges, where VV is the number of vertices in the graph.
2)  The weight of an MST will be less than or equal to the weight of every other spanning tree of
    the graph.
3)  There can be more than one MST for a given graph.


*/

/*
KrusKal's Algorithm:
        C5     C3
    1--------2-----3
    | \C100  |    /
    |  \     |C2 /C20  this is not a MST.
    |    4   |  /
    C6    \C3| /
    |      \ |/
    |________5
    
        5      3
    1------2------3
           |      now this is the blud MST!!!
       4   |      the MST is 13
        \  |2
       3 \ |
           5

we will be given the edges and we will sort them first(according to the edge value)
and then we will go ahead according to DSU concept. We will eradicate the cyclic edges by checking 
the leader of the nodes.

*/