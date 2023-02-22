#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *a; //by pointer we mean that we will allocate the memory later.
    //it's the dynamic array

    int stack_size;
    int cap;
    Stack() //when stack won't have anything in it, initial size has to be 0
    {
        a = new int[1]; //taking 1 sized array, allocating space from
        //memory by new int.
        stack_size = 0;
        cap = 1; //means the size of the array currently.
    }

    //Will make the array capacity(cap) double.
    void increase_size()
    {
        int *tmp; //here we will declare another temporary dynamic array
        //and it's size will be double of previous array.
        //now, previous array is being copied to the tmp array.
        //next, both of the arrays are getting swapped. a is getting tmp's
        //elements and tmp is getting a's. now we are deleting tmp.
        tmp = new int [cap*2];
        for(int i=0; i<cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete []tmp; //third bracket because we deleted an array
        cap = cap*2; //changing the capacity
    }

    //Add an element in the stack. O(1)
    void push(int val)
    {
        //lemme explain. suppose you are entering the first element in the stack.
        //[1]. now the stack_size is increasing by 1. and a[0]=1. if by this, the
        //stack_size gets equal to MAX_SIZE, 22th line's message will be shown.
        if(stack_size+1 > cap)
        {
            increase_size();
        }
        stack_size++;
        a[stack_size-1] = val;
    }

    //Delete the topmost element from the stack. O(1)
    void pop()
    {
        if(stack_size == 0)
        {
            cout<<"STACK IS EMPTY!!\n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size = stack_size - 1;
    }

    //Returns the top element from the stack
    void top ()
    {
        if(stack_size == 0)
        {
            cout<<"STACK IS EMPTY!!\n";
            return;
        }
        cout<<a[stack_size - 1]<<"\n";
    }
};

int main ()
{
    Stack st;
    st.push(3);
    st.top();
    st.push(4);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
    return 0;
}
