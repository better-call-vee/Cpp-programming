//Graph contains node/vertex or, some edges
//nodes connect one with another and they create an edge. Edge is generaally a pair
//of nodes.

//A node in a graph can be thought of as a representation of an object or data.
//In a graph, nodes have no direction and are simply points that store information.
//For example, in a social network graph, each node could represent a person, and
//the information stored at that node could be the person's name and other details
//about them.
//
//An edge in a graph represents a relationship between two nodes. In a graph, an
//edge has a direction, which means it goes from one node to another. For example,
//in a social network graph, an edge could represent the relationship between two
//people who are friends. The edge would start at one person's node and end at the
//other person's node, indicating that the two people are friends.
//
//In summary, a node in a graph represents an object or data, and an edge represents
//a relationship between two nodes.

//Graph is needed for navigating. To navigate the shortest path. Let's consider
//the example of a city map. Imagine you want to find the shortest route from your
//home to a friend's house. To solve this problem, you can use a graph to represent
//the city's roads. Each node in the graph represents a landmark (such as your home
//or your friend's house), and each edge represents a road connecting two landmarks.


///TREE IS A GRAPH BUT TREE DOESN'T CONTAIN CYCLE(ACYCLIC)
//suppose a graph, 1-2,1-4,2-4,4-3,4-6. here they are connected. so, 1-2-4-1, which
//means, if 1 goes ahead with the edges and comes back again to 1, that's a cycle.
//It's a cyclic graph, yes it is.
//Tree's root has no parents but other nodes have one parent. Gettind divided into
//branches.

///BINARY TREE
//Every node has at most 2 children, not more than that. one child is also okay
//left child and right child.
//In a binary tree, each node has a parent node and can have two children nodes.
//The top node of the tree is called the root node, and the nodes with no children
//are called leaf nodes. The height of a binary tree is the number of edges from
//the root node to the deepest leaf node.
//Each level will contain at most 2^(level-1) children.
//
//A binary tree can be used to organize data in a hierarchical manner, where the
//parent node is higher in the hierarchy than its children nodes, and the children
//nodes are lower in the hierarchy than their parent node. For example, in a file
//system, a binary tree can be used to organize files and directories, where the
//root node represents the highest-level directory and its children represent
//subdirectories and files.
//
//One important property of binary trees is that the left child node of a parent
//node is always smaller than the parent node, and the right child node is always
//larger. This property is useful for efficiently searching for data in a binary
//tree, as it allows us to eliminate half of the tree with each comparison.
//
//In summary, a binary tree is a type of data structure where each node has at
//most two children, and the nodes are organized in a hierarchical manner, with
//the parent node being higher in the hierarchy than its children
