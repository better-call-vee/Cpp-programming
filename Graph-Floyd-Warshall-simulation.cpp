
           1
         ↗  ↘
     2 ↗      ↘ 5
     ↗          ↘
    u----50------>v
d[u][v] = 50
d[u][1] = 2
d[1][v] = 5
after using the intermediate node:
d[u][v] = d[u][1] + d[1][v]

=>[d[u][v] = d[u][k] + d[k][v]]<=

        |   1   |   u   |   v   |                 |   1   |   u   |   v   |
------- | ----- | ----- | ----- |         ------- | ----- | ----- | ----- |
    1   |   0   |   ∞   |   5   |            1    |   0   |   ∞   |   5   |
------- | ----- | ----- | ----- |         ------- | ----- | ----- | ----- |
    u   |   2   |   0   |  50   |    =>      u    |   2   |   0   |   7   |
------- | ----- | ----- | ----- |         ------- | ----- | ----- | ----- |
    v   |   ∞   |   ∞   |   0   |            v    |   ∞   |   ∞   |   0   |
------- | ----- | ----- | ----- |         ------- | ----- | ----- | ----- |



Now, let's see the same method for multiple intermediate nodes:
                5
        1--------------->2
       ↗                 |
   2 ↗                   | 3
   ↗                     ⬇
  u----------50--------->v   

    | 1 | 2 | u | v |       | 1 | 2 | u | v |       | 1 | 2 | u | v |
----|---|---|---|---|   ----|---|---|---|---|   ----|---|---|---|---|
  1 | 0 | 5 | ∞ | ∞ |     1 | 0 | 5 | ∞ | ∞ |     1 | 0 | 5 | ∞ | 8 |
----|---|---|---|---|   ----|---|---|---|---|   ----|---|---|---|---|
  2 | ∞ | 0 | ∞ | 3 |     2 | ∞ | 0 | ∞ | 3 |     2 | ∞ | 0 | ∞ | 3 |
----|---|---|---|---|   ----|---|---|---|---|   ----|---|---|---|---|
  u | 2 | ∞ | 0 | 50|     u | 2 | 7 | 0 | 50|     u | 2 | 7 | 0 | 10|
----|---|---|---|---|   ----|---|---|---|---|   ----|---|---|---|---|
  v | ∞ | ∞ | ∞ | 0 |     v | ∞ | ∞ | ∞ | 0 |     v | ∞ | ∞ | ∞ | 0 |
----|---|---|---|---|   ----|---|---|---|---|   ----|---|---|---|---|
this is the distance     this is the distance    this is the distance
0 matrix. D⁰             1 matrix. D¹            2 matrix. D² 

when only node 1 is considered as the intermediate node.
D¹ => d[u][2] = d[u][1] + d[1][2]        13th line's formula
   => d[u][2] = 2 + 5 = 7                where k is 1, v is 2.
______________________________________________________________________
when multiple nodes(1 and 2) are considered as the intermediate nodes.
D² => d[1][v] = d[1][2] + d[2][v]        where u is 1, k is 2.
   => d[1][v] = 5 + 3 = 8

   => d[u][v] = d[u][2] + d[2][v]        where k is 2.
   => d[u][v] = 7 + 3 = 10


PSEUDOCODE
Time complexity => O(V³)
Space complexity => O(V²)

Input -> A weighted graph as an adjacency matrix
Output -> All pair shortest distance

- Create a distance_matrix "d" where d[i][j] = x where there is a direct edge from node "i" to node "j"
  and the cost is "x"  -> {TC => O(V²)}
- for all node "i" d[i][i] = 0     diagonal = 0. means no self loop
- for all nodes "i" & "j" where there isn't any direct edge from "i" to "j" :
   d[i][j] = INF

- for all node "k"              k = outer intermediate node
   - for all possible node "u"
      - for all possible node "v"
        d[u][v] = min(d[u][v], d[u][k] + d[k][v])
{O(V³)}

- output all pair shortest distance "d"


Here's what each loop does:
k loop: This loop iterates over each possible intermediate node in the graph. For example, if k is 3,
we are considering all paths that go from node i to node j through node 3.

u loop: This loop iterates over all possible starting nodes in the graph. For each starting node u,
we are considering all possible paths that go from u to some destination node v.

v loop: This loop iterates over all possible destination nodes in the graph. For each starting node
u and destination node v, we are considering all possible paths that go from u to v.

In other words, the k loop considers all possible intermediate nodes, and the u and v loops consider 
all possible starting and destination nodes. For each combination of u, v, and k, we are checking if 
the path from u to v through k is shorter than the current shortest path from u to v. If it is, we 
update the shortest path accordingly.
