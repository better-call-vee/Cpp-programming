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
**Each time, while the new distances are replacing the old distances, they are being measured. The less
you are the better.
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