
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

    //we will insert where we will find a slot empty for a child
    void Insertion (int id)
    {
        node *newnode = CreateNewNode(id);
        //creating a newnode whose left, right, parent nodes are null with
        //the given id.
        if(root==nullptr)
        {
            root = newnode; //if the tree is already empty and there is no
            //root, we will make the newnode root
            return;
        }
        queue<node*>q;
        q.push(root); //pushing root to q.
        while (!q.empty()) //continuing the loop until it's becoming empty
        {
            node *a = q.front();
            q.pop();
            if(a->Left != nullptr)
            {
                q.push(a->Left);
            }
            else
            {
                a->Left = newnode;
                newnode->parent = a;
                return;
            }
            if(a->Right != nullptr)
            {
                q.push(a->Right);
            }
            else
            {
                a->Right = newnode;
                newnode->parent = a;
                return;
            }
        }
    }

    /**
              0(root)
            /         \
           1           2
          /           / \
         5           3   4

    **/
///SUPPOSE, We want to Insert 6 which will be 1's right child.
/**
Create a new node with the value of 6.
Check if the root of the tree is empty (i.e., null).
Since the root is not null, we will push the root node into a queue and start a
loop.
In each iteration of the loop, we will dequeue a node from the front of the
queue and check if its left child is null. If it is null, we will set the new
node as the left child of this node and set its parent to be this node, and then
return from the function.
If the left child of the node is not null, we will enqueue the left child to the
queue.
We will then check if the right child of the node is null. If it is null, we
will set the new node as the right child of this node and set its parent to be
this node, and then return from the function.
If the right child of the node is not null, we will enqueue the right child to
the queue.
We will continue this loop until we find a node that has a null child, and then
we will insert the new node there.
**/

    void BFS()
    {
        if(root==nullptr) return;
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
    bt.Insertion(0);
    bt.Insertion(1);
    bt.Insertion(2);
    bt.Insertion(5);
    bt.Insertion(6);
    bt.Insertion(3);
    bt.Insertion(4);
    bt.BFS();

    return 0;
}
