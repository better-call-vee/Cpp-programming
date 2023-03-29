/*
     10
A---------->B
 ↘        ↙
 20↘    ↙3
     ↘↙
      C
Dijkstra(ডাইকস্ট্রা)
Here if we try to traverse the graph with the shortest path we will apply BFS.
See, if we apply BFS from source A, it will reach C from A to C direct which is rationally the
shortest path to reach C. But it's a weighted graph bruh. You will go through less distance (10+3)=13
if you would take the A--->B---->C path. An algorithm named Dijkstra is there to solve this problem.
*/
/*
   10      7
A------>B------>C
⬇5  ↗   |        ↘ 25
⬇ ↗ 10  ⬇5         F
D------>E---------↗
   20        2
We will select each node and measure the distance of all nodes in the graph from that particular node
Generally, we will start from A. We dunno the distances of all nodes primarily. After exploring, we
will get to know because it's a weighted graph. We will get B's distance => (A+edge weight) => 0+10
=>10. and for D: 0+5 => 5.

Now we will be greedy, till now, which adjacent node has the least distance, we will select that
biatch and ignore others. Now the next selected node is node D.

D the biatch got only two adjacent nodes which are E, B. D->E distance is 20. But D already has
a distance stored which is 5. So, E dick will get 25.
Now if we measure B's distance in path of D, we will get 5+10=>15 which is greater than previously
assigned B's distance.

**Each time, while the new distances are replacing the old distances,they are being measured. The less
you are the better. This attempt is called "RELAXATION"

Done with D, we won't consider again the nodes with whom we are done.

Now, the least distance stored node is B among the valid nodes. This biatch also got two mofos(C & E).
C's distance was infinity, now it will definitely get a new distance which is (10+7)=>17.
B to E's edge's weight is 5 and E's previously set distance was 25. Now, if we take B--->E, E will
get a distance measured (10+5)=>15. Bingo!

A, B, D done. They're invalid for next consideration. So, we have to choose the least distance
stored node among C, E and F. E qualifies.
E the loyal biatch got only one adjacent node "F". Their edge value is 2, warra couple. So, F will
get a distance measuring (15+2) => 17.

Hey hey, we're not done yet, there are still two undone mofos(C & F) left. They both have equivalent
distances stored per se. We can choose any of them. Choosing C.

This mofo has only one adjacent node which is F. If we try to get the distance of F through this
path, we will get (17+25) => 42!! duhh! Brud F already has a less distance stored(17), no way 42 can
step over, lol!

Got only one undone mofo F the fucker who has no adjacent node. So, mission passed, respect!

Selected     Distances
Node
             A     B     C     D     E     F
-            0    ♾️    ♾️   ♾️    ♾️   ♾️
A            0    10     ♾️   5     ♾️   ♾️  (A Done, we won't consider this mofo ever again)
D            0    10     ♾️   5     25    ♾️  (D Done, we won't consider this mofo ever again)
B            0    10     17    5     15    ♾️  (B Done, we won't consider this mofo ever again)
E            0    10     17    5     15    17   (E Done, we won't consider this mofo ever again)
C            0    10     17    5     15    17    (C Done, we won't consider this mofo ever again)
F            0    10     17    5     15    17     (F Done, Exploration completed)

   10      7
A------>B------>C
⬇5  ↗   |        ↘ 25   The last line(F's row) defines all the nodes' distance from A.
⬇ ↗ 10  ⬇5         F
D------>E---------↗
   20        2

*/

/*
Let's simulate another banger, baby calm down.
But It's Undirected.
B          E
| \4    3/   \2
|   \   /      \
|4    C-----6---D
|   /  \ 1    /
| /2     \  /3
A          F

METHOD OF RELAXATION:
if(d[u] + c(u,v) < d[v])  d[v] = d[u] + c(u,v)
Suppose, two nodes, u and v. If d[v] from source node is less than d[u] + cost of u and v's edge, then
we will go for relaxation and change the v's distance.

At first we measure the distances from the source node we selected, the source node we selected is
B. So, we get the distances. Among them, B now has the least distance which is 0, thus we select
B as our next selected node. Let's explore this bitch with a B.

B has two adj nodes, C and A. Here comes the method of relaxation.
d[B] + c(B, C) < d[C]
=0+4 < ∞
=true. C calm down(relaxed) d[C] = 4
Same goes for A, A is also relaxed with distance 4.

Here to select the next among the valid nodes(B is invalid now). A and C have the least distances.
Okay, let's select C for Calm Down.
C has 4 adj nodes(B, D, E, F)
B => d[C] + c(B, C) => 4+4 => 8, which is not less than B's set distance. So, ignored.
D => d[C] + c(D, C) => 4+6 => 10, which is less than d[D] which was infinity. So, relaxed.
E => d[C] + c(E, C) => 4+3 => 7, which is less than d[E] which was infinity. So, relaxed.
F => d[C] + c(F, C) => 4+1 => 5, which is less than d[F] which was infinity. So, relaxed.

Now, C done. Next valid least node is d[A]. Same method. No one gets relaxed
Now, F. D got less distance. D relaxed.
Now, E. Nobody gets relaxed
Now, The last one, D. No change again. We're done.

Selected        Distances
Node
                A         B          C          D          E          F
-              (∞)        0         (∞)        (∞)        (∞)        (∞)
B               4         0          4         (∞)        (∞)        (∞)     B☑️
C               4         0          4          10         7          5      C☑️
A               4         0          4          10         7          5      A☑️
F               4         0          4          8          7          5      F☑️
E               4         0          4          8          7          5      E☑️
D               4         0          4          8          7          5      D☑️


*/

