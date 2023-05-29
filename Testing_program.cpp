#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> city;
vector<int> visited1;
vector<int> visited2;
int K;
vector<int> children1;
vector<int> children2;

bool RomJul(int source1, int source2)
{
    visited[source1] = 1;
    vistied[source2] = 1;

    children1.push_back(source1);
    children2.push_back(source2);

    int a = 1;
    while (true)
    {
        if (a > K)
            break;

        int head = children1[0];
        int sz = children1.size();

        for (int i = sz - 1; i >= 0; i--)
        {
            for (int nodes : children1[i])
            {
                visited1[nodes] = 1;
                children.push_back(nodes);
            }
            children1.erase(children1.begin() + i);
        }

        int sz2 = children2.size();
        for(int i=sz2-1; i>=0; i--) {
            for(int nodes: children2[i]) {
                visited2[nodes] = 1;
                if(visited1[nodes] == 1 && visited2[nodes] == 1) return true;
                children2.push_back(nodes);
            }
            children2.erase(children2.begin() + i);
        }
        a++;
    }
}

int main()
{

    int N, E;
    cin >> N >> E;

    city.resize(N + 1);

    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        city[u].push_back(v);
        city[v].push_back(u);
    }

    int source1, source2;
    cin >> source1 >> source2;
    
}