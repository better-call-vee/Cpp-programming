/*
Negative cycle detection:
for the nth iteration, if there negative cycle exists, one of the nodes will be relaxed at least frfr.
     5        1
 1------->2------->4
  ↖     ↙
 -10↖ ↙ 2
     3
try to simulate if you don't understand.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<int> d;

int main()
{
    int n, m;
    cin >> n >> m;

    adj_list.resize(n + 1);
    d.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        d[i] = INFINITY;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src = 1;
    d[src] = 0;

    bool negative_cycle = false;

    for (int i = 1; i <= n; i++)     //we need at most n-1 iteration but for cycle detection we need
    //n
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    if (i == n)
                    {
                        negative_cycle = true;
                    }
                }
            }
        }
    }

    if (negative_cycle)
    {
        cout << "Graph has negative cycle";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << "'s shortest distance: "d[i] << "\n";
    }

    return 0;
}