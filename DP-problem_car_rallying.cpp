#include <bits/stdc++.h>
using namespace std;
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=900
const int MAX_VAL = 10005;
const int MAX_SPEED = 30;
int v[MAX_VAL];
int dp[MAX_VAL + MAX_SPEED][MAX_SPEED];
int deacc, acc;
int size;

int dpf(int p, int sp)
{
    if (dp[p][sp] != -1)
        return dp[p][sp];

    if (p > size)
        return dp[p][sp] = 0;

    int small = MAX_VAL;
    int max_speed = INT_MAX;

    for (int i = 1; i < max(1, sp - deacc); i++)
        max_speed = min(max_speed, v[min(size, p + i)]);

    for (int i = max(1, sp - deacc); i <= sp + acc; i++)
    {
        max_speed = min(max_speed, v[min(size, p + i)]);

        if (i > max_speed)
            break;

        small = min(small, dpf(p + i, i));
    }

    return dp[p][sp] = 1 + small;
}

int main()
{
    int cases;
    cin >> cases;

    for (int it = 0; it < cases; it++)
    {
        memset(dp, -1, (MAX_VAL + MAX_SPEED) * MAX_SPEED * sizeof(int));
        memset(v, 0, MAX_VAL * sizeof(int));
        cin >> acc >> deacc;
        acc /= 10;
        deacc /= 10;

        int a, b;
        size = 0;
        while (cin >> a >> b && a != 0 && b != 0)
        {
            b /= 10;
            for (int i = 0; i < a; i++)
                v[++size] = b;
        }

        cout << dpf(0, 0) << "\n";
    }

    return 0;
}
