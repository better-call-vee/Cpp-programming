/**
PROBLEM STATEMENT:
you'll be given an array with random sequence but the array will only contain
distinct values from 1 to n. you have generate the output which will be lexico-
graphically shorter than the given array.
for example, given [1,3,4,2]. you can answer [1,2,3,4] or [1,3,2,4]. It's like you
have to maintain the same value until you're setting a lower value in face of a
greater value than it in the main input array. The more you shift the position of
the lower value to the left, the better the outcome.
**/

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        deque<int>dq;
        vector<int>v(n);
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        int i=0;
        while(i<n)
        {
            if(i==0)
            {
                dq.push_back(v[i]);
                i++; //here, we have no choice, you have to push that first element
            }
            else
            {
                if(v[i]<dq.front()) dq.push_front(v[i]);
                //if the element is less than the front of the deque, we have to
                //push that at front.
                else dq.push_back(v[i]);// else pushing back.
                i++;
            }
        }
        while(!dq.empty())
        {
            cout<<dq.front()<<" ";
            dq.pop_front(); //printing.
        }
        cout<<"\n";
    }
    return 0;
}
