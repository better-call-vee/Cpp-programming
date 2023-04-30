/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is
to produce a sum of money x using the available coins in such a way that the number of coins is
minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1
which requires 3 coins.

Input
The first input line has two integers n and x : the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn : the value of each coin.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum,
print −1
Suppose the x is 13 ans you are given only two coins 6 & 4. You can't form 13 with these two values!
Thus, you need to print -1.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6

Example

Input:
3 11
1 5 7

Output:
3

*/
/*
#include <bits/stdc++.h>
using namespace std;

const int c = 1e6 + 1;
vector<int> coins;
vector<int> dparr;
int n, x;

int vangti(int v)
{
    if (v == 0)
        return 0;

    if (dparr[v] != -1)
        return dparr[v];

    int ans = INT_MAX; // Initialize ans to a large value

    for (int i = 1; i <= n; i++) // Loop over all coins
    {
        if (v >= coins[i])
        {
            int subans = vangti(v - coins[i]);
            if (subans != -1)
                ans = min(ans, subans + 1); // Update ans with the minimum number of coins required
        }

        subans + 1 calculates the number of coins required to reach the value v from the value 
        v - coins[i], assuming that we use one coin of value coins[i]. In other words, if we already 
        know the minimum number of coins required to reach the value v - coins[i], we can use one more
        coin of value coins[i] to reach the value v and obtain a solution with subans + 1 coins.

        For example, let's say we want to reach the value v = 11, and we have two coins with values
        coins = {1, 5, 7}. Suppose we have already computed the minimum number of coins required to
        reach the value v - coins[i] for all i, and we have dparr = {0, 1, -1, 2, -1, 1, -1, 2, ...}
        (where -1 means that the value cannot be reached). If we consider the coin with value c
        oins[2] = 5, we can use one coin of value 5 to reach the value v - coins[2] = 6, which requires
        dparr[6] = 2 coins. Therefore, we can reach the value v = 11 using dparr[6] + 1 = 3 coins
        (i.e., one coin of value 5 and two coins of value 1), which is the minimum number of coins
        required.

        So, the expression ans = min(ans, subans+1) updates the minimum number of coins required to
        reach the value v by considering all possible coins i, and choosing the coin that leads to the
        minimum number of coins required.

    }

    if (ans != INT_MAX)
    {
        dparr[v] = ans;
        return ans;
    }
    else
    {
        dparr[v] = -1;
        return -1;
    }
}

int main()
{
    cin >> n >> x;

    coins.resize(n + 1);
    dparr.resize(x + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        coins[i] = value;
    }

    int ans = vangti(x);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}

This problems memorization method have some problems and exceed time limits.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, x;          // number of coins and target sum
vector<int> coins; // array to store the values of the coins
vector<int> dp;    // array to store the minimum number of coins needed to make up each sum from 0 to x

int main()
{
    cin >> n >> x;

    coins.resize(n + 1);
    dp.resize(x + 1, INF);

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 0; // base case: it takes 0 coins to make a sum of 0

    // iterate over all the coins
    for (int i = 1; i <= n; i++)
    {
        // iterate over all the possible sums that can be made using this coin
        for (int j = coins[i]; j <= x; j++)
        /*
The inner for loop in the code starts from the value of j equal to coins[i], which is the value of the
current coin being considered in the outer loop. This is because if j is less than coins[i], then we
cannot make a coin change of value coins[i] with j value, and we need to skip it.

For example, if we have coins with denominations [1, 2, 5] and we are trying to make change for x = 7,
we start by considering the first coin with denomination 1. If we start the inner loop from j = 1,
then we can make a coin change of value 1 for all values of j starting from 1. If we start the inner
loop from j = 2, then we cannot make a coin change of value 1 for j = 2, and we need to skip it.

Starting the inner loop from coins[i] ensures that we consider all possible coin changes that can be
made with the current coin denomination.
This is the thing which makes the difference from the recursive approach!
        */
        {
            // if it's possible to make the sum j using coins[i], update dp[j]
            if (dp[j - coins[i]] != INF)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    // if it's impossible to make the sum x using the given coins, output -1
    if (dp[x] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }

    return 0;
}
