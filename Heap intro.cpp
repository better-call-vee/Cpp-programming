//A heap is a binary tree with a specific ordering property. Unlike a regular binary
//tree, in a heap, the value of each node is either greater than or equal to (in a
//max heap) or less than or equal to (in a min heap) the values of its children.
//This property ensures that the node with the highest (or lowest) priority is
//always at the top of the heap, which makes it an efficient way to implement a
//priority queue.
//
//A common metaphor for a heap is that it's like a group of items that are piled
//up on a table. The highest (or lowest) priority item is always on top of the pile.
//If a new item is added to the pile, it gets added to the top, and if the top item
//is removed, the next highest (or lowest) priority item is revealed.
//
//Another way to think about a heap is to compare it to a line of people waiting to
//board a bus. The first person in line has the highest priority and will be the
//first to board the bus. When a new person arrives, they get added to the back of
//the line, and when the first person boards the bus, the next person in line
//becomes the new first person and will board next.
//
//In terms of performance, a heap has some advantages over other data structures.
//For example, adding or removing items from a heap is very fast because you only
//need to update the top of the heap and potentially a few other nodes, depending
//on the size of the heap. However, searching for a specific item in a heap is not
//very efficient because the ordering property doesn't allow you to easily determine
//where a particular item is located.

//Heap is a complete binary tree.

//Max Heap/ Mean Heap.
//We'll be able to find the max or min heap through these particular heap types.

/**
///MAX HEAP
        10
      /    \
     9      6
    / \    / \
   3   2  5   4
  /
 1
Max Heap Property
Here, the max value is on top and current node's value >= below nodes' values.

///MIN HEAP
           1
        /     \
       2       7
      / \     / \
     4   5   8   10
    /       /   /  \
   6       9   12   13
Mean Heap Property
Here, the minimum value is on top and current node's value <= below nodes' values.
**/
