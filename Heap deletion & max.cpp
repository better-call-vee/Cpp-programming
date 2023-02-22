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
//            10
//          /    \
//         6      7
//       /   \   /  \
//      1     2 5    4
//suppose we want to delete the root. so we will swap the last element of the
//vector with root. now we will pop back the last element.
//            4
//          /   \
//         6     7
//       /  \   /
//      1    2 5
//now we will call down_heapify with the index which is 0;
//we will enter a infinite while loop. before that we will set the left
//of it to l, and right to r. now we are checking if the left child exists or not
//by l<nodes.size(). currently our largest is set to idx and which is 0 and l(6)
//is greater than largest set index(4). so, now largest will be set to left's
//index(value 6, index = 1). Then it will enter the next if. we can see that,
//7 is greater than 6. so, now largest will be set to 2. and eventually largest
//will be set to 2 & idx is 2 also and 7<->4 will be swapped.
//            7
//          /   \
//         6     4
//       /  \   /
//      1    2 5
//now, largest is 2 and value is 4. there is no right child of it so second if
//will not be executed. but for the left child, l's value is greater than largest's
//so finally, they will be swapped and largest is now 6 so as idx.
//now the while loop will be broken because largest will remain equivalent to
//idx after the if statements.
//            7
//          /   \
//         6     5
//       /  \   /
//      1    2 4
    void deleto(int idx)
    {
        if(idx >= nodes.size()) return; //if the index doesn't exist in the heap
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
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

    //O(logn) because deleto takes logn complexity
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

};

int main ()
{
    MaxHeap heap;
    heap.insert(4);
    heap.insert(7);
    heap.insert(9);
    heap.insert(1);
    heap.insert(10);
    heap.PrintHeap();
    heap.deleto(1);
    heap.PrintHeap();
    cout<<"Max element = "<<heap.getMax()<<"\n";
    heap.ExtractMax();
    cout<<"Extracting max, now Max = "<<heap.getMax();
    return 0;
//           10
//         /    \
//        9      7
//       / \
//      1   4

//           10
//         /    \
//        4      7
//       /
//      1
}
