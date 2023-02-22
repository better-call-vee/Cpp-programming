#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;
class Queue
{
public:
    int a[MAX_SIZE];
    int l, r; //l is the start of the queue, r is the end.

    Queue() {
        l = 0;   //suppose, the array has 2 elements [2,3]. here 2 will be l and
        //r will be 3.
        r = -1; //suppose, the array is empty now and we will enqueue element. after
        //enqueuing first element(let's insert 5), the array will be [5].
        //now, we will increase r by 1. so, if it was not set to -1 previously, it
        //won't work properly.
    }

    //O(1)
    void enqueue(int value) {
        if(r+1 >= MAX_SIZE) {
            cout<<"QUEUE IS FULL\n";
            return;
        }
        r=r+1;
        a[r] = value;
    }

    void dequeue() {
        if(l > r) {   //when l is greater than r, the queue got no elements.
            cout<<"QUEUE IS EMPTY\n";
            return;
        }
        l++; //for every deleting operation, l is moving forward to right.
    }

    int front () {
        if(l>r) {
            cout<<"QUEUE IS EMPTY\n";
            return -1;
        }
        return a[l];
    }

    int size() {
        return (r-l+1);
    }

};

int main () {
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout<<"QUEUE SIZE IS NOW: "<<q.size()<<"\n";
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    cout<<"QUEUE SIZE IS NOW: "<<q.size()<<"\n";
    cout<<"THE FRONT IS NOW: "<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front();
    return 0;
}
