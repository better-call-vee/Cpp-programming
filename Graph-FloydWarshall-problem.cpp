/*
Problem link: https://cses.fi/problemset/task/1672
It's for a bi-directional graph.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> d;

int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    d.resize(n + 1, vector<long long>(n + 1));

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         d[i][j] = 1e9;
    //     }
    // }

    fill(d.begin(), d.end(), vector<long long>(n + 1, 1e18));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);  //in min, both have to be the same data type.
        d[v][u] = min(d[v][u], w);
        /*
        They can give us duplicate paths or two cities can have multiple paths. we will take the
        shortest.
        1  2  4
        1  2  6
        1  2  8
        here we will take the first one only.
        */
    }

    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;

        if (d[u][v] == 1e18)
            cout << -1 << "\n";

        else
            cout << d[u][v] << "\n";
    }

    return 0;
}