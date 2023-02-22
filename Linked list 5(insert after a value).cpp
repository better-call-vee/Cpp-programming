#include<bits/stdc++.h>
using namespace std;

//suppose, a linked list -> (60)[5][20] -> (20)[10][25] -> (25)[15][NULL]
//next, we want to insert a node (50)[100][25] after value 10.
//so, (60)[5][20] -> (20)[10][50] -> (50)[100][25] -> (25)[15][NULL]

class node
{
public:
    int data;
    node *nxt;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }

    int size = 0;

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode -> data = value;
        newnode -> nxt = NULL;
        return newnode;
    }

    void Traverse ()
    {
        node *a = head;
        while (a!=nullptr)
        {
            cout<<a->data<<" ";
            a = a -> nxt;
        }
    }

    void InsertAtHead(int value)
    {
        size++;
        node *a = CreateNewNode(value);
        if(head == nullptr)
        {
            head = a;
            return;
        }
        else
        {
            a -> nxt = head;
            head = a;
        }
    }


    void InsertAfterValue(int value, int getch)
    {
        node *a = head;
        while (a != nullptr)   //traversing while the linked list isn't ending
        {
            if(a->data == value) break; //a->data matching the value. a->data means
            //8 no. line's class's data of 26 no. line's declared class.
            a = a->nxt;
        }

        if(a==nullptr) //a null means we haven't found the value.
        {
            cout<<value<<" doesn't exist in linked list.\n";
            return;
        }

        size++;

        //if we have got a, eg: above mentioned. pointing to 25 now and having 10
        //value with address 20

        node *newnode = CreateNewNode(ge tch);
        newnode->nxt = a->nxt; ///newnode is getting a's next pointing address
        ///which was 25
        a->nxt = newnode;    ///swapping their next pointing value and
        ///a's next pointing spot is the new node, which's address is 50 with
        ///value 100. (line 54)
    }
    int getSize()
    {
        return size;
    }

};

int main ()
{
    LinkedList l;
    l.InsertAtHead(30);
    l.InsertAtHead(10);
    l.InsertAtHead(5);
    l.Traverse();
    cout<<"\n";
    l.InsertAfterValue(10, 100);
    l.Traverse();
    cout<<"\nThe size of the linked list: "<<l.getSize()<<"\n";
    return 0;
}
