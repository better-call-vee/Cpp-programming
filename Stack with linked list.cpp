#include<bits/stdc++.h>
using namespace std;
//head/root is the top now
//top element delete means deletehead.
//push means insertathead.
//everything will be done in O(1)

class node
{
public:
    int data;
    node *nxt;
    node *prv;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()   //constructor
    {
        head = NULL;
        sz = 0;
    }

    ///CREATES A NEW NODE WITH THE GIVEN DATA.
    node *CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == nullptr) //if the linked list is empty or not.
        {
            head = newnode;
            return; //work is done here if the linked list got no elements
            //previously
        }
        node *a = head; //now we know that the head isn't null, now we are taking
        //a variable named 'a' which is pointing to head.
        newnode->nxt = a;//newnode's nxt is pointing to a's address which was
        //previously assigned as head
        a->prv = newnode;//and now, the previous head's previous pointer is being
        //assigned to newnode's address.
        head = newnode; //now head's being assigned to that newnode. done bitch
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {
            return;
        }
        node *a = head;
        node *b = head->nxt;
        if(b != nullptr) //if previous head's next is not null then it will be
        //the new head. otherwise the list will be empty.
            b->prv = nullptr;
        head = b;
        delete a; //our main work was to delete head which was set to a.
        sz--;
    }


    int getSize()
    {
        return sz;
    }
};
class Stack
{
public:
    DoublyLinkedList dl;
    Stack()
    {

    }

    void top ()
    {
        if(dl.getSize()==0)
        {
            cout<<"Stack is empty!\n";
            return;
        }
        cout<<dl.head->data<<"\n";
    }

    void push(int val)
    {
        dl.InsertAtHead(val);
    }

    void pop()
    {
        if(dl.getSize()==0)
        {
            cout<<"Stack is Empty!\n";
            return;
        }
        dl.deleteAtHead();
    }
};

int main ()
{
    Stack st;
    st.push(3);
    st.top();
    st.push(4);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
    return 0;
}
