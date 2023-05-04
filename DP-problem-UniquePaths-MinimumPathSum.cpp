/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
╔═══╦═══╦═══╗
║ 1 ║ 3 ║ 1 ║
╠═══╬═══╬═══╣
║ 1 ║ 5 ║ 1 ║
╠═══╬═══╬═══╣
║ 4 ║ 2 ║ 1 ║
╚═══╩═══╩═══╝
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

It's a very easy problem and just like the previous unique_paths problem. We just need to add the
current selected cell because we need the sum from start to that cell and thus that cell has to be in
count. and we need to take the maximum of the two approaches(right & down)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 201;
int dp[N][N];
int arr[N][N];

int minimumPathSum(int n, int m)
{
    if (n == 0 && m == 0)
        return arr[0][0];

    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = INT_MAX;

    if (n > 0)
        ans = min(ans, minimumPathSum(n - 1, m) + arr[n][m]);
    if (m > 0)
        ans = min(ans, minimumPathSum(n, m - 1) + arr[n][m]); // here are the changes. we have to
    // take the minimum of them.

    dp[n][m] = ans;
    return ans;
}

int main()
{

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int inp;
            cin >> inp;
            arr[i][j] = inp;
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << minimumPathSum(row - 1, col - 1);
    return 0;
}