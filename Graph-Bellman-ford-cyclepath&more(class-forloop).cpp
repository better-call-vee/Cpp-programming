#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

class Edge
{
public:
    int a, b;
    long long c;
    Edge() : a(0), b(0), c(0) {} //default constructor.
    /*
    Edge() {
        a = 0;
        b = 0;
        c = 0;
    }
    */
    Edge(int a, int b, long long c) : a(a), b(b), c(c) {}
    /*
    constructing every input and edge. parameterized constructor
    Edge(int a, int b, long long c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    */
};

vector<Edge> thelist;
vector<long long> dist;
vector<int> parent;

int main()
{
    int n, m;
    cin >> n >> m;

    thelist.resize(m); //we are resizing to the size of edge number because
    //we will consider the algorithm according to the edges. We can't do it
    //with node by node, for that we need vector of vector which is more
    //tiresome.
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
//it's an infinite loop, for every iteration the cur is being set to it's parent
//node.
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

/**
Sample Input 1-

4 5
1 2 2
2 3 2
1 4 1
3 1 -7
3 4 -2

Sample Output 1-

YES
1 2 3 1

Sample Input 2-

6 11
1 3 18
2 4 -5
3 5 -5
4 1 -5
5 6 -6
6 1 3
1 2 19
2 3 -5
3 4 -5
4 5 -5
5 1 -5

Sample Output 2-

YES
1 2 3 4 5 1 / 5 1 2 3 4 5

**/
