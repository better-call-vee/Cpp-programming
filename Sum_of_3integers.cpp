/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
created: 23th September, 2023 19:46:42 GMT+6
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

    int K, S;
    cin >> K >> S;

    int cnt = 0;
    for (int X = 0; X <= K; X++)
        for (int Y = 0; Y <= K; Y++)
            if (S - (X + Y) >= 0 and S - (X + Y) <= K)
                cnt++;

    cout << cnt;

    return 0;
}
// this is the O(n^2) method which is pretty common.

// let's dive into the O(n) method.
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

    int K, S;
    cin >> K >> S;

    int cnt = 0;
    for (int X = 0; X <= K; X++)
    {
        int Y_min = max(0, S - X - K);
        int Y_max = min(K, S - X);

        if (Y_min <= Y_max)
            cnt += (Y_max - Y_min + 1);
    }

    cout << cnt;

    return 0;
}

// here, Imagine you're standing at a point X on a number line.
// As you move along this line (i.e., as you change X), the range of Y values that give
// a valid Z shifts. When X is small, you can have larger Y values, but as X increases,
// the range of valid Y values shrinks because Z has to remain between 0 and K. The
// idea behind the solution is to efficiently determine this shifting range for Y for every X.