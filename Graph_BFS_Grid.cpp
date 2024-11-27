/*
Problem: Escape the Grid

You are given an `n x m` grid. Each cell can be:
- `.` (empty, you can move through it),
- `#` (blocked, you can't move through it).

Your task is to check for each empty cell (`.`) in the grid: **Can you reach the
edge of the grid from that cell?**

- You can move from one cell to its adjacent cells (up, down, left, or right) if
they are empty (`.`).
- The cells on the border (edges) of the grid are considered escape points.

For each empty cell, output `1` if you can reach the edge, otherwise output `0`.

Input:
- The first line contains two integers `n` and `m` (`1 ≤ n, m ≤ 1000`), the
dimensions of the grid.
- The next `n` lines contain `m` characters, where each character is either:
  - `.` representing an empty cell (traversable)
  - `#` representing a blocked cell (not traversable)

Output:
- Output a grid of the same size `n x m` where:
  - Each cell contains `1` if it is escapeable, or `0` if it is not.

Example:

Input:
5 6
......
.###..
.#.#..
.###..
......

Output:
111111
100011
100011
100011
111111

Constraints:
- `1 ≤ n, m ≤ 1000`
- There will be at least one empty cell (`.`) in the grid.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Directions for movement (up, down, left, right)
int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, -1, 1};

// Function to perform BFS and mark reachable cells
void bfs(int n, int m, vector<vector<char>> &grid,
         vector<vector<int>> &result) {
    queue<pair<int, int>> q;

    // Initialize the queue with all boundary cells that are empty (.)
    for(int i = 0; i < n; i++) {
        if(grid[i][0] == '.') {
            q.push({i, 0});
            result[i][0] = 1;
        }
        if(grid[i][m - 1] == '.') {
            q.push({i, m - 1});
            result[i][m - 1] = 1;
        }
    }

    for(int j = 0; j < m; j++) {
        if(grid[0][j] == '.') {
            q.push({0, j});
            result[0][j] = 1;
        }
        if(grid[n - 1][j] == '.') {
            q.push({n - 1, j});
            result[n - 1][j] = 1;
        }
    }

    // Perform BFS from all the boundary cells
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Explore the four directions (up, down, left, right)
        for(int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            // Check if the new cell is within bounds and is an empty cell
            if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
               grid[newX][newY] == '.' && result[newX][newY] == 0) {
                result[newX][newY] = 1; // Mark as escapeable
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> result(
        n, vector<int>(m, 0)); // Initialize result grid with 0

    // Reading the grid
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Perform BFS to determine escapeability
    bfs(n, m, grid, result);

    // Output the result grid
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
