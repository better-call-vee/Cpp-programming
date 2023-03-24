#include<bits/stdc++.h>
using namespace std;

const int maxN = 10101;
char grid[maxN][maxN];
bool visited[maxN][maxN];
pair<int, int>parent[maxN][maxN]; //every location in the grid will contain a pair
int dx[4] = {1, 0, -1, 0};  //down, right, up, left.
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

void bfs(int x, int y, int n, int m)
{
    queue<pair<int,int>>q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty())
    {
        pair<int, int>u = q.front();
        q.pop();
        for(int i=0; i<4; i++)  //getting four cells. down, right, up, left.
        {
            int dx_, dy_;
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];

            if(dx_ >= 1 && dx_ <= n && dy_ >= 1 && dx_ <= n && !visited[dx_][dy_] && grid[dx_][dy_] != '#')
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if(grid[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    bfs(start_x, start_y, n, m);
    if(visited[end_x][end_y])
    {
        cout<<"YES"<<"\n";
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cout<<visited[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    //but we need to find the shortest path as well

    return 0;
}

