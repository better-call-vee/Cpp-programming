#include <bits/stdc++.h>
using namespace std;
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
const int maxN = 10101;
char grid[maxN][maxN];
bool visited[maxN][maxN];

vector<pair<int, int>> path; // we will generate the path with the information of the
// parent pairs.

pair<int, int> parent[maxN][maxN]; /*every location in the grid will contain a pair
 and it will store the data of the parent node and adjacent nodes. The very
 first starting node's parent will be (-1, -1). then it's adjacent nodes' parent
 node pair will be it's location(row and column). like this and so on.

 Let's understand the concept with a good example. Suppose, we want to go from Khulna to Rajshahi.
 We have to print the path.
 So, at first we go from Khulna to Jashore. After reaching Jashore we are keeping the information
 there that we came here from Khulna. Then from Jashore, we go Kotchandpur, there we keep the
 information of Jashore. Then we go Kushtia, Kushtia's parent node is Kotchandpur. Like this and so on.
 */

int dx[4] = {1, 0, -1, 0}; // down, right, up, left.
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

void bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    parent[x][y] = {-1, -1}; // for the parent pair, we're tracking each node's parent. So, when
    // we will start the traversal, the source node's parent will be no one. So, at first we will
    // set it's parent's pair to {-1, -1}

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) // getting four cells. down, right, up, left.
        {
            int dx_, dy_; // these nodes are all u's adjacents. So, u is our parent.
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];

            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] != '#')
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
                parent[dx_][dy_] = u;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    bfs(start_x, start_y, n, m);
    if (visited[end_x][end_y])
    {
        cout << "YES"
             << "\n";
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        path.push_back({end_x, end_y}); // the end is the beginning. starting from the start_x will
        // make things grueling. When we will start from the ending, we can easily access the parents
        // and continue the loop correctly because parents' information are set in a way that only
        // going backward you can access them.
        int x = end_x, y = end_y;
        while (parent[x][y] != make_pair(-1, -1)) // we will run the loop until we are getting the
        // source node whose parent pair was set with (-1, -1). We have used the make_pair function
        // here to equalize with the type of parent which is pair.
        {
            pair<int, int> p = parent[x][y]; // now we are taking a new pair variable in which we will
            // store every new x and y's parent everytime.
            x = p.first, y = p.second; // then we will change the values of x and y , will make them
            // equivalent to their parent's x, y so that we can continue the traversal.
            path.push_back({x, y}); // finally, we will push the values of the pair to the path
            // vector.

            // look, at the first place, the ending was pushed in the path vector. right after that,
            // we are pushing the end's parent which is totally logical because we are going backward.
            // see the input figure to clarify more.
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << "{" << parent[i][j].first << "," << parent[i][j].second << "}"
    //              << " ";
    //     }
    //     cout << "\n";
    // }

    reverse(path.begin(), path.end());
    for (auto val : path)
    {
        cout << val.first << " " << val.second << "\n";
    }

    // here, look at the addresses of the nodes. We will compare two corresponding adjacent nodes and get
    // their differences. We will match the differences that how will we get it. Down, Left, Right or Up?

    string ans; // we have to print the order of the direction to reach the ending point in the
    // shortest path
    for (int i = 0; i < path.size() - 1; i++)
    { // the size is path.size()-1 because we don't need to perform
        // any direction command momentarily reaching the last node(ending)
        for (int j = 0; j < 4; j++)
        {
            int dx_ = path[i].first + dx[j];
            int dy_ = path[i].second + dy[j];
            if (dx_ == path[i + 1].first && dy_ == path[i + 1].second) // like I said, here we are
            // comparing the current node's four direction adjacent nodes with the next node. We will
            // take the specific direction whose difference will match.
            {
                ans.push_back(dir[j]);
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    cout << ans;
    return 0;
}