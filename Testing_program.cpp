#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

class Edge
{
public:
    int a, b;
    long long c;
    Edge() : a(0), b(0), c(0) {}
    Edge(int a, int b, long long c) : a(a), b(b), c(c) {}
};

vector<Edge> thelist;
vector<long long> dist;
vector<int> parent;

int main()
{
    int n, m;
    cin >> n >> m;

    thelist.resize(m);
    dist.resize(n + 1, INF);
    parent.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        thelist[i] = Edge(a, b, c);
    }

    int source = 1;
    dist[source] = 0;

    int lastone = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Edge eds = thelist[j];
            int u = eds.a;
            int v = eds.b;
            long long w = eds.c;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                lastone = v;
            }
        }
    }

    if (lastone != -1)
    {
        for (int i = 1; i <= n-1; i++)
        {
            lastone = parent[lastone];
        }

        vector<int> path;
        for (int cur = lastone;; cur = parent[cur])
        {
            path.push_back(cur);
            if (cur == lastone && path.size() > 1)
                break;
        }

        reverse(path.begin(), path.end());

        cout << "YES\n";
        for (int v : path)
            cout << v << " ";
    }

    else
        cout << "NO";

    return 0;
}
