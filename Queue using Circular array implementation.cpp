#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *a;
    int array_cap;
    int l, r; //l is the start of the queue, r is the end.
    int sz;

    Queue()
    {
        a = new int[1];
        array_cap=1;
        l = 0;   //suppose, the array has 2 elements [2,3]. here 2 will be l and
        //r will be 3.
        r = -1; //suppose, the array is empty now and we will enqueue element. after
        //enqueuing first element(let's insert 5), the array will be [5].
        //now, we will increase r by 1. so, if it was not set to -1 previously, it
        //won't work properly.
        //here we need to maintain size.
        sz = 0;
    }

    void remove_circular ()
    {
        if(l>r)   //circular nature will exist only when l is greater than r.
        {
            int *tmp = new int[array_cap];
            int idx = 0;
            for(int i=l; i<array_cap; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }
            swap(tmp,a);
            l = 0;
            r = array_cap-1; //description stated below
            delete [] tmp;
        }
    }

    //when size will reach the array capacity, then we will increase the size.
    //we have to fix the circular nature while increasing size.
    //so, previously if it is [10,11,12,8,9], where 12 =r, 8=l. we will make
    //this [8,9,10,11,12], where r and l will be the same as previous.
    //otherwise, r and l will clash
    void increase_size()
    {
        remove_circular();
        int *tmp = new int[array_cap*2];
        for(int i=0; i<array_cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a,tmp);
        array_cap = array_cap*2;
        delete[]tmp;
    }

    //O(1)
    //for static,
    //suppose, we have a queue named a[5,6,7,8,9]. now, we have dequeued 5,6,7
    //from this. now we have [0,0,0,8,9]. we will enqueue 10,11,12. For this, we
    //will follow the circular array implementation.
    //so,we will implement like this [10,11,12,8,9]. Here, l is 8 and r is 12.
    //when r was 9, and we are enqueuing another element(10), r is being set to
    //0. look at the enqueue function(38th line).
    void enqueue(int value)
    {
        if(sz==array_cap)
        {
            increase_size();
        }

        r++;
        if(r==array_cap) r=0;
        a[r] = value;
        sz++;
    }

    //after dequeuing 8 and 9 from the queue, the l will move to value 10, then
    //l will be 0.
    //[10,11,12,0,0]
    //  l     r
    void dequeue()
    {
        if(sz==0)
        {
            cout<<"QUEUE IS EMPTY, can't dequeue!\n";
            return;
        }
        l++; //for every deleting operation, l is moving forward to right.
        if(l==array_cap) l=0;
        sz--;
    }

    int front ()
    {
        if(sz == 0)
        {
            cout<<"QUEUE IS EMPTY\n";
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return sz; //or, return n-l+r+1;
    }

};

int main ()
{
    Queue q;
    int n;
    for(;;)
    {
        cin>>n;
        if(n==69) break;
        else if (n==88) q.dequeue();
        else q.enqueue(n);
        cout<<"QUEUE SIZE IS NOW: "<<q.size()<<"\n";
        if(q.front()==-1) cout<<"THERE IS NO FRONT NOW!\n";
        else cout<<"THE FRONT IS NOW: "<<q.front()<<"\n";
    }
    return 0;
}

