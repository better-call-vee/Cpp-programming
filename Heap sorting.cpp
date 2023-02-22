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

    void insert(int x)
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

    void build_from_array(vector<int>a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n/2 - 1;
        for(int i=last_non_leaf; i>=0; i--)
        {
            down_heapify(i);
        }
    }

    void deleto(int idx)
    {
        if(idx >= nodes.size()) return; //if the index doesn't exist in the heap
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }


    int ExtractMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty!\n";
            return -1;
        }
        int ret = nodes[0];
        deleto(0);
        return ret;
    }

    vector<int> heap_sort(vector<int>a)
    {
        MaxHeap h;
        h.build_from_array(a); //building the heap with the given array
        vector<int>ans;
        for(int i=0; i<a.size(); i++)
        {
            ans.push_back(h.ExtractMax()); //pushing the max and deleting the
            //current max.
        }
        reverse(ans.begin(),ans.end()); //reversing to get an increasing sort
        //array.
        return ans;
    }

};

int main ()
{
    MaxHeap heap;
    vector<int>inp = {1,2,3,4,10,9,8,7};
    heap.build_from_array(inp);
    heap.PrintHeap();
    vector<int>sorted_a = heap.heap_sort(inp);
    for(int i=0; i<sorted_a.size(); i++)
    {
        cout<<sorted_a[i]<<" ";
    }
    return 0;
}

