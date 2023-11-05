#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printStack(stack<T> stk)
{
    stack<T> temp;

    while (!stk.empty())
    {
        T topElement = stk.top();
        cout << topElement << ' ';
        temp.push(topElement);
        stk.pop();
    }
    cout << '\n';

    while (!temp.empty())
    {
        stk.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<int> st, st2;
    st.push(2);
    st.push(7);
    st.push(8);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    st2.push(3);
    st2.push(1);
    st2.push(6);
    st2.push(9);

    printStack(st);
    printStack(st2);

    cout << "\nAfter Swapping: \n";
    st.swap(st2);

    printStack(st);
    printStack(st2);

    return 0;
}
