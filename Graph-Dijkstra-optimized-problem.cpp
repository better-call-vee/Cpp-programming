// You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to
// find the shortest path between the vertex 1 and the vertex n.
//  The first line contains two integers n and m (2≤n≤10^5,0≤m≤10^5), where n is the number of
//  vertices and m is the number of edges. Following m lines contain one edge each in form ai, bi and
//  wi (1≤ai,bi≤n,1≤wi≤10^6), where ai, bi are edge endpoints and wi is the length of the edge.
// It is possible that the graph has loops and multiple edges between pair of vertices.
//  Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there
//  are many solutions, print any of them.
/*
5 6                   2         5
1 2 2              1--------2----\
2 5 5              |        |4    \
2 3 4             1|        |      5
1 4 1              4---3----3--1--/
4 3 3
3 5 1
-> 1 4 3 5
*/

#include <bits/stdc++.h>
using namespace std;

/*
here,max n is 10^5 and max weight is 10^6. So, the total cost will be 10^11.
we have to set infinity more than that.
*/

const int N = 1e5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];

// as the INF is a long long value, we have to make the distance array long long as well
long long d[N];

int visited[N], parent[N];
int nodes, edges;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra(int src)
{

    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;

        if (visited[selected_node])
        {
            continue;
        }
        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if (d[selected_node] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
                pq.push({d[adj_node], adj_node});
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

    cout << "Cost of Shortest Path: " << d[nodes] << "\n";

    int current_node = nodes;
    vector<int> path;

    while (true)
    {
        path.push_back(current_node);
        if (current_node == src)
        {
            break;
        }
        current_node = parent[current_node];
    }
    reverse(path.begin(), path.end());

    if (visited[nodes] == 0)
    {
        cout << "Dijkstra not possible\n";
        return 0;
    }

    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/