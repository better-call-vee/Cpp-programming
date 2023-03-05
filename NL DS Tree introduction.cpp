//A tree is a hierarchical data structure that resembles a real-world tree. Just
//as a real-world tree has a trunk (root) and branches, a tree in computer science
//has a root node and branches that extend from it in the form of child nodes.

//Tree is an acyclic graph.

//A good metaphor to understand the tree structure is to think of a family tree.
//The root node represents the head of the family, and each child node represents
//a direct descendant of the head of the family. Each child node can have its own
//child nodes, representing descendants of the descendants, and so on.
//
//Trees have many applications in computer science, including:
//Representing hierarchical relationships between objects
//Storing data for efficient search and retrieval operations
//Implementing algorithms such as breadth-first and depth-first search
//Building decision trees for machine learning and artificial intelligence
//Compression and encoding of data

//Binary tree's nodes can have at most 2 children

//FOR TREE, we can't use a path twice

//        A---E
//      /   \
//     B     C---D
//    /       \
//   G         F
//if we go like this G->B->A->E->A->C->D. we can't go like this
//but, G->B->A->C->D. can go like this only.
