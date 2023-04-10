/*
Most of the times, for negative weights, Dijkstra gives wrong output and doesn't work without error.

         1
    10 ↙   ↘5   1
      2----->3----->4
         -8
look at the graph. let's do dijkstra on this bitch. start from 1. at first everyone's distance is set
to infinity. 
selected 1, exploring it's adjacent nodes. setting 2 and 3's distances to 10 and 5 respectively

next least distance node is 3. selecting 3, exploring 3. setting 4's distance to 5+1=6. 
next least distance node is 4 but 4 doesn't have any adjacent node. 
next least distance node is 2. selecting 2, exploring 2. setting 3's distance to 10-8=2.

but look here, 3 is already a done node and it's invalid to explore. but 4 has the shortest 
distance valuing 3!! 10-8+1 = 3   

THIS IS DIJKSTRA's LIMITATION no. 1. 


DIJKSTRA'S LIMITATION NO. 2:
Negative cycle detection 
     5        1
 1------->2------->4
  ↖     ↙
 -10↖ ↙ 2
     3

let's look at this now. here 1,2,3 makes a negative cycle because their nit weight will be negative.
-10+5+2 = -3
So, actually we can use the cycle any number of times just to decrease the distance of a node.
suppose, we are going to 4 from 1.
we can go like this : 1---->2---->4 : cost => 6
we can go like this : 1---->2---->3---->1---->2---->4 : cost => 3.
we can use the cycle twice/thrice or any number of times. everytime the distance of 4 will be being
less 3 than before! Dijkstra madafaka can't even detect this madafaka.

*/