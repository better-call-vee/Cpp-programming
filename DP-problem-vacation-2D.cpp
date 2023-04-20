/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each
i (1≤i≤N), Taro will choose one of the following activities and do it on the
i-th day:

A: Swim in the sea. Gain a points of happiness.
B: Catch bugs in the mountains. Gain b points of happiness.
C: Do homework at home. Gain c points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
Find the maximum possible total points of happiness that Taro gains.

All values in input are integers.
1≤N≤10^5
1≤a, b, c≤10^4
3
10 40 70
20 50 80
30 60 90
Output: 210
Taro can't do the same activity on back to back days
so, C--->B--->C


VISUALIZATION:
Why is this problem a DP problem?
suppose this case, we will call fun(3) generally(max happiness till day n).
we can calculate the fun(3) if we know fun(2). fun(3) = fun(2) + max(a, b, c) on day 3
it's called leap of faith that fun(2) will be calculated. So, we can see it's being recursive
and it's looking like a DP problem.

But there are some things here we have to notice. Taro don't do the same work back to back days.
So, we have to change the state definition.

fun(n, x) => max happiness till day-n given that we are doing the work - x on day n. This is our
DP state. This is the first step
look =>
if,
fun(3, c) = fun(2, a) + c   max between them
        or, fun(2, b) + c
if,
fun(3, b) = fun(2, a) + b   max between them
        or, fun(3, c) + b
if,
fun(3, a) = fun(2, b) + a   max between them
        or, fun(2, c) + a

and finally ans = max{fun(3,a), fun(3,b), fun(3,c)}


Now, second step. Identifying the recursive equation from the smaller subproblems
fun(n, x) = max{fun(n-1,y)where x!=y} + happiness of task x on day-n

Time complexity = O(n*x*x) = O(nx²) = x=3 here. = So O(n)
Space complexity = now we need a 2D array. dp[n][x] => O(n*x)
                                           dp[n][3] => O(n)

Now, third step. Defining base cases.
fun(1, a) = h(1, a) or,
fun(1, b) = h(1, b) or,          =>          fun(1, x) = h(1, x)
fun(1, c) = h(1, c)
*/
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int happiness[N][4], dp[N][4];

int fun(int day, int current_task)
{
    // 1. Handle base case
    if (day == 1)
        return happiness[day][current_task];

    // 2. If answer is already calculated return it.
    if (dp[day][current_task] != -1)
        return dp[day][current_task];

    int max_profit = 0;

    // 3. Calculate the answer from smaller sub problems.
    for (int last_task = 1; last_task <= 3; last_task++)
    {
        if (last_task != current_task)
        {
            int candidate_profit = fun(day - 1, last_task) + happiness[day][current_task]; // 55th line
            max_profit = max(max_profit, candidate_profit);
        }
    }
    dp[day][current_task] = max_profit;
    return max_profit;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans_1 = fun(n, 1);
    int ans_2 = fun(n, 2);
    int ans_3 = fun(n, 3);

    cout << max({ans_1, ans_2, ans_3}) << endl; // to get the max of more than two elements we need
    // to use curly braces.

    return 0;
}
*/

/// TABULATION

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int happiness[N][4], dp[N][4];

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }

    for (int task = 1; task <= 3; task++)
    { // handle base case
        dp[1][task] = happiness[1][task];
    }

    // loop over the states
    for (int day = 1; day <= n; day++)
    {
        for (int current_task = 1; current_task <= 3; current_task++)
        {
            //calculate answer from smaller subproblems.
            int max_profit = 0;
            for (int last_task = 1; last_task <= 3; last_task++)
            {
                if (current_task != last_task)
                {
                    int current_profit = dp[day - 1][last_task] + happiness[day][current_task];
                    max_profit = max(max_profit, current_profit);
                }
            }
            dp[day][current_task] = max_profit;
        }
    }

    int ans = max({dp[n][1], dp[n][2], dp[n][3]});

    cout << ans;
    return 0;
}