#include <bits/stdc++.h>
using namespace std;

int prec(char ex)
{
    if (ex == '+' || ex == '-') return 1;
    else if (ex == '*' || ex == '/') return 2;
    return 0;
}

string infixToPostfix(string in)
{
    stack<char> stk;
    string postfix = "";

    for (int i = 0; i < in.size(); i++)
    {
        char curr = in[i];
        if (curr >= '0' && curr <= '9') postfix += curr;
        else if (curr == '(') stk.push(curr);
        else if (curr == ')')
        {
            while (stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (stk.size() && prec(stk.top()) >= prec(curr))
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(curr);
        }
    }

    while (stk.size())
    {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int evaluatePostfix(string post)
{
    stack<int> result;

    for (int i = 0; i < post.size(); i++)
    {
        if (isdigit(post[i])) //isdigit is a builtin function which checks
            //if the character is a digit or not.
        {
            int num = 0;
            while (isdigit(post[i]))
            {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            i--;//The while loop continues as long as the condition is true, i.e.,
//isdigit(post[i]) returns true. When isdigit(post[i]) returns false, the loop
//terminates and i is decremented by 1 to account for the fact that i will be
//incremented by 1 in the next iteration of the for loop. This is done because
//the for loop will increment i again in the next iteration, which would cause
//it to skip the next character in the post string. By decrementing i by 1 after
//the while loop, the next iteration of the for loop will correctly process the
//next character in the post string.
            result.push(num);
//The code is checking if the character at the current index i in the postfix
//string is a digit. If it is, it uses a while loop to continue processing all
//the consecutive digits together and convert them into a single number.
//
//For example, let's say the postfix string is "24+56+*", and the current index
//i is 0. The first character of the postfix string is '2', which is a digit.
//So, the code inside the if statement will be executed. The num variable will
//be initialized to 0, and then the while loop will run as long as the current
//character post[i] is a digit. In this case, post[i] is '2', which is a digit,
//so the loop will run once. The num variable will be updated to num * 10 +
//(post[i] - '0'), which is 0 * 10 + (2 - '0') = 2. The value of i will be
//incremented by 1. Now, post[i] is '4', which is also a digit. The while loop
//will run again and update the value of num to num * 10 + (post[i] - '0'),
//which is 2 * 10 + (4 - '0') = 24. Since the next character is not a digit,
//the while loop will exit. Finally, the value of num, which is 24, will be
//pushed onto the result stack.
//In this way, the code handles multi-digit numbers in the postfix expression.
        }
        else
        {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            char op = post[i];
            switch (op)
            {
            case '+':
                result.push(b + a);
                break;
//The calculation should start with b instead of a, since b is the second number
//to be popped from the stack. This is because postfix expression evaluates from
//left to right.
            case '-':
                result.push(b - a);
                break;
            case '*':
                result.push(b * a);
                break;
            case '/':
                if (a == 0)
                {
                    cout << "Division by zero error" << endl;
                    exit(0);
                }
                result.push(b / a);
                break;
            default:
                cout << "Invalid operator" << endl;
                exit(0);
                break;
            }
        }
    }

    return result.top();
}

int main()
{
    string in;
    cin >> in;

    string post = infixToPostfix(in);
    cout << "Postfix: " << post << endl;

    int result = evaluatePostfix(post);
    cout << "Result: " << result << endl;

    return 0
