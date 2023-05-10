/**
Given an integer n, return the least number of perfect square numbers that sum to
n.
A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are
perfect squares while 3 and 11 are not.

Example 1:
Inputt: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

where, 1 <= n <= 10^4


it is a bit complex problem. please simulate to understand. the main concept
is to get the minimum of options. we do it by every possible perfect square present
through the for loop.

And this is a bottom up approach. remember sometimes top down doesn't work and bottom up is the optimal
solution
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

bool isps(int n)
{
    int root = sqrt(n);
    return root * root == n;
}

int perfect_squares(int n)
{
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    if (isps(n))
    {
        dp[n] = 1; // if the n itself a perfect square, we just return 1 without thinking twice.
        return 1;
    }

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
        ans = min(ans, perfect_squares(n - i * i) + 1);
/*
Let's take an intuitive approach to find the number of perfect square numbers required to sum up to a
given target number, 'n'. We will iterate through the numbers whose squares are less than or equal to
'n' and count them.
We can approach the problem recursively to determine the number of perfect square numbers needed to
add up to a target number, 'n'. In each recursive step, we subtract the square of a number (denoted as
'i') from 'n' and call the 'perfect_squares' function again until we reach the base case. With each 
recursive call, we increment the count by 1 and take the minimum of previously set ans and a new 
combination because we are looking for the minimum number of combinations.
*/
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    dp.resize(n + 1, -1);

    cout << perfect_squares(n);

    return 0;
}

/*
Suppose, the value of n is 5.
The loop starts iterating from i = 1.
In the first iteration, i * i = 1 * 1 = 1, which is less than or equal to 5. So we proceed.
We calculate the remaining value as n - i * i = 5 - 1 = 4.
We make a recursive call to perfect_squares(4) to find the minimum number of perfect squares required 
to obtain 4.
The recursive call goes through the same process and returns the result as 1 since 4 is a perfect 
square (2 * 2).
We add 1 to the result of the recursive call (1 + 1 = 2) because we are considering one perfect square
 (1 * 1) in the current iteration.
The minimum number of perfect squares required so far is updated to 2.
The loop proceeds to the next iteration with i = 2.
In the second iteration, i * i = 2 * 2 = 4, which is less than or equal to 5. So we continue.
We calculate the remaining value as n - i * i = 5 - 4 = 1.
We make a recursive call to perfect_squares(1) to find the minimum number of perfect squares required
to obtain 1.
The recursive call returns 1 since 1 is itself a perfect square (1 * 1).
We add 1 to the result of the recursive call (1 + 1 = 2) because we are considering one perfect square
(2 * 2) in the current iteration.
The minimum number of perfect squares required so far remains 2 since 2 is already the minimum.
The loop finishes iterating, and the final answer is 2, which represents the minimum number of perfect
squares required to sum up to 5.
*/