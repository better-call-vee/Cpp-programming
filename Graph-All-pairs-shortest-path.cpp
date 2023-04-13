/*
All pairs shortest path is like I will be asked to represent the shortest path from any node to any 
other node.
          1-----3
         / \
        /   \
       2-----4-----5
Here, if I am asked about 4to5, 2to3 distances we can still do that with single source shortest path.
but, that's not efficient.

Look, among the algorithms we have learned, their complexities are:
BFS -> O(V+E)
Dijkstra -> O(v^2) / O(ElogV)
Bellman Ford -> O(v^3)
If we do this shit with single source shortest path, we have to call these algorithms separately each
and everytime for each source we will get. That will upshot the time complexities to V times multiplied
and which is totally inefficient.

Here comes our savior: Floyd and Warshall
We will use adjacency matrix for this All pair shortest path graph representation.

1                0    1    2
⬇             0  0   ♾️    5
⬇2            1  2    0    ♾️      
⬇             2 ♾️   ♾️   0
0---5--->2
That's how we represent a graph with adjacency matrix.
With this Great Floyd-Warshall algorithm, we can even get the shortest path if the graph has negative
weights and negative cycle!!
if we just ask the shortest path between u and v, matrix[u][v] will give us that
It's so powerful that's why it's a bit grueling algorithm. 

Floyd Warshall is an Incremental Algorithm(builds the answer slow and steady)

        a---7-->b--9-->c
       /               ⬇
   12 /                ⬇3
     ↙                 ⬇
    u---------50------>v 

    Here, if we take the help of a, b, c nodes to reach v from u, it will cost less than direct
    approach from u to v. These a, b, c nodes are called intermediate nodes.
    It's the base of Floyd Warshall algorithm.

*/