/*
BELLMAN-FORD IS A KIND OF DYNAMIC PROGRAMMING

If there remains a negative cycle in the graph, the single source shortest path will be -♾️.
then we will only print the freakin cycle
Else, we will only print the path of the graph normally.
We will run n-1 times iteration if there's not any negative cycle. Else we will run n interation.

        3          -1
   1--------->2--------->4
   |          | 
 -4|          |1     
   |          ⬇
   ---------->3  
       -4

we will take a parent array and set the parent of the relaxed node by storing the value of it's source
node into a vector. 
u----w---->v
d[u] + w < d[v]
here, parent[v] = u;
then we will follow the rule of printing path. first the destination node, then parents one by one.
then reverse.



Negative cycle printing:
          2       -4        3
      1------->2------->3------->6
    -3|         ↖      /         |
      ⬇          2\  ↙ -1        ⬇1
      5            4             7

      for the nth iteration, either node of the negative cycle will be relaxed or nodes that can be
      reached(6,1. not 1,5) from the negative cycle will be relaxed
      if we are out of cycle after nth iteration, we will parent trace n-1 times and we will be in the
      cycle frfr. And if we are already in the cycle, we will just parent trace until we are reaching
      again the source node. If we are already in the cycle and still do this n-1 thing, we will still
      be in the cycle for sure.
       -3
      |--|  1     2     3      
      ---1---->2----->3----->4
      there is a self loop with 1. if we are at node 4, we need to parent trace n-1 times to reach 1.


PSEUDOCODE:
- Create a distance array "d" with all values set to infinity  {TC => O(n)}
- create a parent array
- d[source] = 0  {O(1)}

negative_cycle = false
last_updated_node = -1;

for i=1 to n :   {O(n)}
     for all edges e(u, v, w):      means u to v is a direct edge which cost w.  {O(m)}
         if d[u] + w < d[v]
         => d[v] = d[u] + w
         => parent[v] = u
         -if i==n: 
            -negative_cycle = true
            -last_updated_node = v   {the node which is being relaxed on nth iteration.}

{for the nested loop O(n*m)}

-if negative_cycle == true: {O(n)}
   - print negative cycle exists
   - selected_node = last_updated_node
   - for i=1 to n-1:
     - selected_node = parent[selected_node]

   -last_updated_node = selected_node

   -declare a vector "cycle"
   -cycle.push_back(selected_node)
   -while true:                   
      - selected_node = parent[selected_node]
      - cycle.push_back(selected_node)
      - if selected_node == last_updated_node then break
      - reverse the "cycle" vector
      - print the path 


-if negative_cycle == false:  {O(n)}
   - print the distance array "d" {O(n)}
   - selected_node = destination_node
   - declare a vector path
   -while(true) :
      -path.push_back(selected_node)
      -if selected_node == source: break
      -selected_node = parent[selected_node]
   -reverse the vector path
   -print the path
*/