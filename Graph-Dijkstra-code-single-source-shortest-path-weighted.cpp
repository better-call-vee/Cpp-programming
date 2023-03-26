//There are other efficient ways to do Dijkstra.

#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
const int N = 1e5 + 5;
const int INF = 1e9;
// depends on the problems. Which problem has comparably a less weight, we
// should set INF to 1e9 or less. Otherwise, for large weight, we should set INF to long long and 1e18.

vector<pair<int, int>> adj_list[N];

int d[N], visited[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int selectednode = -1;
        // that means we haven't yet set any selectednode! not a single one yet
        // see the first row of the simulation tables

        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            // we don't want to bother about the visited nodes(invalid/done nodes)

            // peaking the unvisited node with the least d[node]
            if (selectednode == -1 || d[selectednode] > d[j])
            {
                selectednode = j;
            }
            // lemme give an example: let, selectednode = 2 and j = 4
            // d[2] > d[4] -> then we will definitely select the node with less distance. which is j.
            // and if the first condition is met, we won't go for the second(rule of OR). If it wasn't
            // at the beginning, there would have been an error. d[-1] would go out of bound for the
            // unselected node.

            visited[selectednode] = 1;

            for (auto adj_entry : adj_list[selectednode])
            { // adjacent nodes are pairs, so, using auto
                int adj_node = adj_entry.first;
                int edgecost = adj_entry.second;

                if (d[selectednode] + edgecost < d[adj_node])
                {
                    d[adj_node] = d[selectednode] + edgecost;
                }
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\n";

    return 0;
}
/*
1          4
| \4    3/   \2
|   \   /      \
|4    3-----6---6
|   /  \ 1    /
| /2     \  /3
2          5

6 8
1 2 4
1 3 4
2 3 2
3 4 3
4 6 2
3 6 6
3 5 1
5 6 3
*/