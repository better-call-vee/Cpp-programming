/*

By bellman-ford algorithm, we can correctly calculate the negative weighted distances. We do it by
iteration and relaxation.
The theory is, we need at most n-1 iteration to find the shortest paths of all the nodes where n is 
the number of nodes.

  -1     5
1---->2---->3
at first everyone's distance remains infinity. and source node's reamins 0.
if we start the iteration from 1--->2 edge, it will take only 1 iteration but if we start from the node
2, it will take 2 iterations.

1 => 1's distance becomes 0 because it's the source node. 2's distance is changed to -1. 3's relaxed
with the value of 5.

2 => 2's distance is infinity and it remains. 3's distance is infinity, if we apply the theory of
relaxation, it's distance becomes even more (infinity+5), so it remains also. 1st iteration ends.
then we go the next iteration and we get all the shortest distances. So, it took at most 2 iterations.



Let's look at another bitch:
     5
1--------->2
|          |
⬇-2        ⬇-6
⬇          ⬇
3--------->4
     1
if we go with this following sequence:
3-->4       a
1-->3       b
2-->4       c
1-->2       d

then, first iteration: 1 is set with 0(source node) and rest are infinity.
a=> 3 and 4's distances are the same = ♾️. So, no change for 4.
b=> 1 and 3's edge cost is -2. d[1]=0. ∴ d[3] = 0-2 = -2. 3 relaxed with -2
c=> same shit happens for 4 unfortunately. nothing will be changed
d=> 2 is relaxed with d[2] = 5

then, second iteration:
a=> 3's distance is -2. so 4 is relaxed with -1. d[4] = -1
b=> relaxed. d[3] = -2
c=> relaxed. d[2] = 5
d=> relaxed. d[1] = 0



The last brute bitch:
     5        1
 1------->2------->4
  ↖     ↙
 -6 ↖ ↙ 2
     3

1-->2    a
2-->4    b
2-->3    c
3-->1    d

first iteration:
a => 1's distance is 0. 2 is relaxed with 5.
b => 2's distance is 5. 4 is relaxed with 6.
c => 2's distance is 5. 3 is relaxed with 7.
d => 3's distance is 7. 1 was relaxed with 0, new distance can be 1 which is greater than the
     relaxed distance set heretofore. so we move.
done

SUMMARY: WE CAN FIND THE SHORTEST PATHS BY ITERATION ON EDGES AND THERE WILL BE AT MOST NUMBER OF
NODES-1 ITERATIONS.

ON nth ITERATION, WE CAN DETECT THE NEGATIVE CYCLE BECAUSE WHEN THERE'S A NEGATIVE CYCLE IN THE GRAPH
IT WILL ALWAYS BE RELAXED AT THE LAST ITERATION.


n-> number of nodes
m-> number of edges
PSEUDOCODE:
Input -> A weighted graph & a source node (with no negative cycle)
Output -> Shortest distance from source node to all other nodes

- Create a distance array "d" with all values set to infinity  {TC => O(n)}
- d[source] = 0  {O(1)}

negative_cycle = false

for i=1 to n :   {O(n)}
     for all edges e(u, v, w):      means u to v is a direct edge which cost w.  {O(m)}
         if d[u] + w < d[v]
         => d[v] = d[u] + w
         -if i==n: 
            -negative_cycle = true
{for the nested loop O(n*m)}

- print the distance array "d" {O(n)}

Total Time Complexity :
O(n) + O(1) + O(n*m) + O(n)
=> O(n*m)
=> O(|V| * |E|);    
for worst case it will run with O(V^3) time complexity. (E=V^2)
Space complexity => O(n)
*/