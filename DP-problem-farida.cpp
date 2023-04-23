/*
This is a madafaking problem. 
So, the problem is mainly:
There is a bitch princess in a kingdom named Farida. She needs sex and that's she made an advertisement
to get a prince.
But the prince needs to pay coins to fuck the princess and he can attain the coins from monsters.
And there's another condition. The monsters will only give you the coins if you take coins from a 
monster and haven't take coins from the previous monster. 
For example:
5
1 2 3 4 5
here, the prince can attain at most 9 coins and he need to pay 9 coins to fuck the princess.
look, here he takes coin from the first monster. then he skips the second because he can't take coins
from the second monster according to the condition. If he takes, he will be spot dead.
Then he moves to 3rd, then 5th. like this. 
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
long long coins[N];
long long mcoins[N];
long long ans = -1;

long long farida(int n)
{
    if (n <= 0)
        return 0;

    if (mcoins[n] != -1)
        return mcoins[n];

    long long ans1 = farida(n - 1); //skipping the current monster. 
    long long ans2 = coins[n] + farida(n - 2); //taking the current monster's coins.
    ans = max(ans1, ans2); //taking the max of the two options.

    //we can be more intuitive if we look through this in the tabulation method.

    mcoins[n] = ans;
    return ans;
}

int main()
{

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int monsters;
        cin >> monsters;

        memset(mcoins, -1, sizeof(mcoins));

        for (int j = 1; j <= monsters; j++)
            cin >> coins[j];

        mcoins[0] = 0;
        mcoins[1] = coins[1];

        cout << "Case " << i << ": " << farida(monsters) << "\n";
    }

    return 0;
}



//TABULATION
/*
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

*/