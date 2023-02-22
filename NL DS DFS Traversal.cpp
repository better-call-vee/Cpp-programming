/**
DFS (Depth First Search) is a graph traversal algorithm that explores as far
as possible along each branch before backtracking. In other words, it starts
at a particular vertex and visits every vertex that is reachable from it, by
going as far as possible along each branch, before backtracking.

        0
      /   \
     1     2
    / \   /
   3   4 5

Suppose we start our DFS traversal at vertex 0. We mark vertex 0 as visited and
then visit one of its neighbors, for example, vertex 1. We mark vertex 1 as
visited and then visit one of its neighbors, for example, vertex 3. We mark
vertex 3 as visited and then is no neighbor of 3, so we backtrack to 1.
Now we will visit it's other neighbor(4) and we mark it visited. Then we backtrack
to 0 again because all of the vertices to 4 have been visited.
Now, we will visit 2 and 4 and marked them visited. So we backtrack to vertex 0.
Finally, we check that we have visited all vertices, and our DFS traversal is
complete.

It's quite a recursive definition.
f(root) -> 0,1,3,4,5 ; f(0) -> 0, f(1), f(2)
f(1) -> 1,3,4
f(2) -> 2,5
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

    ///DFS PREORDER TRAVERSAL
    void DFS(node *a)
    {
        if(a==nullptr) return;

        cout<<a->id<<" ";
        DFS(a->Left);
        DFS(a->Right);
    }
/**
Let's call DFS(&root), where root is a pointer to the root node (i.e., node 0).

Step 1: DFS(&root)
The input node a is not null (since root is not null), so the function prints
a->id (which is 0) to the console.
The function calls itself recursively with a->Left, which is a pointer to node 1.

Step 2: DFS(a->Left) (i.e., DFS(&node1))
The input node a is not null (since node1 is not null), so the function prints
a->id (which is 1) to the console.
The function calls itself recursively with a->Left, which is a pointer to node 5.

Step 3: DFS(a->Left) (i.e., DFS(&node5))
The input node a is not null (since node5 is not null), so the function prints
a->id (which is 5) to the console.
The function calls itself recursively with a->Left, which is null (since node5
is a leaf node).
The function calls itself recursively with a->Right, which is null (since node5
is a leaf node).
Since both child nodes of node5 are null, the recursive call for node5 returns
and control goes back to the previous call (i.e., DFS(&node1)).

Step 4: DFS(a->Right) (i.e., DFS(&node2))
The input node a is not null (since node2 is not null), so the function prints
a->id (which is 2) to the console.
The function calls itself recursively with a->Left, which is a pointer to node 3.

Step 5: DFS(a->Left) (i.e., DFS(&node3))
The input node a is not null (since node3 is not null), so the function prints
a->id (which is 3) to the console.
The function calls itself recursively with a->Left, which is null (since node3
is a leaf node).
The function calls itself recursively with a->Right, which is null (since node3
is a leaf node).
Since both child nodes of node3 are null, the recursive call for node3 returns
and control goes back to the previous call (i.e., DFS(&node2)).
The function now calls itself recursively with a->Right, which is a pointer to
node 4.
**/

///DFS INORDER TRAVERSAL.
//first the left is printed, then root, then right.
    void DFSinorder(node *a)
    {
        if(a==nullptr) return;

        DFSinorder(a->Left);
        cout<<a->id<<" ";
        DFSinorder(a->Right);
    }

///DFS POSTORDER TRAVERSAL
//root is printed at last.
    void DFSpostorder(node *a)
    {
        if(a==nullptr) return;

        DFSpostorder(a->Left);
        DFSpostorder(a->Right);
        cout<<a->id<<" ";
    }
};

int main ()
{
    BinaryTree bt;
    bt.BuildBinaryTree();
    cout<<"Preorder DFS : ";
    bt.DFS(bt.root);
    cout<<"\n"<<"Inorder DFS : ";
    bt.DFSinorder(bt.root);
    cout<<"\n";
    cout<<"Postorder DFS : ";
    bt.DFSpostorder(bt.root);
    return 0;
}
