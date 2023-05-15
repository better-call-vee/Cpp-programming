/*
You'll be given two integer numbers => n and x. Suppose x has 2 digits. And n is 3.
You have to multiply x with such a value that the product has the same digit number as n
and the value has to be one of x's digit but not 0. You have to show the output of the minimum
operations needed to do this.
suppose, n=5 and x=430. Currently, x has 3 digits. We have to make it 5. So, multiplication 
starts. We can't take 0 because of the condition.
Taking 3 => 1290 => 1290 x 9 => 11610 (2 operations)
Taking 4 => 1720 => 1720 x 2 => 3440 => 3440 x 4 => 13760 (3 operations)
We will take the minimum one.

The problem is a mixture of BFS concept + dynamic programming.
suppose, n=3 and x=2
            2
            ⬇
            4
            ⬇
           1 6
        ↙      ↘
       16       96 
      ↙ ↘     ↙  ↘
     16  96  864  576  #we got our answer
     
*/


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