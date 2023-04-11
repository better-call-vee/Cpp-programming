/*
detect cycle in a weighted directed graph and print the cycle if it is there. Otherwise print "No"
               1
      1<--------------------3
      |  ↖                ↗
      |    ↖            ↗
    1 |      ↖-3      ↗-2
      |        ↖    ↗
      v          ↖↗
      2---------->4
            1

4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj_list;
vector<long long> d;
vector<int> parent;

int main()
{
    int n, m;
    cin >> n >> m;

    adj_list.resize(n + 1);
    d.resize(n + 1);
    parent.resize(n + 1);

    fill(d.begin(), d.end(), LLONG_MAX / 2);
    
    /*
    The LLONG_MAX constant is defined in the <limits.h> or <climits> header file as the maximum value
    that a long long integer can hold. On most platforms, this value is equal to 9223372036854775807, 
    which is a very large number.
    */

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    bool negative_cycle = false;
    // the source detection part still runs without error even we don't define any source node.
    int last_updated_node = -1;

    for (int i = 1; i <= n; i++)
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
                    parent[v] = u;
                    if (i == n)
                    {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if (negative_cycle)
    {
        cout << "YES\n";

        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        last_updated_node = selected_node;

        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == last_updated_node)
            {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
        {
            cout << node << " ";
        }
    }

    else
        cout << "NO";

    return 0;
}