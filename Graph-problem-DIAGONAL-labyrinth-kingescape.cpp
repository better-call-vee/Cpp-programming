#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int grid[N][N];
bool visited[N][N];
int n, q1, q2, k1, k2, w1, w2;
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1}; // down, right, up, left, rup, lup, ld, rd
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({k1, k2});
    visited[k1][k2] = true;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx_, dy_;
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];

            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= n && !visited[dx_][dy_] && grid[dx_][dy_] != -1)
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
            }
        }
    }
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int dx_ = x + dx[i];
        int dy_ = y + dy[i];

        if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= n && !visited[dx_][dy_] && grid[dx_][dy_] != -1)
        {
            dfs(dx_, dy_);
        }
    }
}

int main()
{
    cin >> n;

    cin >> q1 >> q2 >> k1 >> k2 >> w1 >> w2;

    grid[q1][q2] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == q1 - q2 || i + j == q1 + q2) // here is the magic. that's how we can find
                // the diagonal paths
                grid[i][j] = -1;

            if (i == q1)
                grid[i][j] = -1;
            if (i == q2)
                grid[j][i] = -1;
        }
    }

    bfs();
    dfs(k1, k2);

    if (visited[w1][w2])
        cout << "YES";

    else
        cout << "NO";

    return 0;
}
