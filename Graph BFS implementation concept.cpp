/**
Writing the steps before writing the code is called pseudocode.
Pseudocode of BFS:
==================

Input -> Connected Graph and a "source"
Output -> Traverse all nodes and print the traversal order

BFS(graph, source):
-Initiate an array called "visited" and an empty queue "q"
-mark visited[source] = 1 and q.push(source)
-while the queue is not empty:
    -head = q.front()
    -q.pop()
    -print the node "head"
    -for all adjacent nodes of "head":
        -if visited[adj_node] == 0:
            -visited[adj_node] = 1 and q.push(adj_node)
**/

/**
TIME COMPLEXITY
10th & 11th line => O(1)
Now we have to calculate complexity for the while loop.
Here, suppose the number of nodes are V and the number of edges are E.
so, 13, 14th line will easily take O(1), but we will run the loop total V times for
V nodes. so, it will eventually become O(V).

##a particular edge of a graph won't be used more than twice.
  -> 1----2, here this edge will be used maximum twice no matter how many adjacent
     new nodes come here.

So, for the second loop here(16 to 18th line):
here, the complexity will be O(2E) according to the corollary stated just above.
And the overall time complexity will be O(V+E)
though, for complete graph there will be a complexity of O(E^2)

SPACE COMPLEXITY:
the queue's max length can be equivalent to V. one node can have a V no. of adjacent
nodes. So, space complexity O(V).

**/
