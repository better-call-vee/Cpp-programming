/*
--------------------
| Common Multiples:|
--------------------
Given two integers x and y, and a range from 1 to n:

    Calculating Multiples of x and y:
        The total number of multiples of x within the range is ⌊nx⌋⌊xn​⌋.
        The total number of multiples of y within the range is ⌊ny⌋⌊yn​⌋.

    Identifying Common Multiples of x and y:
        The common multiples of x and y within a given range are the multiples of their Least Common Multiple (LCM).
        The formula for LCM of two numbers aa and bb is:
        LCM(a,b)=a×b/GCD(a,b)

        Here, GCD stands for the Greatest Common Divisor.
        The count of common multiples of x and y in the range is ⌊nLCM(x,y)⌋⌊LCM(x,y)n​⌋.

    Adjustment for Common Multiples:
        Subtract the count of common multiples from the multiples of x and y to get the adjusted counts.
    #include <bits/stdc++.h>
using namespace std;

// Compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Compute LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Adjust the count of multiples of x and y in the range 1 to n, considering common multiples
void adjust_multiples(int n, int x, int y, int &x_div, int &y_div) {
    x_div = n / x;
    y_div = n / y;

    // Deduct common multiples (those divisible by LCM of x and y)
    int common_multiples = n / lcm(x, y);
    x_div -= common_multiples;
    y_div -= common_multiples;
}

int main() {
    int n = 24, x = 4, y = 6;
    int x_div, y_div;
    adjust_multiples(n, x, y, x_div, y_div);
    cout << "Adjusted count of multiples of " << x << ": " << x_div << endl;
    cout << "Adjusted count of multiples of " << y << ": " << y_div << endl;
    return 0;
}

*/

/*
-----------------------------------------------------------------
Calculating the Sum of the Last m Largest Numbers in a Sequence:|
-----------------------------------------------------------------

Given a sequence from 1 to N:

To find the sum of the last m largest numbers, we first need to identify these numbers.

The last m largest numbers in the sequence from 1 to N would be:
N−1,N−2,…,N−m+1

Now, let's use the arithmetic sequence sum formula to determine the sum of these numbers.

The formula to find the sum of an arithmetic sequence is:
Sum=n/2×(first term+last term)

For our sequence:

    First term = N−m+1
    Last term = N
    Number of terms (n) = m

Plugging in these values:
Sum=m / 2 × (N − m + 1 + N)
Sum=m / 2 × (2N − m + 1)
highSum = (k * (2 * n - k + 1)) / 2;
*/

/*
--------------------------------------------------------------------------------
Minimum LCM of two numbers from 1 to N and their sum has to be equivalent to N |
--------------------------------------------------------------------------------
int n, ans = 1;
cin >> n;

for (int i = 2; i * i <= n; i++)
     if (n % i == 0)
        ans = max(ans, n / i);

cout << ans << " " << n - ans << "\n";
*/

/*
------------
CO - PRIME |
------------
If two numbers' GCD is 1, then they are "CO-PRIME"
*/

/*
-------------------
GCD - OVERLAPPING |
-------------------
https://github.com/tanvee009/Cpp-programming/blob/main/GCD_overlapping.cpp

*/