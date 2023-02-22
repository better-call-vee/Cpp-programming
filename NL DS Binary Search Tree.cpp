/**
A binary search tree (BST) is a data structure in C++ that is used to store a
collection of elements. It is a type of tree where each node has at most two
children, referred to as the left child and the right child.

The nodes in a binary search tree are arranged in a specific order based on
the value of the elements they store. Each node in the tree represents an
element, and the left child of a node contains elements with values less than
the node's value, while the right child of a node contains elements with values
equals to/greater than the node's value.

       🌳  6  🌳
       /       \
      4         8
     / \       / \
    2   5     7   9
   / \
  1   3

In this example, the root node contains the value 6, and its left child contains
the value 4, which is less than 6, while its right child contains the value 8,
which is greater than 6. The left child of the 4 node contains the value 2, which
is less than 4, and so on. It's a binary search tree, yes it is!

         🌳 4 🌳
        /       \
       1         6
      /         / \
     1         4   7
Here in this tree, on the right side, 6's child for is equals to the root. Also
on the left side, 1's child 1 is equals to it's root 1. So, it's quite contradic-
tory to have the root's same value for both sides. So, it's not a BST.
**/
#include <iostream>

using namespace std;

int main() {
  // Print the tree using ASCII art
  cout << "        \U0001F332   4   \U0001F332" << endl;
  cout << "       /          \\" << endl;
  cout << "      1            6" << endl;
  cout << "     /            / \\" << endl;
  cout << "    1            4   7" << endl;

  return 0;
}
