#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
public:
    Stack() {}

    void Push(const T& value)
    {
        PRIS.push(value);
    }

    T Pop()
    {
        auto top = PRIS.top();
        PRIS.pop();
        return top;
    }

    bool Empty() const
    {
        return PRIS.empty();
    }

private:
    stack<T>PRIS; //storing the data. STL stack.
};

int main()
{
    Stack<char> char_stack;
    Stack<int> int_stack;
    Stack<double> double_stack;

    char_stack.Push('a');
    int_stack.Push(42);
    double_stack.Push(3.14);

    while (!char_stack.Empty())
    {
        cout << char_stack.Pop() << "\n";
    }
    while (!int_stack.Empty())
    {
        cout << int_stack.Pop() << "\n";
    }
    while (!double_stack.Empty())
    {
        cout << double_stack.Pop() << "\n";
    }

    return 0;
}

