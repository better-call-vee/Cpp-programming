
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5; //taking a big sized array so that we don't have to go out of
//bound.
//1e5 means 1x10^5.

int visited[N];

vector<int>adj_list[N];

//The DFS algorithm continues to backtrack and explore other branches until it has
//visited all the reachable nodes. Once all the reachable nodes have been visited,
//the DFS algorithm will terminate and return control to the main function.

void dfs(int node) //taking the source
//adj_list[node] will contain this particular node's all adjacent nodes.
//suppose, a node is 6 and it's connected with 8, 5 and 2. So, adj_list[6] => 8,5,2
{
    cout<<node<<endl;
    visited[node] = 1; //making the source visited.

    for(int adj_node: adj_list[node]) { //running a loop on that particular node's
//adjacent list
        if(visited[adj_node] == 0) {
            dfs(adj_node); //if an adjacent node is unvisited, then we will run
//a recursive function on it and it will go on until it's being visited.
        }
    }
}

int main () {
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(0);
    return 0;
}
/**
0-----1------2-----3
      |      |
      |      |
      5------4
0 1
2 3
1 5
5 4
4 2
1 2
**/
