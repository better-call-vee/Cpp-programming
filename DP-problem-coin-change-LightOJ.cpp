/*
In a strange shop there are n types of coins of value A1, A2 ... An. C1, C2, ... Cn denote the
number of coins of value A1, A2 ... An respectively. You have to find the number of ways you can
make K using the coins.

For example, suppose there are three coins 1, 2, 5 and we can use coin 1 at most 3 times, coin 2
at most 2 times and coin 5 at most 1 time. Then if K = 5 the possible ways are:

(1, 1, 1, 2)

(1, 2, 2)

(5)

So, 5 can be made in 3 ways.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing two integers n (1 ≤ n ≤ 50) and K (1 ≤ K ≤ 1000). The next
line contains 2n integers, denoting A1, A2 ... An, C1, C2 ... Cn (1 ≤ Ai ≤ 100, 1 ≤ Ci ≤ 20). All Ai
will be distinct.
K means the target.

Output
For each case, print the case number and the number of ways K can be made. The result can be large, so,
 print the result modulo 100000007.

Sample
Input
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1

Output:
Case 1: 3  (where we can take at most '1' 3 times, '2' 2 times, '5' 1 time)
Case 2: 9

DP STATES:
1)fun(n, k) => Number of ways to make sum=k such that we don't exceed the limit of each coin.

2)fun(n, k) = fun(n-1, k) + will do till the limit of coin[n] -> fun(n-1, k-coin[n]);

3)base case is the same as previous variations
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> limit;
vector<vector<int>> dp;

int LightOJ(int n, int K)
{
    if (n == 0)
    {
        if (K == 0)
            return 1;
        return 0;
    }

    if (dp[n][K] != -1)
        return dp[n][K];

    int ans1 = LightOJ(n - 1, K);
    if (K < coins[n])
    {
        dp[n][K] = ans1;
        return ans1;
    }

    int ans2 = 0;

    for (int i = 1; i <= limit[n]; i++)
    {
        if (K - i * coins[n] < 0)
            break;
        ans2 += LightOJ(n - 1, K - i * coins[n]);
    }

    int ans = ans1 + ans2;
    dp[n][K] = ans;
    return ans;
}

int main()
{
    int test, t = 0;
    cin >> test;

    while (test--)
    {
        int n, target;
        cin >> n >> target;

        coins.resize(n + 1);
        limit.resize(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> coins[i];

        for (int i = 1; i <= n; i++)
            cin >> limit[i];

        dp.resize(n + 1, vector<int>(target + 1, -1));

        cout << "Case " << ++t << ": " << LightOJ(n, target) % 100000007 << '\n';

        coins.clear();
        limit.clear(); // there can be more than one test case
        dp.clear();
    }
    return 0;
}

// for tabulation, follow the subset knapsack problem. but here we will need three nested loops.
// third one will be for the limits. j=1; j<=limit[i]; j++;