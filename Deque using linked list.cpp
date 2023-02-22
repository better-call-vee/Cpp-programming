//will do this using doubly linked list.
//not possible to implement with singly linked list.

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prv;
    node *nxt;
};

class Deque
{
public:
    node *head;
    node *tail;
    int sz;

    Deque()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode -> data = value;
        newnode -> prv = nullptr;
        newnode -> nxt = nullptr;
        return newnode;
    }

    void push_back(int value)
    {
        node *newnode = CreateNewNode(value);
        if(sz == 0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail -> nxt = newnode;
        newnode -> prv = tail;
        tail = newnode;
        sz++;
    }

    void push_front(int value)
    {
        node *newnode = CreateNewNode(value);
        if(sz == 0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head -> prv = newnode;
        newnode -> nxt = head; //newnode's prv is already null,so we don't
        //need to do that differently
        head = newnode;
        sz++;
    }

    void pop_back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            sz--;
            return;
        }
        node *a = tail;
        tail = tail->prv;
        delete a;
        tail->nxt = nullptr;
        sz--;
    }

    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            sz--;
            return;
        }
        node *a = head;
        head = head->nxt;
        delete a;
        head->prv = nullptr;
        sz--;
    }

    int front ()
    {
        if(sz==0) return -1;
        return head->data;
    }

    int back ()
    {
        if(sz==0) return -1;
        return tail->data;
    }

};

int main ()
{
    Deque d;
    d.push_back(5);
    d.push_back(10);
    d.push_back(15);
    if(d.back()!=-1) cout<<"Back : "<<d.back()<<"\n";
    else cout<<"Deque is empty\n";
    if(d.front()!=-1) cout<<"Front : "<<d.front()<<"\n";
    else cout<<"Deque is empty\n";

    d.push_front(20);
    if(d.back()!=-1) cout<<"Back : "<<d.back()<<"\n";
    else cout<<"Deque is empty\n";
    if(d.front()!=-1) cout<<"Front : "<<d.front()<<"\n";
    else cout<<"Deque is empty\n";

    d.pop_front();
    d.pop_back();
    if(d.back()!=-1) cout<<"Back : "<<d.back()<<"\n";
    else cout<<"Deque is empty\n";
    if(d.front()!=-1) cout<<"Front : "<<d.front()<<"\n";
    else cout<<"Deque is empty\n";

    return 0;
}
