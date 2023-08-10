/**
PROBLEM STATEMENT:
Two persons, Klyora & Koxia.
Klyora has n numbered whiteboards & Koxia has m numbered operations.
There will be written an integer number on each whiteboard, and Koxia will have
chance of m times to replace the numbers with her numbers.
Well, we will have three lines of input.
*)The first line will contain the number of n and m.
*)The second line will contain the numbers which are written on each whiteboard.
*)The third line will contain the numbers which are going to replace the whiteboard
numbers.
The Output will be the maximum sum of integers written on whiteboards after performing
the operations.
Our target will be replacing the shorter values of the whiteboards with the Koxia's
values. Everytime we have to sort the deque or linked list containing the value of
the whiteboards. OR we can do that with Set!
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
        int n, m;
        cin>>n>>m;
        long long sum = 0;
        deque<int>Klwb;

        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            Klwb.push_back(x);
            sum+=x;
        }
        sort(Klwb.begin(), Klwb.end());
        for(int i=0; i<m; i++)
        {
            int y;
            cin>>y;
            sum-=Klwb.front();
            sum+=y;
            Klwb.pop_front();
            Klwb.push_back(y);
            sort(Klwb.begin(), Klwb.end());
        }

        cout<<sum<<"\n";
    }
    return 0;
}

//we can do this with linked list also. but linked list's sort STL will be
//Klwb.sort().
