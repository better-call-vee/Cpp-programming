/*
It's like a variation of the 0/1Knapsack problem

you'll be given a set of integers and you've to make a subtotal using subset of the given integer
set. you can't take a number more than once. you can either take a number or skip it. you just have
to show an output that if it's possible to form the subtotal or not.

suppose you have a set of integers:
2 8 1 9 6 7
and asked to make a subtotal of 12. you can make it by a subset(2, 9, 1)
subset is like this and if they say subarray then you have to take shorter parts from here but the
elements have to be consecutive(2,8,1)/(9,6) like this!

For this, we have to use the function to just get a boolean output! YES or NO.

suppose, [4,2,5]. we have to make 9.

                          ↗fun(0,-2)
                 ↗fun(1,2)->fun(0,2)
        ↗fun(2,4)->fun(1,4)->fun(0,0) return 1;
fun(3,9)                   ↘fun(0,4)
        ↘        ↗fun(1,7)->fun(0,4)
          fun(2,9)        ↘fun(0,7)
                 ↘
                  fun(1,9)->fun(0,5)
                          ↘fun(0,9)

here, only if we get the second parameter 0, we return 1. For every state we got two options-> take it
or skip it, that's what I've done here.

fun(n, x) = fun(n-1, target) || fun(n-1, x - num[n]) #skip or take
if one's true, then we get YES
Time complexity O(2^n)(brute force)
*/
/*
#include <bits/stdc++.h>
using namespace std;

// DP STATES:
// -> state: fun(n, target) -> returns true(1) if it is possible to create a subset from numbers 1 to n
//           and form the sum "target"

// -> recurrence: fun(n, target) -> fun(n-1, target) OR
//                                  fun(n-1, target - nums[n])      if target >= nums[n]

// -> base_case: fun(0, target) -> return 1, if target == 0 else return 0

const int N = 101;     // how many numbers will be there
const int M = 1e5 + 5; // max target
int nums[N];
int dp[N][M];

int subset_sum(int n, int target)
{
    // base_case
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }
    // if (target == 0)
    //     return 1;     if we even don't write this line, it will work properly. because, if we
    // reach the target before reaching n==0, we still can reach n==0 with skipping the rest elements

    if (dp[n][target] != -1)
        return dp[n][target];

    int ans1 = subset_sum(n - 1, target);
    if (target < nums[n]) // suppose the target is 9 and the num[n] is 11, we can't take it. corner case
    {
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = subset_sum(n - 1, target - nums[n]); // if target is bigger than the nums[n] then we
    // will take the nums[n] and substract it.

    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
}

int main()
{

    int n, target;
    cin >> n >> target;

    for (int i = 1; i <= n; i++)
    {
        int inp;
        cin >> inp;
        nums[i] = inp;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (subset_sum(n, target))
        cout << "YES, TARGET REACHED";
    else
        cout << "SORRY, TARGET IS UNREACHABLE";

    return 0;
}
*/

/*
Sample input:
6 9
3 34 4 12 5 2

6 1
3 34 4 12 5 2

4 9
4 1 9 2

1 5
5
*/

// Tabulation
#include <bits/stdc++.h>
using namespace std;

const int N = 101;     // how many numbers will be there
const int M = 1e5 + 5; // max target
int nums[N];
int dp[N][M];

int main()
{

    int n, target;
    cin >> n >> target;

    for (int i = 1; i <= n; i++)
    {
        int inp;
        cin >> inp;
        nums[i] = inp;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= target; i++) // base case.
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int m = 1; m <= target; m++)
        {
            int ans1 = dp[i - 1][m];
            if (m < nums[i])
                dp[i][m] = ans1;

            else
            {
                int ans2 = dp[i - 1][m - nums[i]];
                dp[i][m] = ans1 or ans2; // if either one of them is true, we go with that.
            }
        }
    }

    if (dp[n][target] == 1)
        cout << "YES, TARGET REACHED";
    else
        cout << "SORRY, TARGET IS UNREACHABLE";

    return 0;
}