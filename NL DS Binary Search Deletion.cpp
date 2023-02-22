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
        node *newnode = CreateNewNode(value);
        if(root == nullptr)
        {
            root = newnode;
            return;
        }

        node *cur = root;
        node *prv = nullptr;
        while(cur != nullptr)
        {
            if(newnode->value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else
            {
                prv = cur;
                cur = cur->Left;
            }
        }
        if(newnode->value > prv->value)
        {
            prv -> Right = newnode;
        }
        else
        {
            prv -> Left = newnode;
        }
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
            if(value > cur->value)
            {
                cur = cur -> Right;
            }
            else if(value < cur->value)
            {
                cur = cur -> Left;
            }
            else return true;
        }
        return false;
    }

    void Delete (int value)
    {
        node *cur = root;
        node *prv = nullptr;

        while(cur != nullptr)
        {
            if(value > cur->value)
            {
                prv = cur; //to track parent
                cur = cur->Right;
            }
            else if(value < cur->value)
            {
                prv = cur;
                cur = cur->Left;
            }
            else
            {
                break; //if equal, breaking.
            }
        }
        if(cur == nullptr)
        {
            cout<<"Value is not present in BST\n";
            return;
        }

        //case 1: target's both children are NULL/empty
        if(cur->Left == nullptr && cur->Right == nullptr)
        {
            if(prv->Left!=nullptr && prv->Left->value == cur->value)
            {
                prv->Left = nullptr; //checking if the target is prv's left
                //or right child. if left then making left null and deleting
            }
            else prv->Right = nullptr; //or else deleting right.
            delete cur; //now deleting cur to vacate the targetted node.
            return;
        }

//Case 2: Targetted node has only one child
//             6
//           ╱   ╲
//          5     10
//         ╱      ╱  ╲
//        4      7    11
//                ╲
//                 8
//here we want to delete 7, which is 10's left child. so, the first if statement
//is being entered. Then, (10)prv's left value is being equals to cur's value(7).
//now, we are assigning prv's left to cur's right which is 8 and cur(7) is being
//deleted.
//             6
//           ╱   ╲
//          5     10
//         ╱      ╱  ╲
//        4      8    11

        if(cur->Left==nullptr && cur->Right!=nullptr)
        {
            if(prv->Left!=nullptr && prv->Left->value == cur->value)
            {
                prv->Left = cur->Right; //if prv's left is the targetted
                //node, we will set the cur's right to prv's left
            }
            else prv->Right = cur->Right; //or else deleting right. suppose,
            //11 got a right child and left is empty. we will delete 11 and set
            //that right child to 10's right.
            delete cur;
            return;
        }

        //same type theories for this.
        if(cur->Left!=nullptr && cur->Right==nullptr) //suppose, we want to
            //delete 5.
        {
            if(prv->Left!=nullptr && prv->Left->value == cur->value)
            {
                prv->Left = cur->Left;
            }
            else prv->Right = cur->Left;
            delete cur;
            return;
        }

        ///CASE 3: if the targetted node has 2 children
//inorder successor finding: targetted node's right side's least valued node.
//replacing the targetted value with the just next higher node.
//           10
//       ___/  \___
//      5          15
//     / \        /  \
//    4   7     12    16
//             /  \    \
//            11  13   17
//suppose we want to delete 10. so cur is now set to 10. we are taking tmp set to
//the right of 10 because we need the minimum value from right. now it's pointed
//to 15. now the tmp is moving to the bottom most left because it will be the
//least value from the right side according to the binary search tree rule.
        node *tmp = cur->Right;
        while(tmp->Left!=nullptr) //moving until the last left child
        {
            tmp = tmp->Left;
        }
        int saved = tmp->value; //value is being saved to set at 10's place.
        Delete(saved); //now that bottom most left child is being deleted and
        //it will follow either the first or second case. here it's following
        //the second case.
        cur->value = saved; //and finally, the 10 is being replace by 11.
//            11
//        ___/  \___
//       5         15
//     /  \       /  \
//    4    7    12    16
//                \     \
//                 13    17
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
//      6
//     / \
//    4   7
//   / \   \
//  3   5   8
//Case 1
//    bst.Delete(8);
//    bst.BFS();
//case 2
//    bst.Delete(7);
//    bst.BFS();
//case 3
    bst.Delete(6);
    bst.BFS();
    if(bst.Search(1)) cout<<"1 found in the tree\n";
    else cout<<"1 not found in the tree\n";
    if(bst.Search(7)) cout<<"7 found in the tree\n";
    else cout<<"7 not found in the tree\n";
    return 0;
}
