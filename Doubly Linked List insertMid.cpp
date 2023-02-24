#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node *prev;
};

class Doublyll
{
public:
    node *head;
    node *tail;
    int sz;

    Doublyll()
    {
        head = nullptr;
        tail = nullptr;
        sz=0;
    }

    node *createnew (int value)
    {
        node *newnode = new node;
        newnode->val = value;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        return newnode;
    }

    void insertHead(int value)
    {
        sz++;
        node *a = createnew(value);
        if(head==nullptr)
        {
            head = a;
            tail = a;
            return;
        }
        else
        {
            node *b = head;
            b->prev = a;
            a->next = b;
            head = a;
        }
    }

    void insertTail(int value)
    {
        sz++;
        node *a = createnew(value);
        if(tail==nullptr)
        {
            head = a;
            tail = a;
            return;
        }
        else
        {
            node *b = tail;
            b->next = a;
            a->prev = b;
            tail = a;
        }

    }

    void insertMid(int value)
    {
        node *a = createnew(value);
        if(head==nullptr)
        {
            head = a;
            tail = a;
            sz++;
            return;
        }
        else
        {
            node *b = head;
            for(int i=0; i<(sz/2)-1; i++)  //to find the middle we follow this
            //condition.
            {
                b = b->next;
            }
            a->prev=b;
            a->next=b->next;
            if(b->next != nullptr) b->next->prev = a;
            b->next=a;
        }
        sz++;
    }
//or it can be implemented like this:
//void insertMid(int value)
//{
//    node *a = createnew(value); // create a new node with the given value
//    if (head == nullptr) // if the list is empty
//    {
//        head = a; // make the new node the head and tail of the list
//        tail = a;
//        sz++; // increment the size of the list
//        return;
//    }
//    else if (head->next == nullptr) // if the list has only one node
//    {
//        head->next = a; // make the new node the next node of the head
//        a->prev = head; // make the head the previous node of the new node
//        tail = a; // make the new node the tail of the list
//    }
//    else // if the list has two or more nodes
//    {
//        node *slow = head; // initialize the slow pointer to the head of the
          ////list
//        node *fast = head->next; // initialize the fast pointer to the second
          //// node of the list
//        while (fast != nullptr && fast->next != nullptr) // move the fast
//pointer two steps at a time and the slow pointer one step at a time until the
//end of the list is reached
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        a->prev = slow; // make the slow pointer the previous node of the new
          ////node
//        a->next = slow->next; // make the next node of the slow pointer the
          ////next node of the new node
//        if (slow->next != nullptr) slow->next->prev = a; // if the next node of
////the slow pointer is not null, make the previous node of the next node the
////new node
//        slow->next = a; // make the new node the next node of the slow pointer
//        if (a->next == nullptr) tail = a; // if the next node of the new node
////is null, make the new node the tail of the list
//    }
//    sz++; // increment the size of the list
//}

//this slow node move one node at a time while the fast moves 2 at a time.By
//using two pointers, one moving at half the speed of the other, we can find
//the middle node in a single traversal of the linked list.


    void traverse()
    {
        node *a = head;
        while(a!=nullptr)
        {
            cout<<a->val<<" ";
            a = a->next;
        }
    }

};

int main()
{
    Doublyll dll;
    dll.insertHead(4);
    dll.insertTail(9);
    dll.insertHead(2);
    dll.insertHead(3);
    dll.insertMid(7);
    dll.traverse();
    return 0;
}

