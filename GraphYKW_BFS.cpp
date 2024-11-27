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