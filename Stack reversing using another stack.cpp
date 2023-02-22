#include<bits/stdc++.h>
using namespace std;

template<class T>

class node
{
public:
    T data;
    node *nxt;
    node *prv;
};

template<class T>
class DoublyLinkedList
{
public:
    node <T> *head; //because node has been implemented template based with T
    //14th line: the template is T, so in the angle brackets we have to write
    //T.
    int sz;
    DoublyLinkedList()   //constructor
    {
        head = NULL;
        sz = 0;
    }

    ///CREATES A NEW NODE WITH THE GIVEN DATA.
    node <T> *CreateNewNode(T data)
    {
        node <T> *newnode = new node <T>;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void InsertAtHead(T data)
    {
        sz++;
        node <T> *newnode = CreateNewNode(data);
        if(head == nullptr) //if the linked list is empty or not.
        {
            head = newnode;
            return; //work is done here if the linked list got no elements
            //previously
        }
        node <T> *a = head; //now we know that the head isn't null, now we are taking
        //a variable named 'a' which is pointing to head.
        newnode->nxt = a;//newnode's nxt is pointing to a's address which was
        //previously assigned as head
        a->prv = newnode;//and now, the previous head's previous pointer is being
        //assigned to newnode's address.
        head = newnode; //now head's being assigned to that newnode. done bitch
    }

    void Traverse (node <T> *head)
    {
        if(head == nullptr) return;
        cout<<head->data<<" ";
        Traverse(head->nxt);
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {
            return;
        }
        node <T> *a = head;
        node <T> *b = head->nxt;
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

template<class T>
class Stack
{
public:
    DoublyLinkedList<T> dl;
    Stack()
    {

    }

    T top ()
    {
        if(dl.getSize()==0)
        {
            cout<<"Stack is empty!\n";
            T a = 69;
            return a;
        }
        cout<<dl.head->data<<"\n";
    }

    void push(T val)
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

    int getSize() {
        return dl.getSize();
    }

};
int main ()
{
    //Reverse a stack using another stack
    Stack<int>a;
    a.push(4);
    a.push(6);
    a.push(3);
    a.push(7);

    //so, now a => [4,6,3,7]
    //now, tmp is being pushed by a's top elements. and the top element of a
    //is being removed
    //finallay tmp => [7,3,6,4]. now we will swap a and tmp.
    Stack<int>tmp;
    while(a.getSize()>0)
    {
        tmp.push(a.top());
        a.pop();
    }
    swap(a, tmp);
    DoublyLinkedList<int>dll;
    dll.Traverse(dll.head);
    return 0;
}
