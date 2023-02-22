#include<bits/stdc++.h>
using namespace std;
const int maxsize = 10; //that means we will not change the MAX_SIZE variable
template<class T>
class Stack
{
public:
    T a[maxsize];
    int stsize;
    Stack ()
    {
        stsize = 0; //when stack won't have anything in it, initial size has to
        //be 0
    }

    //Add an element in the stack. O(1)
    void push(T val)
    {
        //lemme explain. suppose you are entering the first element in the stack.
        //[1]. now the stack_size is increasing by 1. and a[0]=1. if by this, the
        //stack_size gets equal to MAX_SIZE, 22th line's message will be shown.
        if(stsize+1>maxsize)
        {
            printf("STACK IS FULL!\n");
            return;
        }
        stsize++;
        a[stsize-1] = val;
    }

    //Delete the topmost element from the stack. O(1)
    void pop()
    {
        if(stsize==0)
        {
            printf("BITCH, STACK IS EMPTY!\n");
            return;
        }
        stsize--;
        a[stsize] = 0;
    }

    //Returns the top element from the stack
    T top ()
    {
        if(stsize==0)
        {
            printf("BITCH, STACK IS EMPTY!\n");
            T a = T();
            return a;
        }
        return a[stsize-1];
    }

};

int main ()
{
    Stack<int>st;
    string inp;
    for(;;) //infinite for loop
    {
        cin>>inp;
        if(inp == "pop")  //for string check, we need to use double quotation.
            //for single character, single quotation.
        {
            st.pop();
        }
        else if(inp == "break")
        {
            printf("THANK YOU, THE PROGRAM IS EXITING...");
            break;
        }
        else
        {
            int fin = stoi(inp); //converts a string into an integer.
            st.push(fin);
        }
        if(st.stsize!=0)
        {
            cout<<"THE TOP ELEMENT IS: "<<st.top()<<'\n';
        }
    }
    return 0;
}
