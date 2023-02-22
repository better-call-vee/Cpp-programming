//Supports push, top, pop, size.
//Queue was a linear DS but Priority Queue is a non-linear DS.
//push(x) => push the value x to priority queue O(logn) => insert(x)
//top(x)  => max value print O(1) => heap[0]
//pop(x)  => max value delete O(logn) => deleto(0)
//it's like implementing stack with linked list. linked list is like heap here.
//It's called priority queue because the max value containing one is popped
//first and gets a priority. it's like a ticket line, where the political leaders
//can take privilege.
#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int>nodes;

    Heap()
    {

    }

    void up_heapify(int idx)
    {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/2])
        {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    void inserto(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }

    void PrintHeap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }

    void down_heapify(int idx)
    {
        while(1)
        {
            int largest = idx;
            int l = 2*idx + 1;
            int r = 2*idx + 2;
            if(l<nodes.size() && nodes[largest] < nodes[l]) largest = l;
            if(r<nodes.size() && nodes[largest] < nodes[r]) largest = r;
            if(largest==idx) break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    int getMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty!\n";
            return -1;
        }
        return nodes[0];
    }


    void deleto(int idx)
    {
        if(idx >= nodes.size()) return; //if the index doesn't exist in the heap
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    int sizo()
    {
        return nodes.size();
    }

};

class PriorityQueue
{
public:
    MaxHeap pk;
    PriorityQueue () {}

    void push(int x)
    {
        pk.inserto(x);
    }

    void pop()
    {
        pk.deleto(0);
    }

    int top()
    {
        return pk.getMax();
    }

    int SIZE ()
    {
        return pk.sizo();
    }

};

int main ()
{
    PriorityQueue pq;
    pq.push(5);
    pq.push(7);
    pq.push(10);
    pq.push(1);
    pq.push(2);

    while(pq.SIZE()!=0)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
