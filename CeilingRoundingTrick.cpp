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
        ll m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        if (ak >= m / k)
            cout << max(0LL, m % k - a1) << '\n';
            
        else
        {
            m -= ak * k;
            if (a1 >= m)
                cout << 0 << '\n';
            else if (a1 >= m % k)
                cout << (m - a1 + k - 1) / k << '\n';
            else
                cout << (m - a1) / k + (m - a1) % k << '\n';
        }
    }

    return 0;
}

What is Ceiling Division?
Ceiling division is a way of dividing two numbers and rounding up to the next integer. In other words, if the division doesn't result in an exact integer, you round up to the nearest whole number.

Why Use 
(
�
−
�
1
+
�
−
1
)
/
�
(m−a1+k−1)/k?
The expression is a trick to perform ceiling division without using floating-point numbers or special functions like ceil().

Breakdown:
Calculate the Remaining Amount: 
�
−
�
1
m−a1 represents the remaining amount that needs to be paid using fancy coins of value 
�
k.
Add 
�
−
1
k−1: By adding 
�
−
1
k−1, you are effectively "pushing" the result of the division up to the next integer if there is any remainder.
Divide by 
�
k: Finally, you divide by 
�
k to find out how many coins of value 
�
k are needed.
Example:
Let's take an example to illustrate how it works:

Suppose 
�
=
10
m=10, 
�
1
=
4
a1=4, and 
�
=
3
k=3.
Remaining amount: 
�
−
�
1
=
6
m−a1=6.
You need two coins of value 3 to pay 6, but 
6
/
3
=
2
6/3=2 is exact, so no rounding is needed.
If you calculate 
(
6
+
3
−
1
)
/
3
=
8
/
3
=
2
(6+3−1)/3=8/3=2, you get the correct answer.
Now, consider a case where the division is not exact:

Suppose 
�
=
10
m=10, 
�
1
=
3
a1=3, and 
�
=
3
k=3.
Remaining amount: 
�
−
�
1
=
7
m−a1=7.
You need three coins of value 3 to pay 7, even though 
7
/
3
=
2
1
3
7/3=2 
3
1
​
 .
If you calculate 
(
7
+
3
−
1
)
/
3
=
9
/
3
=
3
(7+3−1)/3=9/3=3, you get the correct answer, rounded up.
Why the 
−
1
−1?
The 
−
1
−1 is there to ensure that you don't round up unnecessarily when the division is exact. Without the 
−
1
−1, you might add 
�
k to the numerator even when there is no remainder, leading to an extra coin being used.

Conclusion:
The expression 
(
�
−
�
1
+
�
−
1
)
/
�
(m−a1+k−1)/k is a clever way to perform ceiling division, ensuring that you always round up when there is a remainder and don't round up when the division is exact. It's a useful technique for problems where you need to divide and round up without using floating-point arithmetic.