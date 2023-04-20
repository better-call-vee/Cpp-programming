/*

# Memorization Method (recursive)

fun(n, a, b, c, ...) {
    //1. handle base case.
    //2. if current state is already solved, return the result
    //3. calculate the result from the smalller sub-problems
}

let's do it for fibonacci
THE 3 STEPS:
fib(n) -> calculates the nth fibonacci.
fib(n) = fib(n-1) + fib(n-2)
fib(1) = 1, fib(2) = 2;
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
long long dp[N];

int fib(int n)
{
    // if(n == 1) return 1;  //step 1
    // if(n == 2) return 1;

    if (n == 0)
        return 0;

    if (n <= 2)
        return 1;

    if (dp[n] != -1)  // step 2
        return dp[n]; // checking if current state is already solved.

    // calculating from smaller subproblems.
    long long ans = fib(n - 1) + fib(n - 2);
    dp[n] = ans; // step 3
    return ans;
}

int main()
{

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp)); // marking the array as unvisited

    cout << fib(n) << "\n";

    return 0;
}