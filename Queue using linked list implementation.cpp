
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *nxt;
};

class Queue
{
public:
    node *head;
    node *tail;
    int sz;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    node *CreateNode(int value)
    {
        node *newnode = new node;
        newnode -> data = value;
        newnode -> nxt = nullptr;
        return newnode;
    }

    void enqueue(int value)
    {
        sz++; //enqueuing needs to increase size
        node *newnode = CreateNode(value); //needs a new node as well.
        if(head == nullptr)
        {
            head = newnode; //empty linked list's head and tail will be the
            //same if we enqueue.
            tail = newnode;
            return;
        }
        tail -> nxt = newnode;
        tail = newnode;
        //suppose, we have 2 elements in the linked list. (10)1[20] -> (20)2[NULL]
        //now, we will enqueue 5 with an address of 70.
        //(10)1[20] -> (20)2[70] -> (70)5[NULL].
    }

    void dequeue()
    {
        if(sz == 0)
        {
            cout<<"QUEUE IS EMPTY!\n";
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
        head = head -> nxt;
        delete a;
        sz--;
    }

    int front () {
        if(sz==0) {
            cout<<"NO FRONT means -1!\n";
            return -1;
        }
        return head -> data;
    }

    int size () {
        return sz;
    }

};

int main () {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout<<"Q size: "<<q.size()<<"\n";
    cout<<"Front: "<<q.front()<<"\n";
    q.dequeue();
    cout<<"After Dequeuing, Front: "<<q.front()<<"\n";
    q.dequeue();
    cout<<"After Dequeuing, Front: "<<q.front()<<"\n";
    q.dequeue();
    cout<<"After Dequeuing, Front: "<<q.front()<<"\n";
    cout<<"Q size: "<<q.size()<<"\n";
    return 0;
}
