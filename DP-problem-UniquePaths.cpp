/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take
to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:
1 <= m, n <= 100

TIME COMPLEXITY => O(n*m)
SPACE COMPLEXITY => O(n*m)

Let's think in the way of dynamic programming:
=> state definition: f(n, m) => in how many ways we can reach cell (n, m)
=> recurrence state: f(n, m) => f(n-1, m) + f(n, m-1);  #one is for the upper cell, the next is for left
                                                        cell of the selected cell.
for rows, if we go down, it increases by 1, and for up, it decreases by 1.
for columns, if we go right, it increases by 1, and for left, it decreases by 1.
=> base case: f(0, 0) = 1;   #if there is no cell, there is one way to reach the finish line.

Let's spill the tea:
      0   1
    ╔═══╦═══╗
  0 ║ R ║   ║  we have to go to 2,1 from 0,0. To reach (2,1) we can take only two paths beforehand.
    ╠═══╬═══╣  (1,1) and (2,0). Then, to reach the (1,1), we can take only two paths beforehand =>
  1 ║   ║   ║  (0,1) and (1,0). And to reach (2,0), we can take only one path, that's (1,0).
    ╠═══╬═══╣
  2 ║   ║ F ║  If we know the unique paths number to reach the (1,1) and (2,0) cells,
    ╚═══╩═══╝  we can easily get the unique paths number to reach (2,1). Same goes for these two cells
               also.
*/
// TOP DOWN APPROACH
// MEMORIZATION
/*#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];

int unique_paths(int n, int m)
{
  if (n == 0 && m == 0)
    return 1;

  if (dp[n][m] != -1)
    return dp[n][m];

  int ans = 0;
  if (n > 0) // corner case
    ans += unique_paths(n - 1, m);
  if (m > 0) // corner case
    ans += unique_paths(n, m - 1);

  // look at the matrix figure above. we can go to 2,0 from going down from 1,0 only. We can't go to
  // 2,0 from it's right cell which is impossible to be (2,-1). Similarly, we can't go to 0, 1 from
  // -1, 1. That's why we have to handle this corner cases(63th, 65th lines)

  dp[n][m] = ans;
  return ans;
}

int main()
{

  int row, col;
  cin >> row >> col;

  fill_n(&dp[0][0], N * N, -1);

  cout << unique_paths(row - 1, col - 1); // the last cell. 0 indexed 2D array

  return 0;
}*/

// TABULATION
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];

int main()
{

  int row, col;
  cin >> row >> col;

  dp[0][0] = 1;

  for (int i = 0; i < row; i++)
  { // we will run the loop from 0. otherwise, some cells will be ignored
    for (int j = 0; j < col; j++)
    {
      if (i == 0 and j == 0)
        continue;

      int ans = 0;
      if (i > 0)
        ans += dp[i - 1][j];
      if (j > 0)
        ans += dp[i][j - 1];
      dp[i][j] = ans;
    }
  }

  cout << dp[row - 1][col - 1];

  return 0;
}