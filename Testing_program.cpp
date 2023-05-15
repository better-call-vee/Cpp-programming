#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    scanf("%d", &n);
    long long x;
    scanf("%lli", &x);

    queue<long long> q;
    map<long long, int> ops;

    ops[x] = 0;
    q.push(x);

    while (!q.empty())
    {
        long long child = q.front();
        q.pop();
        string digits = to_string(child);

        if (digits.size() == n)
        {
            printf("%d", ops[child]);
            return 0;
        }

        for (auto digit : digits)
        {
            if (digit == '0')
                continue;

            long long ydecimal = child * (digit - '0');

            if (!ops.count(ydecimal))
            {
                ops[ydecimal] = ops[child] + 1;
                q.push(ydecimal);
            }
        }
    }

    printf("-1");

    return 0;
}