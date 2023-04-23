#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
long long coins[N];
long long mcoins[N];
long long ans = -1;

int main ()
{

    int tc;
    cin >> tc;

    for(int case_=1; case_<=tc; case_++)
    {
        int monsters;
        cin >> monsters;

        memset(mcoins, -1, sizeof(mcoins));

        for(int j=1; j<=monsters; j++)
            cin>>coins[j];

        mcoins[0] = 0;
        mcoins[1] = coins[1];

        for(int i=2; i<=monsters; i++)
        {
            long long ans1 = mcoins[i - 1];
            long long ans2 = coins[i] + mcoins[i - 2];
            ans = max(ans1, ans2);

            mcoins[i] = ans;
        }

        cout<<"Case "<<case_<<": "<<mcoins[monsters]<<"\n";
    }

    return 0;
}



