#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *Left;
    node *Right;
};

class BST
{
public:
    node *root;

    BST ()
    {
        root = nullptr;
    }

    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->Left = nullptr;
        newnode->Right = nullptr;
        return newnode;
    }

    void Insert(int value)
    {
        node *newnode = CreateNewNode(value);//we will insert the value to the
        //tree, so we are creating a newnode.

        if(root == nullptr) //checking if the root is null or not.
        {
            root = newnode;
            return; //corner case handled
        }
        //otherwise, suppose we have already a binary search tree;

//          ╭─── 5 ───╮
//          │         │
//      ╭─── 3 ───╮  ╭─── 8 ───╮
//      │         │  │         │
//    2 │        4│  │        9│
//      │         │  │         │
//      ╰─────────╯  ╰─────────╯
//we want to insert 7 here.
//so cur is now 5. and cur's prv is null.

        node *cur = root;
        node *prv = nullptr;
        while(cur != nullptr) //we are going until cur is being null
        {
            if(newnode->value > cur->value) //so, if root's value is greater than
//newnode's value, we will obviously go to right.
            {
                prv = cur; //so now 5 will be prv and 8 will be cur
                cur = cur->Right;
            }
            else     //now for the next loop newnode's value is lesser than 8 so
//it will enter the else condition and 8 will be prv. and cur will be pointed to
//null. now we will break the loop.
            {
                prv = cur;
                cur = cur->Left;
            }
        }
        //now we have got our desired place to insert
        if(newnode->value > prv->value) //we haven't tracked if it's right of prv
            //or left of prv.
        {
            prv -> Right = newnode; //if the value is more than prv then we will
            //go right or else we will go left. here, prv is mainly parent node.
        }
        else
        {
            prv -> Left = newnode;
        }
        //done
    }

    void BFS()
    {
        queue<node*>q;
        q.push(root);
        while (!q.empty())
        {
            node *a = q.front();
            q.pop();
            int l = -1, r = -1;
            if(a->Left != nullptr)
            {
                l = a->Left->value;
                q.push(a->Left);
            }
            if(a->Right != nullptr)
            {
                r = a->Right->value;
                q.push(a->Right);
            }
            cout<<"Node value = "<<a -> value<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<"\n";
        }
    }

    bool Search (int value)
    {
        node *cur = root;
        while(cur!=nullptr)
        {
            if(value > cur->value) //roaming every node & searching
            {
                cur = cur -> Right;
            }
            else if(value < cur->value)
            {
                cur = cur -> Left;
            }
            else return true; //when value will be the same as cur's value.
        }
        return false; //if we don't get the same value after traversing the
        //whole tree, the while loop will be broken. then it's false and not
        //found
    }

};

int main ()
{
    BST bst;
    bst.Insert (6);
    bst.Insert (4);
    bst.Insert (3);
    bst.Insert (5);
    bst.Insert (7);
    bst.Insert (8);
    bst.BFS();
    if(bst.Search(1)) cout<<"1 found in the tree\n";
    else cout<<"1 not found in the tree\n";
    if(bst.Search(7)) cout<<"7 found in the tree\n";
    else cout<<"7 not found in the tree\n";
    return 0;
}
