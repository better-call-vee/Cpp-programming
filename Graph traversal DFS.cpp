/**
Steps are the same as BFS. DFS(Depth First Search). there are two steps:
    1. Select a node.
    2. Explore a node.

Suppose a graph:

    6     7       3   4
    \    /        |  /
     \  /         | /
      \/          |/
      1-----------2------5

    BFS: 1,2,6,7,3,4,5.

In DFS, we will select a node and then we will explore. If we get a node unvisited,
we will go there and the previous selected node will be paused.
Then we go that unvisited node and select that, mark that visited and explore
while searching for an unvisited node. and go on.

TO SIMULATE THE GRAPH ABOVE:
Selecting 1, printed -> 1.
Exploring 1, got 2. 2 is unvisited. 1's exploration paused. going to 2.

Selecting 2, printed -> 1, 2.
Exploring 2, got 1, but 1 is visited. So, moving on. Got 3, 3 is unvisited.
2's exploration paused. Moving to 3.

Selected 3, printed -> 1, 2, 3.
3 has only adjacent node 2 which is also visited. So, getting back from 3 to 2.
and done with 3. From 2, we got another two unvisited nodes: 4 and 5.

And this same process goes on: printed -> 1,2,3,4,5.
done with 2. back to 1 and same process goes on for 1.
printed -> 1,2,3,4,5,6,7.


For DFS, we go how deep we can go and for BFS, we go level wise.

The standard implementation of depth-first search (DFS) algorithm uses a "STACK"
data structure to keep track of the vertices that have been visited but not yet
explored.

We go to each node only once for DFS traversal, so for that the time complexity
is O(v)
And every edge is selected & checked twice, suppose, for 1--2 in the graph,
for 2, it's checked once with visited array, for 1 also.
so for that O(2E)
overall, O(V+E)
**/

