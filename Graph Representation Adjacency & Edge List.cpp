///LINKED LIST/VECTOR
///NO DRAWBACKS AT ALL

/**
     (0)A----B(1)
            /\
           /  \
          /    \
         /      \
     (2)C--------D(3)
Here, It's an undirected unweighted graph. We will just make the list of each
node. The lists will contain the connected nodes of particular nodes where you
can go using only an edge at a time!
Here:
0-->1   2-->1     |     0 => 1
1-->0   2-->3     |     1 => 0,2,3 [lists like this will be represented as vector
1-->2   3-->1     |     2 => 1,3    linked list]
1-->3   3-->2     |     3 => 1,2


    1
 0 ---> 1
  \    ^
 1 \  / 1
    v/
    02
For directed loop, also the same method.
0 => 1, 2
1 =>
2 => 1.
If 0 had multiedges with 2, 0 => 1, 2, 2, 2...
so, it's easier to represent multiedge with adjacency list

If 1 had a self loop then, 1 => 1.



    3
 0 ---> 1     WEIGHTED GRAPH WITH ADJACENCY LIST
  \    ^
 2 \  / 4
    v/
    02

Here:
0 => (1,3), (2,2)
1 =>
2 => (1,4)

**/




///EDGE LIST
/**
edge lists don't have that much use like adjacency list and matrix.

for 5th line's graph. the representation will be like the following:
[0,1], [1,2], [2,3], [1,3].
if they are weighted, the weights will be added with this. suppose,
[0,1]'s weight is 5. [0,1,5].

if they are directed, then also quite the same, suppose 3 is directing to
2 and their weight is 7, so [3,2,7]
**/
















