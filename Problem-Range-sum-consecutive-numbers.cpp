/*
The problem is we need to find the sum of some numbers from a range to another range.
Let's see the sample input then it will be clear.
Sample Input 0
4
3 6
2 11
4 16
17 7
Sample Output 0
18        3+4+5+6 = 18
65        the sum of numbers from 2 to 11 will be 65
130       and so on
132
*/

#include <iostream>
using namespace std;

long long calculateSum(int L, int R)
{
    long long n = R - L + 1;           // Number of elements in the range
    long long sum = (n * (L + R)) / 2; // Sum of the arithmetic series
    // there can be another method. but it's the same. just a bit difference
    // (1LL * R * (R + 1) - 1LL * L * (L - 1)) / 2;  here the 1LL is just to keep the R and L
    // long long so that we calculate the same type of data.
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int L, R;
        cin >> L >> R;

        int left = min(L, R);
        int right = max(L, R);

        long long sum = calculateSum(left, right);
        cout << sum << "\n";
    }

    return 0;
}
