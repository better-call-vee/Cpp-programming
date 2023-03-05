//https://www.hackerrank.com/contests/phitron-monthly-contestmarch-2023batch-02/challenges/multiplication-between-l-to-r

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q,L,R,val;
    cin>>N;
    vector<int> A;
    for(int i=0; i<N; i++)
    {
        cin>>val;
        A.push_back(val);
    }
    int prefix[N+1];
    prefix[0] = 0;
    for(int i=1; i<N+1; i++)
    {
        prefix[i] = prefix[i-1] + A[i-1];
    }
    for(int i=0; i<N+1; i++) {
        cout<<prefix[i]<<" ";
    }
    cout<<"\n";
    cin>>Q;
    while(Q--)
    {
        cin>>L>>R;
        int match = (R-L)+1;
        int match2 = prefix[R]-prefix[L-1];
        if(match==match2) cout<<"1\n";
        else cout<<"0\n";

    }
    return 0;
}
