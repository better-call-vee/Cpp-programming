// https://atcoder.jp/contests/dp/tasks/dp_a

/*
there will be stones of different heights. The frog can jump from a stone to
another stone. If the frog is on i stone, it can go to i+1/i+2th stone.
Everytime there will be a cost. the absolute difference between those stones.
|h1-h2|

suppose
1      2       3       4
10     30      40      20
1--->2--->4 => |10-30|+|30-20| => 30. This is the optimal path.

Why is it a dp problem?
=> we know one thing that if we can solve sub problems of a problem,
we can solve the problem with DP
Our goal is to reach the last/final stone. To reach, we can go two or one
step forward at a time.
We can reach the 4th stone either from 3rd stone or 2nd stone directly by one jump.
So, we have to reach there at first, either it isn't possible to reach the
goal stone.
If we jump from the 3rd stone, we need the cost from 1st stone to 3rd stone
at first or if we jump from the 2nd stone, we need the cost from 1st stone to
2nd stone at first.
So, ultimately we are in need of solving smaller sub problems to solve the bigger
problems...
That's how we decide that it's a DP problem.


1) state definition => stone(n)-> minimum cost to reach nth stone.
2) identifying the recursive equation for the smaller subproblems:
we have two options everytime, one stone/ two stones.
to reach the 4th stone, we can go from 3rd/2nd stone by one jump.
stone(4) = stone(2)(cost from 1 to 2) + |h4-h2|  or,
stone(4) = stone(3)(cost from 1 to 3) + |h4-h3|
we will take the minimum of these two.

So, the final equation will be:            It's the main challenge of DP problem
stone(n) = min(stone(n-2) + |hn-h(n-2)|, stone(n-1) + |hn-h(n-1)|);

The base case is the smallest problem => stone(1) = 0. 1st stone doesn't have a cost.
*/

// SOLVING WITH MEMORIZATION:
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int h[N];
int dp[N]; // storing cost in this array.

int stone(int n)
{
    if (n == 1)
    {
        return 0; // if we are on 1st stone
    }

    // checking if answer already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans1 = stone(n - 1) + abs(h[n] - h[n - 1]);

    if (n == 2)
    {
        dp[n] = ans1;
        return ans1;
    }

    // it's a corner case. look ->
    // 2
    // 100 10
    // if we go without handling this case, there will be an error and the output will be shown 10! but
    // in reality the answer is nothing other than 90.
    // If we wouldn't handle the base case, we will move next to ans2 equation and then we will
    // be in need of handling stone(2-2) = stone(0) case which isn't handled here.
    // Therefore, we write this extra lines after ans1.
    // so, for handling this case, we need to just calculate the value which is got by only a jump(n-1)
    // not the 2 stone jump!

    int ans2 = stone(n - 2) + abs(h[n] - h[n - 2]);

    int ans = min(ans1, ans2);
    dp[n] = ans;
    return ans;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << stone(n);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int h[N];
int dp[N];

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    dp[1] = 0; // handle the base case

    // loop through the states
    for (int i = 2; i <= n; i++)
    {
        // solve from smaller sub-problems
        int ans1 = dp[i - 1] + abs(h[i] - h[i - 1]);
        if(n==2 && i==2) {
            dp[i] = ans1;
            continue;
        }
        int ans2 = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(ans1, ans2);
    }

    cout << dp[n];
    return 0;
}