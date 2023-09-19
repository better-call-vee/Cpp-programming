/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
The problem is we need to exchange the shoes of the students but someone's shoe can only be exchanged if
there are shoes greater or equal sized than that person. And the sizes will be given ascendingly.
we have to print the sequence of the exchanged shoes.

2
5
1 1 1 1 1
6
3 6 8 13 15 21
output:
5 1 2 3 4 or, 2 3 4 5 1 or others
-1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n, start = 0;
        cin >> n;

        vector<int> shoes(n);
        for (int i = 0; i < n; i++)
            cin >> shoes[i];

        vector<int> exchange(n);
        iota(exchange.begin(), exchange.end(), 0);
        // suppose, n is 7. it will be 0 1 2 3 4 5 6
        // suppose we may write iota(....., 1) it will be 1 2 3 4 5 6 7
        // iota(....., 3)? => 3 4 5 6 7 8 9
        bool hobena = false;
        while (start < n)
        {
            int end = start;
            while (end < n && shoes[start] == shoes[end])
                end++;

            if (end - start == 1)
            {
                hobena = true;
                break;
            }

            rotate(exchange.begin() + start, exchange.begin() + start + 1,
                   exchange.begin() + end);
            // rotate the vector from the 2nd place to the last.
            // suppose 1 2 3 4 5. start = 0. end = 4. then => 2 3 4 5 1.
            // suppose 2 2 3 3 3 4 4 4 4. start = 5, end = 8. then 6 7 8 5.
            // the middle parameter is for choosing from which place we want to rotate.
            // if it were 2, we would do 7 8 5 6.
            start = end;
        }

        if (!hobena)
            for (int i = 0; i < n; i++)
                cout << exchange[i] + 1 << " \n"[i == n - 1];
        else
            cout << -1 << "\n";
    }

    return 0;
}