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
            exit(0);
//exit(0) is a function in the standard library of C++ that terminates the
//program. The argument 0 passed to the exit function indicates a successful
//termination. It returns control to the operating system with an exit status
//of 0, which typically means that the program has completed successfully. In
//other words, exit(0) is used to exit the program and return a status of 0 to
//the operating system, indicating that the program has run successfully.
        }
        return dl.head->data;
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
};

int main ()
{
    Stack<double>st; //here double is the value of T. everywhere there is written
    //T, is being replaced by double.
    st.push(3.5);
    st.push(3.6);
    st.push(7.8);
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";

    Stack<char>st2;
    st2.push('a');
    st2.push('g');
    st2.push('u');
    cout<<st2.top()<<"\n";
    st2.pop();
    cout<<st2.top()<<"\n";
    return 0;
}
