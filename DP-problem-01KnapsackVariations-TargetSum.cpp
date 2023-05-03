/*
You are given an integer array of numbers and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each
integer in nums and then concatenate all the integers.
That means I have to use each and every number given as input.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them
to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

This problem is also quite similar to the previous variation problems of knapsack.
suppose, given two numbers [5,4]
our target is to make it 1 by using - or + at a time.
             + (0, -8)
       (1,-3)- (0, 2)
     +
(2,1)
     -      + (0, 0)       there's only one way to reach the target.
       (1,5)- (0, 10)

everytime there's being created two new states. everytime reaching the base case, we will get 1 in
return. And thus, we will calculate the all possible ways.

fun(n, target) => fun(n-1, target-nums[n]) + fun(n-1, target+nums[n])
base case is the same as previous.
here we have to handle the negative target case differently.
*/

/*
#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> dp;

int TargetSum(int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (dp[n][target + 1000] != -1)
        return dp[n][target + 1000];

    int ans1 = TargetSum(n - 1, target - nums[n]); // if we add value
    int ans2 = TargetSum(n - 1, target + nums[n]); // if we substract value

    int ans = ans1 + ans2;
    dp[n][target + 1000] = ans;
    return ans;
}

int main()
{
    int length, target;
    cin >> length >> target;
    nums.resize(length + 1);

    for (int i = 1; i <= length; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    dp.assign(length + 1, vector<int>(2001, -1));
    /*
    Let's say the target is -5, and we want to access dp[n][-5]. Since we cannot have negative indices
     for vectors, this will result in an out of range error.

Similarly, let's say the target is 1000, and we want to access dp[n][1000]. In this case, the index is
 larger than the size of the vector, so this will also result in an out of range error.

To avoid this, we need to adjust the indices such that they fall within the range of the vector. In
the solution I provided earlier, we added 1000 to the target value to shift it by 1000 units, and
created a dp table of size (length + 1) x (2000 + 1) to accommodate all possible values of target.

For example, if the target is -5, we will now access dp[n][995], and if the target is 1000, we will
access dp[n][2000]. These indices are within the range of the dp table and will not result in an out
of range error.
    */
// initialize dp array for base case where n == 0 and target != 0
/*   for (int i = -1000; i <= 1000; i++)
   {
       if (i != 0)              // skip target == 0 case
           dp[0][i + 1000] = 0; // this is the base case.
   }

   cout << TargetSum(length, target);

   return 0;
}
*/

// but this is still not the optimal solution yet as it will give runtime error in leetcode. this is
// the top down approach. Let's make a bottom-top approach.
// here we will go from nums[1] to nums[n] and will start from 0 to reach the target.

#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> dp;
int target, length;

int TargetSum(int idx, int sum)
{
    if (idx == nums.size())
        return sum == target ? 1 : 0;

    if (dp[idx][sum + 1000] != -1)
        return dp[idx][sum + 1000];

    int ans1 = TargetSum(idx + 1, sum + nums[idx]);
    int ans2 = TargetSum(idx + 1, sum - nums[idx]);

    int ans = ans1 + ans2;
    dp[idx][sum + 1000] = ans;
    return ans;
}

int main()
{

    cin >> length >> target;
    nums.resize(length + 1);

    for (int i = 1; i <= length; i++)
    {
        int inp;
        cin >> inp;
        nums[i] = inp;
    }

    dp.assign(length + 1, vector<int>(2001, -1));

    cout << TargetSum(1, 0);

    return 0;
}

