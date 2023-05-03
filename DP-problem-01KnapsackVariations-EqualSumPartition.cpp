/*
Given an integer array nums, return true if you can partition the array into two subsets such that
the sum of the elements in both subsets is equal or false otherwise.
You can't take a number twice.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100


Here, one thing is, if we get a odd number input, the result will be automatically false because we
can divide equally an odd integer number.
We have to divide the total targetted sum into two equal parts.
At first we will calculate the subtotal of the given inputs.
Then we will divide it by 2 and call the function with it and n. We will then follow the same method
as subtotal sum and if we get the exact true return that means the other equivalent partition is
present there.(because we called the function with target half of the total sum)
Therefore, the whole condition will be true. If not, then false.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> dp;

int equalSumParts(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp[n][target] != -1)
        return dp[n][target];

    int ans1 = equalSumParts(n - 1, target);
    if (target < nums[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2 = equalSumParts(n - 1, target - nums[n]);

    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
}

int main()
{
    int length;
    cin >> length;
    nums.resize(length + 1);

    int sum = 0;

    for (int i = 1; i <= length; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
        sum += num;
    }
    // we can do the sum using another way =>  int sum = accumulate(nums.begin(), nums.end(), 0);
    // 0 is the initial value of the accumulator.

    if (sum % 2 != 0)
    {
        cout << "false";
        return 0;
    }

    int target = sum / 2;
    dp.assign(length + 1, vector<int>(target + 1, -1));

    if (equalSumParts(length, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}