/*
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the
knapsack is W, which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9

Input
Input is given from Standard Input in the following format:

N   W
w1  v1
w2  v2
.   .
:   :
wN  vN

Output
Print the maximum possible sum of the values of items that Taro takes home.

6 15
6 5
5 6
6 4
6 6
3 5
7 2
Output: 17

5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Output: 5000000000



1) state: knapsack(n, cap), maximum possible profit considering objects 1 to n and a capacity of cap.
2) recurrence:
knapsack(n, cap) = max(
                       value[n] + knapsack(n-1, cap - weight[n]),   # YES CASE
                       0 + knapsack(n-1, cap)                       # NO CASE
                      )
3) base case: if (n == 0) or (cap == 0): return 0
if (weight[n] > cap): return knapsack(n-1, cap)

*/

// TOP-DOWN APPROACH
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int W = 1e5 + 5;
long long dp[N][W];
int wt[N], val[N];

long long knapsack(int n, int cap)
{
    // base and special case
    if (n == 0 || cap == 0)
        return 0;
    if (wt[n] > cap)
    {
        long long ans = knapsack(n - 1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    // if result is already calculated
    if (dp[n][cap] != -1)
        return dp[n][cap];

    long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
    long long ans2 = knapsack(n - 1, cap);

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;

    return ans;
}

int main()
{

    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            dp[i][j] = -1;
    // memset(dp, -1, sizeof(dp));

    cout << knapsack(n, w);

    return 0;
}
*/

// TABULATION
#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int W = 1e5 + 5;
long long dp[N][W];
int wt[N], val[N];

int main()
{

    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for (int i = 0; i <= w; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            if (cap < wt[i])
            {
                dp[i][cap] = dp[i - 1][cap];
            }
            else
            {
                // calculate the result from smaller sub-problems
                dp[i][cap] = max(
                    val[i] + dp[i - 1][cap - wt[i]],
                    dp[i - 1][cap]
                    );
            }
        }
    }

    cout << dp[n][w];

    return 0;
}