// Graph's complexity depends on Vertices and Edges.
// n nodes => (n * (n - 1)) / 2 highest edges. (n C 2);
// sparse graph (less edges) , densed graph
/*
"Simple" path : no node is visited multiple times generally.

Degree sum of a graph : 2 * edge count
Degree is the count of edges a vertice has.

Handshaking lemme: the nodes, which have odd number of degree,
this type in total will be even numbered.
suppose, a graph have 5 nodes, 2 nodes may have degree of 3.
but there can't be any 1/3/5 nodes which have odd number of
degrees.

Summation of in degree == summation of out degree in directed graph
    (1) -----> (2)
     |
     |
     v
    (3) -----> (4)

1 -> in degree = 0 out degree = 2
2 -> in degree = 1 out degree = 0
3 -> in degree = 1 out degree = 1
4 -> in degree = 1 out degree = 0
3 == 3


*/

/*
### Graph Representation: Adjacency List vs. Adjacency Matrix ###

**Adjacency Matrix:**
- A 2D matrix (V x V) where each cell (i, j) indicates the presence/weight of an
edge between node i and node j.
- Efficient for dense graphs (many edges).
- Allows O(1) time complexity to check if two nodes are adjacent.
- Space complexity: O(V^2), even for sparse graphs.

**Adjacency List:**
- Each vertex has a list of its adjacent vertices or edges stored as a list,
vector, or set.
- Efficient for sparse graphs (few edges).
- Space complexity: O(V + E).
- Checking adjacency is slower (O(degree of node), unless enhanced using a
set/hashmap).
- Efficient for calculating indegree, outdegree (directed graph), and degree
(undirected graph).

###
1. Adjacency Matrix is efficient for dense graphs but with less edges.
2. Adjacency List is better for sparse graphs.
3. Checking adjacency is straightforward in a matrix, while it can be optimized
in a list using sets or hashmaps.
4. Degree calculations are easier with adjacency lists.

Below are two implementations:
1. Adjacency Matrix for a dense graph.
2. Adjacency List (optimized with `std::set`) for a sparse graph with degree
calculations.
*/
// Adjacency Matrix
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vert = 4;
    vector<vector<int>> adj(vert, vector<int>(vert, 0));

    adj[0][1] = 1, adj[1][0] = 1;
    adj[1][2] = 1, adj[2][1] = 1;
    adj[2][3] = 1, adj[3][2] = 1;
    adj[3][0] = 1, adj[0][3] = 1;

    cout << (adj[0][1] ? "Yes" : "No") << endl;

    for(const auto &row : adj) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}

// Adjacency List
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int vert = 4;

    // Adjacency List using vector of vectors
    vector<vector<int>> adj_vec(vert);
    adj_vec[0].push_back(1);
    adj_vec[1].push_back(2);
    adj_vec[2].push_back(3);
    adj_vec[3].push_back(0);

    // Adjacency List using vector of sets
    vector<set<int>> adj_set(vert);
    adj_set[0].insert(1);
    adj_set[1].insert(2);
    adj_set[2].insert(3);
    adj_set[3].insert(0);

    // Adjacency List using vector of unordered_maps
    vector<unordered_map<int, int>> adj_map(vert);
    adj_map[0][1] = 1;
    adj_map[1][2] = 1;
    adj_map[2][3] = 1;
    adj_map[3][0] = 1;

    // Calculate indegree, outdegree, and total degree
    vector<int> in_deg(vert, 0), out_deg(vert, 0), tot_deg(vert, 0);

    for(int i = 0; i < vert; ++i) {
        for(int nei : adj_vec[i]) {
            out_deg[i]++;
            in_deg[nei]++;
        }
        tot_deg[i] = in_deg[i] + out_deg[i];
    }

    cout << "Degrees\n";
    for(int i = 0; i < vert; ++i) {
        cout << i << ": In=" << in_deg[i] << ", Out=" << out_deg[i]
             << ", Total=" << tot_deg[i] << endl;
    }
    return 0;
}





