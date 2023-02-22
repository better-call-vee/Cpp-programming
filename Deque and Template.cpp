#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node
{
public:
    T data;
    node *prv;
    node *nxt;
};
template<typename T>
class Deque
{
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    int rev;

    Deque ()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
        rev = 0;
    }

    node<T> *CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode -> data = value;
        newnode -> prv = nullptr;
        newnode -> nxt = nullptr;
        return newnode;
    }

    void InsertAtTail (T value)
    {
        node<T> *newnode = CreateNewNode(value);
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

    void InsertAtHead(T value)
    {
        node<T> *newnode = CreateNewNode(value);
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

    void push_back(T value)
    {
        if(rev == 0) InsertAtTail(value);
        else InsertAtHead(value);
    }

    void push_front(T value)
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
        node<T> *a = tail;
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
        node<T> *a = head;
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

    T front ()
    {
        if(sz==0) return -1;
        if(rev==0) return head->data;
        else return tail->data;
    }

    void pgood()
    {
        node<T> *a = head;
        while(a!=nullptr)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    void pReverse()
    {
        node<T> *temp = head;
        if (temp == nullptr)
            return;

        if (temp->nxt != nullptr)
        {
            head = temp->nxt;
            pReverse();
        }
        cout << temp->data << " ";
        head = temp;
    }

    T getMax()
    {
        node<T> *temp = head;
        T maxVal = head->data;
        while (temp != nullptr)
        {
            maxVal = max(maxVal, temp->data);
            temp = temp->nxt;
        }
        return maxVal;
    }

    T getMin()
    {
        node<T> *temp = head;
        T minVal = head->data;
        while (temp != nullptr)
        {
            minVal = min(minVal, temp->data);
            temp = temp->nxt;
        }
        return minVal;
    }

    void print()
    {
        if(rev==0) pgood();
        else
        {
            pReverse();
            cout<<"\n";
        }
    }

    T back ()
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
    Deque<int>dq;
    for(;;)
    {
        string inp;
        int p;
        cin>>inp;
        if(inp=="pb") dq.pop_back();
        else if(inp=="fp") dq.pop_front();
        else if(inp=="puff")
        {
            cin>>p;
            dq.push_front(p);
        }
        else if(inp=="pusb")
        {
            cin>>p;
            dq.push_back(p);
        }
        else if(inp=="rev") dq.reverse_deque();
        else if(inp=="break")
        {
            dq.print();
            break;
        }
        dq.print();
    }
    cout<<"MAX: "<<dq.getMax()<<" & MIN: "<<dq.getMin();
    return 0;
}

