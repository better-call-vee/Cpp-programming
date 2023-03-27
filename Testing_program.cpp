#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> roads[N];
int visited[N];

int part[N];

bool citiesandroads(int src)
{
    visited[src] = 1;
    for (int con : roads[src])
    {
        if (visited[con] == 0)
        {
            if (part[src] == 1)
                part[con] = 2;
            else
                part[con] = 1;

            bool done = citiesandroads(con);
            if (!done)
                return false;
        }
        else
        {
            if (part[src] == part[con])
                return false;
        }
    }
    return true;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    int src = 1;

    while (true)
    {
        if (visited[src] == 0)
        {
            part[src] = 1;
            bool ok = citiesandroads(src);
            if (!ok)
                break;
        }
        src++;
        if (src > n)
            break;
    }

    return 0;
}