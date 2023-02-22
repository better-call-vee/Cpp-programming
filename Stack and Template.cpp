///STACK FOR ANY DATA TYPE, ANY CLASS.
///vector<int>a; <..> this is template.

//In C++, a template is a feature that allows the creation of generic functions and
//classes. Templates enable the developer to write code that can work with any data
//type, without the need to specify the type at the time of writing the code.
//Instead, the type is specified at the time of instantiation, or when the
//template is used in a program. This allows for greater flexibility and code
//reuse. Templates are defined using the keyword "template" followed by angle
//brackets <> containing the template parameters.

#include<bits/stdc++.h>
using namespace std;
template<class T> //template's function is more like #define.
class Stack
{
public:
    T *a;
//  int *a; we are changing this int to any type of data type.

    int stack_size; //size and cap type can't be changed because they're integers
    int cap;
    Stack()
    {
        a = new T[1];
        stack_size = 0;
        cap = 1;
    }


    void increase_size()
    {
        T *tmp;
        tmp = new T[cap*2];
        for(int i=0; i<cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete []tmp;
        cap = cap*2;
    }

    void push(T val)
    {
        if(stack_size+1 > cap)
        {
            increase_size();
        }
        stack_size++;
        a[stack_size-1] = val;
    }

    void pop()
    {
        if(stack_size == 0)
        {
            cout<<"STACK IS EMPTY!!\n";
            return;
        }
//      a[stack_size - 1] = 0; we can't do this because the data type is not
//      specific.
        stack_size = stack_size - 1;
    }

    T top ()
    {
        if(stack_size == 0)
        {
            cout<<"STACK IS EMPTY!!\n";
            //assert(false); program crashing syntax
            T a = 69;
            return a;
        }
        cout<<a[stack_size - 1]<<"\n";
    }
};

int main ()
{
    Stack<double>st; //here double is the value of T. everywhere there is written
    //T, is being replaced by double.
    st.push(3.5);
    st.push(3.6);
    st.push(7.8);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
    st.pop();
    cout<<st.top()<<"\n";

    Stack<char>st2;
    st2.push('a');
    st2.push('g');
    st2.push('u');
    st2.top();
    st2.pop();
    st2.top();

    return 0;
}
