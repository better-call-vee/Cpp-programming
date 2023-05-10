#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<int>> memo;

int robUtil(int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return nums[start];

    if (memo[start][end] != -1)  
        return memo[start][end];

    int skipFirst = robUtil(start + 1, end);
    int robFirst = nums[start] + robUtil(start + 2, end);
    int ans = max(robFirst, skipFirst);

    memo[start][end] = ans;  

    return ans;
}

int rob(int n)
{
    if (n == 1)
        return nums[0];

    memo.assign(n, vector<int>(n, -1));  

    int max1 = robUtil(0, n - 2);
    int max2 = robUtil(1, n - 1);

    return max(max1, max2);
}

int main()
{
    int n;
    cin >> n;

    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = rob(n);
    cout << result;

    return 0;
}
