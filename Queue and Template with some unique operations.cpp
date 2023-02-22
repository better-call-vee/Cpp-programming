#include<bits/stdc++.h>
using namespace std;

template<typename T>
class FTQ
{
public:
    T *marr;
    int capa, msz, head, tail;

    FTQ ()
    {
        marr = new T[1];
        capa = 1;
        msz = 0;
        head = 0;
        tail = -1;
    }

    void capainc()
    {
        T *tmp = new T[capa * 2];
        memcpy(tmp, marr, capa * sizeof(T)); //it copies the marr elements and
        //stores in tmp.
        swap(marr, tmp);
        capa = capa * 2;
        delete[]tmp;
    }

    void enFTQ (T inp)
    {
        if(msz == capa) capainc();
        tail = (tail + 1) % capa;
        marr[tail] = inp;
        msz++;
    }

    void deFTQ()
    {
        if(msz == 0)
        {
            throw "THE QUEUE IS EMPTY"; //it will show error
        }
        head = (head + 1) % capa;
        msz--;
    }

    //the modulo operator keeps track of the circular implementation.
//Consider a queue with a capacity of 5. The current values of head & tail are 0
//and 4 respectively. This means that the queue is full and the next element needs
//to be inserted at index 0 (overwriting the oldest element).
//head = 0;
//tail = 4;
//capa = 5;
//tail = (tail + 1) % capa;
///tail = (4 + 1) % 5 = 0;
//As we can see, after incrementing the value of tail by 1, (tail + 1) % capa
//gives us 0 which means that the next element will be inserted at index 0,
//overwriting the oldest element, and the tail index is pointing to index 0.
//Example 2:
//Consider a queue with a capacity of 5. The current values of head and tail are
//0 and 2 respectively. If we dequeue an element, we increment the value of head
//by 1.
//head = 0;
//tail = 2;
//capa = 5;
//head = (head + 1) % capa;
//// head = (0 + 1) % 5 = 1;
//As we can see, after incrementing the value of head by 1, (head + 1) % capa
//gives us 1 which means that the head index is now pointing to index 1 in the
//queue.

    T dafront()
    {
        if(msz == 0)
        {
            throw "NO FRONT FOUND, QUEUE IS EMPTY";
        }
        return marr[head];
    }
};

int main ()
{
    FTQ<char>cq;
    cq.enFTQ('I');
    cq.enFTQ('a');
    cq.enFTQ('m');
    cq.deFTQ();
    cq.deFTQ();
    cq.enFTQ('t');
    cq.enFTQ('6');
    cq.deFTQ();
    cq.deFTQ();
    cout<<"FRONT: "<<cq.dafront()<<"\n";
    return 0;
}

