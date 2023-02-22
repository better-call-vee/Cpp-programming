#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    long long moves = 0;
    for(int i=1; i<n; i++)
    {
        if(a[i]<a[i-1])
        {
            moves += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout<<moves;
    return 0;
}

