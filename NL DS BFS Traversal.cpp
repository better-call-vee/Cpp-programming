/**

BFS stands for "Breadth-First Search", and it is a traversal algorithm used to
explore all the nodes of a graph or a tree in a level-wise order. It starts from
the root node and explores all the neighboring nodes at the current level before
moving on to the next level.

In BFS traversal, we maintain a queue to keep track of the nodes to be visited.
We start by adding the root node to the queue and mark it as visited. Then, we
repeat the following steps until the queue is empty:

1.Dequeue the front node from the queue
2.Visit the node and perform any necessary operations
3.Enqueue all the unvisited neighboring nodes of the dequeued node
By doing so, we visit all the nodes in a level-wise order, starting from the
root node.

For example, consider the following binary tree:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
If we perform a BFS traversal on this tree starting from the root node, we visit
the nodes in the following order: 1, 2, 3, 4, 5, 6, 7. We first visit the root
node 1, then its children 2 and 3, then their children 4, 5, 6, and 7.

**/

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    node *Left;
    node *Right;
    node *parent;
    //it's quite like linked list. instead of next and previous, here are left,
    //right, parent nodes & id to recognize them.
};

class BinaryTree
{
public:
    node *root;
    node *allnode[6];

    BinaryTree ()
    {
        root = nullptr;
    }

    node *CreateNewNode(int id)
    {
        node *newnode = new node;
        newnode -> id = id;
        newnode -> Left = nullptr;
        newnode -> Right = nullptr;
        newnode -> parent = nullptr;
        return newnode;
    }

    void BuildBinaryTree ()
    {
        node *allnode[6];
        //we have taken an array for 6 nodes of a tree
        for(int i=0; i<6; i++) //now we have created the new 6 nodes with id.
        {
            allnode[i] = CreateNewNode(i);
        }
        allnode[0]->Left = allnode[1];
        allnode[0]->Right = allnode[2];

        allnode[1]->Left = allnode[5];
        allnode[1]->parent = allnode[0];

        allnode[2]->Left = allnode[3];
        allnode[2]->Right = allnode[4];
        allnode[2]->parent = allnode[0];

        allnode[5]->parent = allnode[1];

        allnode[3]->parent = allnode[2];
        allnode[4]->parent = allnode[2];
        root = allnode[0];
    }

/**
      0(root)
    /         \
   1           2
  /           / \
 5           3   4

**/

    void BFS()
    {
        queue<node*>q;
        q.push(root); //pushing root to q.
        while (!q.empty()) //continuing the loop until it's becoming empty
        {
            node *a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->Left != nullptr)
            {
                l = a->Left->id;
                q.push(a->Left);
            }
            if(a->Right != nullptr)
            {
                r = a->Right->id;
                q.push(a->Right);
            }
            if(a->parent != nullptr) p = a->parent->id;
            cout<<"Node id = "<<a -> id<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<" Parent id = "<<p<<"\n";
        }
    }

};

int main ()
{
    BinaryTree bt;
    bt.BuildBinaryTree();
    bt.BFS();
    return 0;
}
