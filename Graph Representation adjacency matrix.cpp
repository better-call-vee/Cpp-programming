//A way to let computer understand the mechanism of graph. the visuals we draw
//computer can't understand. we need to represent in a way to make computer
//understand the node, edge and their relations

//Let's learn graph presentation with adjacency matrix. Think about 2D array.
/**
     (0)A----B(1)
            /\
           /  \
          /    \
         /      \
     (2)C--------D(3)

╔═══╦═══╦═══╦═══╦═══╗
║     0   1   2   3 ║ Now look at this and learn the theory.
╠   ╬═══╬═══╬═══╬═══╣
║ 0 ║ 0 ║ 1 ║ 0 ║ 0 ║ If two nodes are connected, then matrix[i][j] = 1.
╠   ╬═══╬═══╬═══╬═══╣ Here, i---j.
║ 1 ║ 1 ║ 0 ║ 1 ║ 1 ║ suppose this matrix here is the representation of the above
╠   ╬═══╬═══╬═══╬═══╣ drawn graph. where 0 is connected 1(A-->B). look at
║ 2 ║ 0 ║ 1 ║ 0 ║ 1 ║ the matrix. row(i) 0's column(j) 1 is 1. so, it supports the
╠   ╬═══╬═══╬═══╬═══╣ formula. match this for others as well.
║ 3 ║ 0 ║ 1 ║ 1 ║ 0 ║
╚═══╩═══╩═══╩═══╩═══╝


Now we will represent a directed graph.
    1
 0 ---> 1
  \    ^    if a weighted graph has the same weight for each node, then it's
 1 \  / 1   considered as an UNWEIGHTED graph.
    v/
    02

╔═══╦═══╦═══╦═══╦
║     0   1   2 ║
╠   ╬═══╬═══╬═══╬ Here, 0 is directed to 1 and 2, so 0th row has value 1 in
║ 0 ║ 0 ║ 1 ║ 1 ║ column 1 and 2. 1 has no directed connection with any node. so
╠   ╬═══╬═══╬═══╬ whole 1th row is 0.
║ 1 ║ 0 ║ 0 ║ 0 ║
╠   ╬═══╬═══╬═══╬ here if 1 has a self-loop, then 1th row's 1th column will be 1.
║ 2 ║ 0 ║ 1 ║ 0 ║
╚═══╩═══╩═══╩═══╩



Now we will represent a directed weighted graph.
    3
 0 ---> 1
  \    ^
 2 \  / 4
    v/
    02

╔═══╦═══╦═══╦═══╦
║     0   1   2 ║
╠   ╬═══╬═══╬═══╬ Here, 0 is directed to 1 and 2, with weights measuring 3 and 2
║ 0 ║ 0 ║ 3 ║ 2 ║ correspondingly.
╠   ╬═══╬═══╬═══╬ Then, 2 is directed to 1 with weight measuring 4.
║ 1 ║ 0 ║ 0 ║ 0 ║
╠   ╬═══╬═══╬═══╬ for weighted directed graph, we need to represent like this.
║ 2 ║ 0 ║ 4 ║ 0 ║ matrix[i][j] = W(i,j). i----->j
╚═══╩═══╩═══╩═══╩                           w

#we can't express the multiedge with adjacency matrix. it collides with weighted
matrix concept. suppose here 0 and 2 have 3 multiedges. so, 0th 2nd column will
be 3. so it's controversial and a drawback of adjacency matrix.

**/


