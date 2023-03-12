/**
BFS is a level order traversal we know.

5      4
|     /
|    /
1---2---3
Steps:
1. Select a node
2. Explore a node(it means visiting all it's adjacent nodes)

Taking an output container where we will keep the nodes.(which is actually a queue)
Suppose, we are starting with 1. Exploring 1. 1's adjacents are 2 and 5.
So, output[1,5,2].
now, next 5. 5's adjacent is only 1. it's done so we will not select or explore.
next selected node will be 2. 2's adjacents are 4 and 3. we will explore and keep
those in output.
output[1,5,2,4,3]. then we will select 4 and 3 but they're already done.

second example:
       2
      / \
     4   3
    /|\
   6 1 5

first selected node = 2. pushing to output queue. output[2]
now, 2's adjacents are 4 and 3. pushing 4 and 3. it doesn't matter in which order
we are pushing the adjacents. and now we will pop the head from output queue.
now, output[4,3]. and this popped 2 will be printed. printed -> 2.

now, 2 is done. next selected node will be 4. the node we will select, we will print
at first. printed -> 2, 4.
and then, we will explore the selected node. 6,1,5,2 are the adjacents of 4. 2 has
been outputed already so it will be ignored. 6, 1, 5 will be pushed to the queue and
4 will be popped out.
printed -> 2, 4
output[3,1,6,5].

now, selected node is 3. adjacent nodes of 3 is 2 which is already visited. popping
3. same goes for 1,6,5 because their adjacent 4 is already visited and they will
be popped and the queue will be empty.
printed -> 2,4,3,1,6,5

**/
