
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value; //we will set a value for the id
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

    node *CreateNewNode(int id, int value)
    {
        node *newnode = new node;
        newnode -> id = id;
        newnode -> value = value;
        newnode -> Left = nullptr;
        newnode -> Right = nullptr;
        newnode -> parent = nullptr;
        return newnode;
    }

    //we will insert where we will find a slot empty for a child
    void Insertion (int id, int value)
    {
        node *newnode = CreateNewNode(id, value);
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
          / \         / \
         5   6       3   4

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

    void Search(node *a, int value) {
        if(a==nullptr) return;
        if(a->value==value) cout<<a->id<<" ";
        Search(a->Left, value);
        Search(a->Right, value);
    }

};

int main ()
{
    BinaryTree bt;
    bt.Insertion(0, 5);
    bt.Insertion(1, 10);
    bt.Insertion(2, 10);
    bt.Insertion(5, 9);
    bt.Insertion(6, 8);
    bt.Insertion(3, 5);
    bt.Insertion(4, 7);
    bt.BFS();
    bt.Search(bt.root, 10);
    return 0;
}

