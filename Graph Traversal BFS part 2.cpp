/**

It's for a cyclic graph.
THE UNVISITEDS GET PUSHED, THE SELECTED GETS POPPED.

4---5---1
 \  |\  |  Like I said before, BFS is level by level order. look, at first 5 and 3
  \ | \ |  are printed after 4 because they're one edge away from 4. but at last
   \|  \|  2 and 4 printed because they're 2 edges away.
    3---2  Here we started from 4 so 4 is called the SOURCE NODE.

Here, we will take an extra array named visited array where we will store the nodes
which are visited but other steps are the same as before.
The visited array will be like frequency array.
╭───╮╭───╮╭───╮╭───╮╭───╮╭───╮
| X │ 0 │ 0  │ 0 │ 0 │ 0  │
╰───╯╰───╯╰───╯╰───╯╰───╯╰───╯
  0   1    2   3    4   5
  If we get any of the number of the indices, we will increase the value by one of
  the particular index.

  At first we are selecting 4. so, printed -> 4.
  output[4]. now we will explore. 5 and 3. pushed. output[4,5,3] and 4 popped. so
  output[5,3]. 4 popped because exploration done. now the visited array will be:
╭───╮╭───╮╭───╮╭───╮╭───╮╭───╮
| X │ 0 │ 0  │ 1 │ 1 │  1 │
╰───╯╰───╯╰───╯╰───╯╰───╯╰───╯
  0   1    2   3    4   5

  Then, moving on to 5. so, printed -> 4, 5.
  output[5,3]. but now we will explore. 1,2,3. pushed 1,2. output[5,3,1,2]
  now 5 gets popped. here, we used the visited array. 3 already had 1 count that's
  why we didn't push 2. now the array will be:
╭───╮╭───╮╭───╮╭───╮╭───╮╭───╮
| X │ 1 │  1 │ 1 │ 1 │  1 │  and output[3,1,2]
╰───╯╰───╯╰───╯╰───╯╰───╯╰───╯
  0   1    2   3    4   5

  And the process and checking continues, in the end: the queue will be empty and
  we will get 4, 5, 3, 1, 2.

  Change the source node and try again. suppose, we take 1 as source code.
  printed -> 1, 5, 2, 4, 3.

**/
