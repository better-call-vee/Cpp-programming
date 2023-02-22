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
    T top ()
    {
        if(dl.getSize()==0)
        {
            cout<<"Stack is empty!\n";
            T a = T();
            return a;
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

    int getSize()
    {
        return dl.getSize();
    }
};

int main ()
{
    Stack <int> st;
    st.push(5);
    st.push(2);
    st.push(7);

    //lemme explain. the input: [7,2,5]. 7 is the top.
    //st's size is now 3. int t is getting 7 as value input. and st is getting
    //a value popped. now st is [2,5]. now tmp has size 0, so second while
    //loop won't be executed. now tmp will be pushed with the value 7.
    //now 2 will be set to t. and now we will enter the second while loop
    //because it has now size of 1.here it will check if tmp's top is greater than
    //this t which is set to 2 now. so,yeah, it's true,the while loop will be
    //broken now.now this t will be pushed to tmp.next 5. but tmp's top, which
    //is now 2 is not greater than 5. now this 2 bitch will be popped and pushed
    //to st and tmp's new top bitch will 7. yeah baby, we got it right. like this,
    //now t=5 will be pushed to tmp. and then the poor bitch 2 will pushed at last.
    //done yo.

    Stack <int> tmp;
    while(st.getSize()>0)
    {
        int t = st.top();
        st.pop();
        while(tmp.getSize()>0)
        {
            if(tmp.top()>t) break;
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(t);
    }
    swap(st,tmp);
    while(st.getSize()>0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
