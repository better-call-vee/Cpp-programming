/*
### Breadth-First Search (BFS) ###

**What is BFS?**

- BFS is a graph traversal algorithm where you explore all the adjacent nodes of
  the current node before moving on to the next level of nodes. (core concept)

- It explores nodes "level by level" or "breadth-wise."
- BFS is typically implemented using a queue.

**How BFS Works:**
1. Start from a source node.
2. Mark it as visited and push it into the queue.
3. While the queue is not empty:
   - Pop the front node from the queue.
   - Explore all its adjacent nodes.
   - If an adjacent node is not visited:
     - Mark it as visited.
     - Push it into the queue.

**Key Characteristics of BFS:**
- BFS guarantees the shortest path (in terms of the number of edges) in an
  unweighted graph.
- Used for:
  - Checking graph connectivity.
  - Finding the shortest path in unweighted graphs.
  - Solving problems like bipartite graph checking, cycle detection, etc.

**Complexity Analysis:**
1. **Time Complexity:**
   - BFS processes each vertex and edge once.
   - Total time complexity: **O(V + E)**, where:
     - **V** is the number of vertices.
     - **E** is the number of edges.
2. **Space Complexity:**
   - **Graph Representation (Adjacency List):** **O(V + E)**.
   - **Visited Array:** **O(V)**, to track which nodes have been visited.
   - **Queue:** **O(V)**, as in the worst case, all vertices could be in the
queue simultaneously.
   - Total space complexity: **O(V + E)**.

**Common Applications of BFS:**
1. Shortest path in unweighted graphs.
2. Checking graph connectivity.
3. Level-order traversal of trees.
4. Solving problems like word ladder, maze solving, and bipartite graph
checking.

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ed, x, y;
    cin >> n >> ed;
    vector<vector<int>> nds(n + 1);
    vector<int> visited(n + 1, 0);
    for(int i = 0; i < ed; i++) {
        cin >> x >> y;
        nds[x].push_back(y);
        nds[y].push_back(x);
    }
    int start;
    cin >> start;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : nds[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return 0;
}

// Shortest path and parents

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int dis[N], par[N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(!vis[v]) {
                q.push(v);
                par[v] = u;          // parenting
                dis[v] = dis[u] + 1; // level
                vis[v] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    int v = 4;
    while(v != 1) {
        cout << v << ' ';
        v = par[v];
    }
    cout << 1 << '\n';
}

// Number of shortest paths:
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int dis[N], par[N],
    sp_count[N]; // sp_count stores the number of shortest paths for each node

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    sp_count[1] = 1; // There is one shortest path to the start node (itself)

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(!vis[v]) {
                q.push(v);
                dis[v] = dis[u] + 1; // Set the distance for the first time
                sp_count[v] =
                    sp_count[u]; // Inherit shortest path count, first time
                                 // visited, from the first parent
                vis[v] = true;
            } else if(dis[v] == dis[u] + 1) {
                sp_count[v] += sp_count[u]; // Add counts from this level.
                                            // everytime it gets another parent.
            }
        }
    }

    // Output distances
    for(int i = 1; i <= n; i++) {
        cout << "Node " << i << ": Distance = " << dis[i]
             << ", Shortest Paths = " << sp_count[i] << '\n';
    }

    return 0;
}

/*
                  (1)
                 / |  \
               /   |   \
             (2)  (3)   (4)
             |     |     |
            (5)   (6)    |
                   \_____|
6 6
1 2
1 3
1 4
2 5
4 6
3 6

*/

/*
Multi source BFS:
Taking a fake node to connect with the multi nodes.
like, taking a grid and connecting with all of it's edge nodes.
and then BFS and check all the edge nodes are possible to visit from every node
in the grid

    Problem:
    You are given an n x m grid where each cell is either open (1) or blocked
(0). You need to determine for each open cell (1) whether it is possible to
reach the boundary of the grid (the "outside") or not. A cell can reach the
outside if there is a path of open cells (1) connecting it to the boundary.

    Approach:
    - Consider the cells on the boundary of the grid as the "outside".
    - Use multi-source BFS starting from all boundary open cells (1).
    - For each open cell inside the grid, check if it can reach the outside by
propagating BFS from the boundary.
    - Output "YES" for reachable cells and "NO" for unreachable cells.

    Input Format:
    - The first line contains two integers n and m (1 ≤ n, m ≤ 1000), the number
of rows and columns in the grid.
    - The next n lines each contain m integers (either 0 or 1), representing the
grid.

    Output Format:
    - For each open cell inside the grid, print "YES" if it can reach the
boundary and "NO" otherwise.

    Sample Input:
    4 4
    1 1 1 1
    1 0 0 1
    1 1 0 1
    1 1 1 1

    Sample Output:
    YES YES YES YES
    YES NO NO YES
    YES YES NO YES
    YES YES YES YES
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1000;   // Maximum grid size
int grid[N][N];       // Grid to store the input
bool reachable[N][N]; // Array to mark which nodes can reach the outside
int n, m;             // n = number of rows, m = number of columns

// Directions for 4-connected neighbors (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Check if a cell is within bounds and not a blocked cell
c

void multisourceBFS() {
    queue<pair<int, int>> q;

    // Initialize reachable array to false
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            reachable[i][j] = false;
        }
    }

    // Add all boundary cells with value 1 to the queue
    for(int i = 0; i < n; i++) {
        if(grid[i][0] == 1) { // Left boundary
            q.push({i, 0});
            reachable[i][0] = true;
        }
        if(grid[i][m - 1] == 1) { // Right boundary
            q.push({i, m - 1});
            reachable[i][m - 1] = true;
        }
    }

    for(int j = 0; j < m; j++) {
        if(grid[0][j] == 1) { // Top boundary
            q.push({0, j});
            reachable[0][j] = true;
        }
        if(grid[n - 1][j] == 1) { // Bottom boundary
            q.push({n - 1, j});
            reachable[n - 1][j] = true;
        }
    }

    // Perform BFS from all boundary cells
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            // Check if the neighbor is within bounds and is not blocked and not
            // already visited
            if(inBounds(nx, ny) && !reachable[nx][ny]) {
                reachable[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // Input the grid, where 1 represents open space and 0 represents blocked
    // space
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Run the BFS from all the boundary cells
    multisourceBFS();

    // Output results for each internal cell (inside the grid)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) { // Only consider open cells
                if(reachable[i][j]) {
                    cout << "YES ";
                } else {
                    cout << "NO ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
