//A way to let computer understand the mechanism of graph. the visuals we draw
//computer can't understand. we need to represent in a way to make computer
//understand the node, edge and their relations
//The adjacency matrix is only symmetric for undirected graphs.
//this means that the matrix is symmetric across its diagonal. For example, in a
//3x3 symmetric matrix, the element in row i and column j is equal to the element
//in row j and column i, for all i and j.

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

/**

the time complexity to calculate the number of edges in a graph whose information
is stored in the form of an adjacency matrix is O(vertex^2).

To calculate the number of edges in an undirected graph using its adjacency
matrix, we can iterate through the elements of the upper or lower triangular
portion of the matrix (since the matrix is symmetric), and count the number of
non-zero entries. Since the matrix has vertex^2 entries and we only need to
examine half of them, the time complexity is O(vertex^2/2), which simplifies
to O(vertex^2).

Similarly, to calculate the number of edges in a directed graph using its
adjacency matrix, we can iterate through all the entries of the matrix and
count the number of non-zero entries. Since the matrix has vertex^2 entries,
the time complexity is also O(vertex^2).

Therefore, regardless of whether the graph is directed or undirected, the time
complexity to calculate the number of edges from its adjacency matrix is
O(vertex^2).

**/


/**

In a simple graph with n vertices, the maximum number of possible non-zero
values in its adjacency matrix is n(n-1)/2.

This is because in an undirected simple graph, each vertex can be connected to
at most n-1 other vertices, and the diagonal entries of the adjacency matrix are
always zero. Therefore, for each vertex, there are n-1 possible edges that can
be incident on it. However, since the graph is simple, each edge can only be
counted once, which means that the total number of edges in the graph is at
most (n-1) + (n-2) + ... + 1 = n(n-1)/2.

Since the adjacency matrix of an undirected simple graph is symmetric, we only
need to consider the upper or lower triangular portion of the matrix, which
contains n(n-1)/2 entries. Therefore, the maximum number of possible non-zero
values in the adjacency matrix of an undirected simple graph with n vertices
is also n(n-1)/2.

It's worth noting that not all possible n(n-1)/2 entries need to be filled in
an adjacency matrix, as the actual number of edges in a simple graph can be
less than this maximum bound. However, this is the maximum number of non-zero
values that can appear in the adjacency matrix of an undirected simple graph
with n vertices.

**/
