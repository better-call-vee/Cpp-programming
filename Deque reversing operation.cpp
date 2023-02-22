
//pushback -> pushfront
//pushfront -> pushback
//popback -> popfront
//popfront -> popback
//front -> back
//back -> front

//O(1) time complexity

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
    int rev;

    Deque()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
        rev = 0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode -> data = value;
        newnode -> prv = nullptr;
        newnode -> nxt = nullptr;
        return newnode;
    }

    void InsertAtTail (int value)
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

    void InsertAtHead(int value)
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

    void push_back(int value)
    {
        if(rev == 0) InsertAtTail(value);
        else InsertAtHead(value);
    }

    void push_front(int value)
    {
        if(rev==0) InsertAtHead(value);
        else InsertAtTail(value);
    }

    void DeleteAtTail()
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

    void DeleteAtHead()
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

    void pop_back()
    {
        if(rev==0) DeleteAtTail();
        else DeleteAtHead();
    }

    void pop_front()
    {
        if(rev==0) DeleteAtHead();
        else DeleteAtTail();
    }

    int front ()
    {
        if(sz==0) return -1;
        if(rev==0) return head->data;
        else return tail->data;
    }

    int back ()
    {
        if(sz==0) return -1;
        if (rev==0) return tail->data;
        else return head->data;
    }

    void reverse_deque()
    {
        if(rev == 0)
        {
            rev = 1; //when rev is being 1, the deque will be reversed.
        }
        else rev = 0; //when rev is already 1 and this function is called, then
        //we are reversing the reversed deque. then we will print the actual
        //deque.
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
    d.reverse_deque();
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