/*
Pseudocode and Complexity

input -> a weighted graph and a source
output -> distance of all nodes from the source

- Create a distance array "d"     S[O(n)] , we will take all the nodes here
- Initialize all the values of "d" to infinity(a very large value like 1e5)
- d[src] = 0
- Create a visited array and mark all nodes as unvisited      S[O(n)]

- for i = 0 to n - 1: T(O(n^2))  //there will be inner loop working for 143th line
     - pick the "unvisited node with the least d[node]"
     - visited[node] = 1
     - for all adj_node of node: T[O(E)] it's complexity is O(E), previously explained in BFS, DFS
          -if d[node] + c(node, adj_node) < d[adj_node] {
               -d[adj_node] = d[node] + c(node, adj_node)
          }
- output array "d"

Overall Space Complexity -> O(n)
Overall Time  Complexity -> O(n^2 + E); We know one thing, for worst case scenario, this O(E) becomes
O(n^2).
The Overall Time Complexity -> O(n^2); for sparse graph -> O(n^2) + O(E)
*/

/*
OPTIMIZED DIJKSTRA(This algorithm works properly and efficiently with sparse graphs)

Optimized time complexity => O(mlogn), which can be O(n²logn) for big graphs. So, ultimately the
primary algorithm is good for large and big data and this optimized dijkstra is for sparse graphs.

input -> a weighted graph and a source
output -> distance of all nodes from the source

- Create a distance array "d"     S[O(n)] , we will take all the nodes here
- Initialize all the values of "d" to infinity(a very large value like 1e5)
- d[src] = 0
- Create a visited array and mark all nodes as unvisited      S/T[O(n)]
- Take an empty priority_queue "pq" of pair (minheap)
- pq.push({0, src})   ->   pushing source node


- while the priority_queue isn't empty: O(E) . (The queue will be pushed with items E times.)
     - pick the node with minimum distance value => head_distance, head = pq.top()
     - pq.pop() -> O(log E)
     - pick the "unvisited node":
     - if visited[head] == 1 : ignore
     - visited[head] = 1
     - for all adj_node of head: T[O(E)] it's complexity is O(E), previously explained in BFS, DFS
          -if d[node] + c(node, adj_node) < d[adj_node] {
               -d[adj_node] = d[node] + c(node, adj_node)
  (O log E) -> -pq.push({d[adj_node], adj_node}) [priority_queue's push pop's com. O(logn)]
look, when a node is being relaxed, we are
pushing it to the priority_queue for potentiality! how? when we get a relaxed node, there maybe
other opportunities to find more relaxed nodes if we take that relaxed node as our source node.
we are keeping the distance because we know, in pair priority_queue, if we pop, we get the value with
the greatest first pair.(minheap priority queue). so, we are automatically getting the node with the
least distance to go on.
          }
- output array "d"


COMPARE THE 142 & 171 LINES.
suppose a graph:
    10
A------->B | C
for the 142th syntax the loop will run 3 times because we have 3 nodes here.

first loop -> A was the source code. We pop it and it's set to head as it's the front of the queue
and it's distance is 0. it's marked visited. then we explore it. B gets relaxed because it has a large
value set before which is infinity. And the value of B is pushed in the queue{10, B}.

second loop -> B is the head now. B is now marked visited/done. Since B has no adjacent nodes, the 
second part isn't executed at all. 

third loop -> There is nothing to do and the queue is empty as well. It will be an error.
That's why we will run the loop until the priority queue has at least an element/is not being empty

177th line's loop will run total E times and it's not connected with the outer loop, it's independent

total time complexity :
O(n) + O(E log E) + O(E log E) 
=> O(E log E)
=> O(|E| log |E|) here the modulus is referring as the number of edges.

E => V^2  . E can be V^2 in worst case (v = number of vertices)

=> O(|E| log |V^2|)
=> O(2|E| log |V|)  ->  a logarithmic theory
=> O(|E| log₂|V|)  -> log subscript 2(log base 2). in time complexity calculation, log is generally 2
based. generally log is 10 based tho.

*/