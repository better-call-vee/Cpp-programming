#include<bits/stdc++.h>
using namespace std;

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

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode -> data = value;
        newnode -> nxt = NULL;
        return newnode;
    }

    int size = 0;

    int getValue(int index)
    {
        if (index >= size || index < 0)
            return -1;

        node *gv = head;
        for (int i = 0; i < index; i++)
        {
            gv = gv->nxt;
        }
        return gv->data;
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

    void printReverse()
    {
        node *temp = head;
        if (temp == nullptr)
            return;

        if (temp->nxt != nullptr)
        {
            head = temp->nxt;
            printReverse();
        }
        cout << temp->data << " ";
        head = temp;
    }

    void InsertAtHead(int value)
    {
        size ++;
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

     void swapFirst()
    {
        if (head == nullptr || head->nxt == nullptr)
            return;

        node *temp = head;
        head = head->nxt;
        temp->nxt = head->nxt;
        head->nxt = temp;
    }

    int getSize()
    {
        return size;
    }
};

int main ()
{
    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout<<l.getValue(2)<<"\n";

    cout<<l.getValue(6)<<"\n";

    l.printReverse();
    cout<<"\n";
    l.Traverse();
    cout<<"\n";
    l.swapFirst();
    l.Traverse();
    cout<<"\n";
    l.printReverse();

    return 0;
}

