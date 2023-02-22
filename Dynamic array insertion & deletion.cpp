//mechanism of vector from scratch

#include<bits/stdc++.h>
using namespace std;

class Array   ///memory complexity O(n)
{
private:
    int *arr;
    int cap;
    int sz;

    void Increase_size()
    {
        cap = cap*2;
        int *tmp = new int[cap];
        for(int i=0; i<sz; i++)
        {
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
    }

public:
    Array ()
    {
        arr = new int [1];
        cap = 1;
        sz = 0;
    }

    //time complexity total O(nlogn)
    void Push_back(int x)
    {
        if(cap == sz)
        {
            Increase_size();
        }
        arr[sz] = x;
        sz++;
    }

    //O(sz-pos) --> O(sz) worst case
    void Insert(int pos, int x)
    {
        if(cap==sz)
        {
            Increase_size();
        }
        for(int i=sz-1; i>=pos; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[pos] = x;
        sz++;
    }

    //O(n)
    void Print()
    {
        for(int i=0; i<sz; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    int getSize()   //O(1)
    {
        return sz;
    }

    int getElement(int idx)   //O(1)
    {
        if(idx>=sz)
        {
            cout<<"Error "<<idx<<" is out of bound!\n";
            return -1;
        }
        return arr[idx];
    }

    //sz=cap/2, then cap = cap/2
    void Pop_back() {
        if(sz==0) {
            cout<<"Current size is 0\n";
            return;
        }
        sz--;
    }

    void Erase (int pos) {
        if(pos>=sz) {
            cout<<"Position doesn't exist.\n";
            return;
        }
        for(int i=pos+1; i<sz; i++) {
            swap(arr[i-1], arr[i]);
        }
        sz--;
    }

};

int main ()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Print();
    a.Insert(2, 14);
    cout<<a.getSize()<<"\n";
    for(int i=0; i<a.getSize(); i++)
    {
        cout<<a.getElement(i)<<"\n";
    }
    a.Pop_back();
    a.Print();
    a.Pop_back();
    a.Print();
    a.Erase(1);
    a.Print();
}

//The worst-case time complexity of an algorithm is the function that gives the
//maximum number of steps an algorithm takes to complete, given the input size.
//It is usually represented using big O notation, which gives an upper bound on
//the number of steps the algorithm takes. The worst-case time complexity is
//important because it gives an idea of how the algorithm will perform when given
//the worst possible input. For example, if an algorithm has a worst-case time
//complexity of O(n^2), it means that the number of steps the algorithm takes
//grows at most quadratically with the size of the input. This can be useful
//for determining how well an algorithm will scale as the input size increases.
