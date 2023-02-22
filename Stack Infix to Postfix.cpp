//a + b => a and b are the operands, + is the operator
//a+b is an infix expression. ab+ is a postfix expression

//a + b x c + d => a + t1 + d => t2 + d => t3
//multiplication's precedence is the greatest here. it will be calculated first.
//BODMAS.

//we have to do the same thing with programming and computer. that's why there
//is postfix expression.
//abc*+d+. 4th line's postfix.
//look, here the first precedence operator will be *(multiplication). the operands
//will be with the operator. so bc*.
//result => at1+d+, where t1 = b*c
//now at1+ is a+b*c, which will be t2. and finally t2 will be added with d.

//implementing postfix expression with stack. we will push elements serially until
//the elements are operands. for the 10th line, first a, then b, then c.
//pushed all three. then
//we got *, the previous two elements will be popped now, because they're the
//operands of this operator. b*c = t1. we are pushing now t1 and those b & c are
//popped already. then we got +, a and t1. now a and t1 are getting popped
//t2 is being pushed. then d is being pushed. got +. previous two operands are
//t2 and d. they will be popped, result will be t3.

//infix is really hard for computer, so we need to go from infix to postfix
//here + and - has same strength of precedence, and / and * has the same.

//a+b*c+d
//we are taking a string named result where we will store the postfix format of
//this infix format. And taking a stack, st also.
//operands are generally being pushed to result. and the operators are generally
//being pushed to stack.
//first, a => being pushed to result. result[a]
//+, being pushed to stack, st is empty already.so no checks needed
//b, being pushed to result. result[ab]
//*, being pushed to stack. multiplication has more precedence. so it will be pushed
//now, c, result[abc]
//+, so, stack has a top of *, which has more precedence than a +. now, this more
//precedence * will be popped and pushed to result. now + and + have same precedence
//if they even have same precendence, it will be pushed to result now(the top +)
//and the + before d will be pushed to stack now.
//then d will be pushed to result and at last the plus will be pushed to result
//done.


#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if(ch == '+' || ch == '-') return 0;
    else return 1;  //precedence is setting the strength of the operators.
    //*,/ =1. +,- = 0.
}

int main ()
{
    string s;
    cin>>s; //taking infix expression input
    stack<char>st;
    string ans = "";

    for(int i=0; i<s.size(); i++)
    {
        char now = s[i]; //scanning the string from start.
        if(now >= 'a' && now <= 'z')
        {
            ans+=now; //adding operands to ans
        }
        else //when the operators will enter
        {
            while(st.size() && prec(st.top())>=prec(now)) //st.size() is true
//or not means we are checking if stack has an element or not. only then we will
//check the precedence.if current operator's precedence is same or less to the
//top's, then top is being pushed to ans and st is being popped back.
            {
                ans += st.top();
                st.pop();
            }
            st.push(now); //else now is generally being pushed to stack.
        }
    }
    while(st.size()) //if in the end, stack remains with elements then the rest
        //elements will be pushed to ans+st is being empty
    {
        ans += st.top();
        st.pop();
    }
    cout<<ans<<"\n";

    return 0;
}


///IF THERE ARE BRACKETS.
///We have to change the prec function first.
//int prec (char ex)
//{
//    if(ex=='+' || ex=='-') return 1;
//    else if(ex=='*' || ex=='/') return 2;
//    else return 0;
//}
//.........................................
//else if(now == '(') st.push(now);
//else if(now == ')')
//{
//    while(st.size() && st.top() != '(')
//    {
//        post+=st.top();
//        st.pop();
//    }
//    st.pop();
//}

//When the code encounters an opening bracket (, it pushes it onto the stack.
//This is because brackets are used to denote precedence of operations, and they
//need to be processed last.
//
//When the code encounters a closing bracket ), it starts popping elements from
//the stack and appending them to the postfix expression until it encounters an
//opening bracket. This is because the expression within the brackets needs to be
//processed first before any other operations outside the brackets. Once the
//opening bracket is encountered, it is popped from the stack but not added to
//the postfix expression, because brackets are not part of the postfix expression.
//
//For example, let's consider the infix expression a + (b * c).
//
//When the code encounters a, it adds it directly to the postfix expression.
//When it encounters +, it pushes it onto the stack, because it has lower
//precedence than *.
//When it encounters (, it pushes it onto the stack.
//When it encounters b, it adds it to the postfix expression.
//When it encounters *, it pushes it onto the stack, because it has higher
//precedence than +.
//When it encounters c, it adds it to the postfix expression.
//When it encounters ), it starts popping elements from the stack and appending
//them to the postfix expression. It pops * first, followed by b, and finally (.
//When the stack is empty, the code continues processing the rest of the infix
//expression.
//The final postfix expression for a + (b * c) will be abc*+, which correctly
//reflects the order of operations.
