
/*
6 6
1 2
2 3
2 4
2 6
3 4
4 5

  1-----2-----6
       / \  
      3---4----5
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> noed;
vector<int> visited;
vector<int> parent;
vector<int> theway;

void pathanddfs(int s, int d)
{
    visited[s] = 1;

    for (int go : noed[s])
    {
        if (visited[go] == 0)
        {
            if (go == d)
            {
                parent[go] = s;
                return;
            }
            visited[go] = 1;
            parent[go] = s;
            pathanddfs(go, d);
        }
    }
}

int main()
{

    cout << "Enter the number of nodes and edges: ";
    int nodes, edges;
    cin >> nodes >> edges;

    cout << "Enter the Source and Destination nodes: ";
    int source, destination;
    cin >> source >> destination;

    noed.resize(nodes + 1);
    visited.resize(nodes + 1);
    parent.resize(nodes + 1);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        noed[a].push_back(b);
        noed[b].push_back(a);
    }

    pathanddfs(source, destination);

    int temp = destination;
    theway.push_back(temp);

    while (temp != source)
    {
        theway.push_back(parent[temp]);
        temp = parent[temp];
    }

    reverse(theway.begin(), theway.end());

    cout << "\nThe DFS path from source to destination: ";
    for (int val : theway)
    {
        cout << val << " ";
    }

    return 0;
}