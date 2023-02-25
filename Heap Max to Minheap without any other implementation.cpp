#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int>mh;
    void up_heapify(int i)
    {
        while(i>0 && mh[i]>mh[(i-1)/2])
        {
            swap(mh[i], mh[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void insert(int value)
    {
        mh.push_back(value);
        up_heapify(mh.size()-1);
    }
    void down_heapify(int i)
    {
        while(1)
        {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;
            if(l<mh.size() && mh[l]>mh[largest]) largest=l;
            if(r<mh.size() && mh[largest]<mh[r]) largest=r;
            if(largest==i) break;
            swap(mh[largest], mh[i]);
            i = largest;
        }
    }
    void Delete(int i)
    {
        if(i>mh.size()) return;
        swap(mh[i], mh[mh.size()-1]);
        mh.pop_back();
        down_heapify(i);
    }
};

class MinHeap
{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.insert(-x); //this will make the maximum value negative which will
        //be the minimum in the maxheap. so, reverse done
    }
    void Delete(int idx)
    {
        mx.Delete(idx);
    }
    int getMin()
    {
        if(mx.mh.empty()) return -1;
        return -mx.mh[0];
    }

    void print()
    {
        for(auto val : mx.mh)
        {
            cout<<-val<<" ";
        }
    }
};

int main ()
{
    MinHeap mn;
    mn.insert(2);
    mn.insert(4);
    mn.insert(9);
    mn.insert(21);
    mn.insert(1);
    mn.Delete(0);
    cout<<"The minimum node of the MinHeap is: "<<mn.getMin()<<"\n";
    cout<<"Printing the MinHeap: ";
    mn.print();
    return 0;
}

