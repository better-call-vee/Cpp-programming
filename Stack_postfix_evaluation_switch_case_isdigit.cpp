#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char ex)
{
    if (ex == '+' || ex == '-')
        return 1;
    else if (ex == '*' || ex == '/')
        return 2;
    return 0;
}

string infixToPostfix(string in)
{
    stack<char> stk;
    string postfix = "";

    for (int i = 0; i < in.size(); i++)
    {
        char curr = in[i];
        if (isdigit(curr)) // Handle multi-digit numbers
        {
            while (i < in.size() && isdigit(in[i]))
            {
                postfix += in[i];
                i++;
            }
            i--;            // Decrement i to account for the last increment in the loop
            postfix += ' '; // Add space to separate numbers in postfix expression
        }
        else if (curr == '(')
            stk.push(curr);
        else if (curr == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (!stk.empty() && prec(stk.top()) >= prec(curr))
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(curr);
        }
    }

    while (!stk.empty())
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
        char curr = post[i];
        if (isdigit(curr)) // isdigit is a builtin function which checks
        // if the character is a digit or not.
        {
            int num = 0;
            while (i < post.size() && isdigit(post[i]))
            {
                num = num * 10 + (post[i] - '0');
                i++; //suppose a number 56. first we get 5 as num. then secondly, when we get 6,
                //5*10 + 6 = 56. yo biatch
            }
            i--; // Decrement i to account for the last increment in the loop which will eventually 
            //end up on the character. but after ending the rest commands, we will go to the for 
            //loop which will increase i, so if we don't do this decrement, eventually i will be
            //incremented by 2.
            result.push(num); 
        }
        else if (curr == ' ') // Skip space characters between numbers in postfix expression
            continue;
        else
        {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            switch (curr) // Use the current character (operator) to perform the operation
            {
            case '+':
                result.push(b + a);
                break;
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

    return 0;
}

/*
Infix Expression: 2*(56+3)*4/2

Initialize an empty stack and an empty postfix string.

Process the infix expression character by character:

Character '2': It is a digit, so we add it to the postfix string.
Character '*': It is an operator, so we push it onto the stack.
Character '(': It is an opening parenthesis, so we push it onto the stack.
Characters '5', '6', '+', '3': They are digits and an operator, forming the sub-expression (56+3).
Character ')': It is a closing parenthesis. So, we pop operators from the stack and append them to the
 postfix string until we encounter the matching opening parenthesis '(' on the stack. The postfix 
 string becomes "2563+".
Character '': It is an operator, and its precedence is higher than the operator on top of the stack 
(' > +'). So, we push '*' onto the stack.
Character '4': It is a digit, so we add it to the postfix string.
Character '/': It is an operator, and its precedence is higher than the operator on top of the stack
 ('/ > *'). So, we push '/' onto the stack.
Character '2': It is a digit, so we add it to the postfix string.
Now, we have processed the entire infix expression. The stack is not empty, so we pop the remaining
 operators from the stack and append them to the postfix string. The postfix string becomes 
 "2563+*42/".

The final postfix expression is "2563+*42/".

Now, let's evaluate this postfix expression using the evaluatePostfix function:

Initialize an empty stack.

Process the postfix expression character by character:

Character '2': It is a digit, so we push it onto the stack.
Character '5': It is a digit, so we push it onto the stack.
Character '6': It is a digit, so we push it onto the stack.
Character '3': It is a digit, so we push it onto the stack.
Character '+': It is an operator. We pop the top two elements from the stack (3 and 6), perform
 the addition (6+3=9), and push the result (9) back to the stack.
Character '': It is an operator. We pop the top two elements from the stack (9 and 5), perform
 the multiplication (59=45), and push the result (45) back to the stack.
Character '4': It is a digit, so we push it onto the stack.
Character '2': It is a digit, so we push it onto the stack.
Character '/': It is an operator. We pop the top two elements from the stack (2 and 4), perform
 the division (4/2=2), and push the result (2) back to the stack.
Now, we have processed the entire postfix expression. The stack contains the final result, which is 2.

So, the result of the expression "2*(56+3)*4/2" is 2, which is correctly evaluated using the postfix 
expression. The conversion from infix to postfix ensures that the correct order of operations is
 followed during the evaluation.




SIMULATE to understand.
*/