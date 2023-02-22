#include<bits/stdc++.h>
using namespace std;

//[{()}], {( )}, {()}[] = regular bracket sequence.
//{()}[][ => invalid bracket sequence.
int main ()
{
    string s;
    cin>>s; //taking input of a bracket sequence.
    //suppose, {[()()]}

    stack<char>st; //we are taking a stack.
    for(int i=0; i<s.size(); i++) //we are traversing the bracket sequence.
    {
        char now = s[i]; //index 0: now = {, index 1: now = [ and so on..
        if(now == '(' || now == '{' || now == '[')
        {
            st.push(now); //if it's an opening bracket, we will push the
            //bracket in the stack.
        }
        else
        {
            if(st.empty ()) //now we are checking if the stack is empty or not
        //because, when are not getting an opening bracket+if the stack is already
        //empty, means the bracket sequence is invalid.suppose, we got ")" this
        //as the first index. and the stack is empty. so that means, there isn't
        //any valid opening input of this first closing bracket. so it's invalid
            {
                cout<<"Invalid\n";
                return 0;
            }
            if(now == ')' && st.top() == '(')
            {
                st.pop(); //go through the example input.look for the 4th index
            //there's a first closing bracket. here, now = ) and the top of the
            //stack is ( now because the last pushed element was "(". so, it's a
            //match and now that ( will be popped from the stack.
            }
            else if(now == '}' && st.top() == '{')
            {
                st.pop(); //same goes for this
            }
            else if(now == ']' && st.top()=='[')
            {
                st.pop(); //same.
            }
            else
            {
                cout<<"Invalid\n"; //if these don't match, then obviously it will
                //be invalid.
                return 0;
            }
        }
    }
    if(st.empty()) //in the end, the stack has to be empty as hell else it's
        //invalid
    {
        cout<<"Valid\n";
    }
    else cout<<"Invalid\n";
    return 0;
}
