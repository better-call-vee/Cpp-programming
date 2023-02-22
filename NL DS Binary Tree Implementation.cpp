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

//The tree is quite like this.
//      0(root)
//    /         \
//   1           2
//  /           / \
// 5           3   4

    void printTreeInfo ()
    {
        for(int i=0; i<6; i++)
        {
            int p = -1;
            int l = -1;
            int r = -1;
            if(allnode[i]->parent!=nullptr) p = allnode[i]->parent->id;
            if(allnode[i]->Left!=nullptr) l = allnode[i]->Left->id;
            if(allnode[i]->Right!=nullptr) r = allnode[i]->Right->id;
            //setting parent, left, right's id to p,l,r
            cout<<"Node "<<i<<": Parent = "<<p<<" , Left Child = "<<l<<" , Right child = "<<r<<"\n";
        }
    }
};

int main ()
{
    BinaryTree bt;
    bt.BuildBinaryTree();
    bt.printTreeInfo();
    return 0;
}
