/*
### Depth First Search (DFS) ###

**What is DFS?**
- DFS explores a graph by visiting nodes starting from a source node and moving
as far as possible along each branch before backtracking.
- It uses recursion or an explicit stack to manage the traversal.
- DFS is commonly used for:
  1. Checking if a graph is connected.
  2. Counting connected components.
  3. Solving graph-related queries, like determining if two nodes are connected.

**Complexity: O(V + E)**
- V: Number of vertices (nodes).
- E: Number of edges.
- Why?
  - Each vertex is visited once.
  - Each edge is traversed once (in both directions for undirected graphs).

**1) Graph Connectivity:**
- A graph is connected if there's a path between every pair of vertices.
- Use DFS starting from any node to mark all reachable nodes.
- If all nodes are visited, the graph is connected.

**2) Counting Connected Components:**
- A connected component is a maximal subset of vertices such that any two
vertices in this subset are connected by a path.
- Use DFS iteratively on unvisited nodes and count the DFS calls.

**3) Answering Queries (x, y connected?):**
- Run DFS from node `x` and see if `y` is visited.
- Preprocess all connected components using DFS or Union-Find:
  - Assign each node a component ID.
  - To answer a query, simply check if `x` and `y` share the same component ID
(O(1) query time after preprocessing).

*/

// 1) Graph Connectivity :
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
vector<vector<int>> nds;
vector<int> visited;
void dfs(int u) {
    visited[u] = 1;
    for(int v : nds[u])
        if(!visited[v]) dfs(v);
    return;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ed, x, y;
    cin >> n >> ed;
    nds.resize(n + 1);
    visited.resize(n + 1, 0);
    for(int i = 0; i < ed; i++) {
        cin >> x >> y;
        nds[x].push_back(y);
        nds[y].push_back(x);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cout << "Disconnected\n";
            return 0;
        }
    }
    cout << "Connected\n";
    return 0;
}

// 2) Counting Connected Components
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
vector<vector<int>> nds;
vector<int> visited;
void dfs(int u) {
    visited[u] = 1;
    for(int v : nds[u])
        if(!visited[v]) dfs(v);
    return;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ed, x, y;
    cin >> n >> ed;
    nds.resize(n + 1);
    visited.resize(n + 1, 0);
    for(int i = 0; i < ed; i++) {
        cin >> x >> y;
        nds[x].push_back(y);
        nds[y].push_back(x);
    }
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            components++;
        }
    }
    cout << "Connected Components: " << components << nl;
    return 0;
}

// 3) Answering Queries (x, y connected?)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
vector<vector<int>> nds;
vector<int> comp_id;
void dfs(int u, int id) {
    comp_id[u] = id;
    for(int v : nds[u])
        if(comp_id[v] == 0) dfs(v, id);
    return;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ed, q, x, y;
    cin >> n >> ed;
    nds.resize(n + 1);
    comp_id.resize(n + 1, 0);
    for(int i = 0; i < ed; i++) {
        cin >> x >> y;
        nds[x].push_back(y);
        nds[y].push_back(x);
    }
    int id = 1;
    for(int i = 1; i <= n; i++) {
        if(comp_id[i] == 0) {
            dfs(i, id);
            id++;
        }
    }
    cin >> q;
    while(q--) {
        cin >> x >> y;
        if(comp_id[x] == comp_id[y])
            cout << "Connected\n";
        else
            cout << "Not Connected\n";
    }
    return 0;
}

/*

BICOLORING & BIPARTITE

 * Concept Breakdown:
 * 1. **Graph Representation**:
   We represent the graph using an adjacency list
   where each node (index) has a list of its adjacent nodes (edges).
 * 2. **DFS for Graph Traversal**:
   We use Depth-First Search (DFS) to traverse
   the graph. DFS explores as far as possible along a branch before
   backtracking.
 * 3. **Bipartite Check**:
   A graph is bipartite if we can color the graph using two colors such
   that no two adjacent nodes have the same color.
   During DFS, we assign colors to each node. The parent node gets color 0,
   and each adjacent node gets the opposite color (1 or 0).
   If we encounter a situation where two adjacent nodes have the same
   color, the graph is not bipartite, and we return "NO".
 * 4. **Time Complexity**:
   The algorithm performs a DFS traversal on the graph,
   which takes O(V + E) time, where V is the number of vertices and E is the
   number of edges.
 * 5. **Space Complexity**: O(V + E) due to the adjacency list and color/visited
   arrays.
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; // Maximum number of nodes
vector<int> g[N];      // Adjacency list to store graph
bool vis[N];           // Visited array to track if a node is visited
int col[N];            // Array to store the color of each node
bool ok;               // Boolean flag to check if graph is bipartite

// Depth-First Search (DFS) function to traverse the graph and check bipartite
// condition
void dfs(int u) {
    vis[u] = true;       // Mark the current node as visited
    for(auto v : g[u]) { // Traverse through all adjacent nodes of u
        if(!vis[v]) {    // If adjacent node is not visited
            col[v] = col[u] ^ 1; // Assign opposite color to adjacent node (bicoloring)
            dfs(v);     // Recursively visit adjacent node
        } else {        // If the adjacent node is already visited
            // If the adjacent node has the same color as the current node, the
            // graph is not bipartite
            if(col[u] == col[v]) {
                ok = false; // Set ok to false if graph is not bipartite
            }
        }
    }
}
for(auto v : g[u]) {
	if(!visited[v]) {
		col[v] = col[u] ^ 1;
		dfs(v);
	}
	else {
		if(col[u] == col[v]) ok = false;
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);                  

    int n, m; // Number of nodes and edges
    cin >> n >> m;

    // Building the graph by reading edges
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // Add edge u -> v
        g[v].push_back(u); // Add edge v -> u (undirected graph)
    }

    ok = true;                    // Initially, assume the graph is bipartite
    for(int i = 1; i <= n; i++) { // Iterate through all nodes
        if(!vis[i]) {             // If a node is not visited yet, perform DFS
            col[i] = 0; // Assign initial color 0 to the unvisited node
            dfs(i);     // Start DFS from this node
        }
    }

    // If ok is true, the graph is bipartite, otherwise it's not
    if(ok) {
        cout << "YES\n"; // Output YES if the graph is bipartite
    } else {
        cout << "NO\n"; // Output NO if the graph is not bipartite
    }
}
