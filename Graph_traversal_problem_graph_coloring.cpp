//graph coloring means we will color the nodes of the graph.
//our problem is:
//we have to color the nodes using one of two colors and the adjacent nodes can't
//have the same color in them
/**
G----R
|    |   It's  called bicoloring
|    |   like this. no adjacent nodes have the same color.
R----G

     A
    / \    not bicolorable. Here, let's simulate the process. We will do this prob
   B---C   lem with DFS. A is the source node, now it will be paused and we will
    \ /    color it with red, moving to B. B is colored with green. it has paused
     D     and checking it's adjacent nodes. first A, but it's visited, and it's
colored Red. So, we are moving to C, as B was green, so C will be colored Red. now,
C will be paused and will check the color with adjacent nodes. here it dies.

there's a property in bicoloring, the graph we'll get for bicoloring must be a
bipartite graph.

      A |------E
     / \|     / \
    B   C    F   G
     \ /     |\ /
      D--------H

B       A
C       D
F       E
G       H

Our problem : https://cses.fi/problemset/task/1668
here, we will consider the teams as colors.
5 3
1 2
1 3
4 5
Output: 1 2 2 1 2 / 1 2 2 2 1 or many more
1st line is the number of pupils and edges
(1)
1---2(2)
|
3(2)    that's it. adjacent nodes/friendships are being devided into two teams

4--5(2)
(1)
if there's no bipartition possible, you've to print "IMPOSSIBLE"
5 4
1 2
1 3
2 3
4 5
IMPOSSIBLE
**/

//Try to simulate with an example to understand properly.

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int visited[N];
int color[N];

vector<int>adj_list[N];

bool dfs(int node) //it will return true if we can bicolor
{
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            //assign different color to adj_node if it was not visited beforehand. 
            if(color[node] == 1) color[adj_node] = 2;
            else color[adj_node] = 1;

            bool is_bicolorable = dfs(adj_node);
            if(!is_bicolorable) return false;
//during the recursion, if we find any occurance between two nodes where we are
//getting false, then we have to stop there and make the whole function false.
        }
        else //if the adjacent node was visited prior to this/heretofore/beforehand.
        {
            //check if color is same or different
            if(color[node] == color[adj_node]) return false;

        }
    }
    return true;
}

int main ()
{

    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bicolorablE = true;

    for(int i=1; i<=nodes; i++)
    {
        if(visited[i]==0)
        {
            color[i] = 1; //if any node is not visited, we are assigning a
            //color for it. and then making it source code. we had to do it in
            //a loop because there can be more teams/graphs like the sample input
            //than one.
            bool ok = dfs(i);
            if(!ok)
            {
                is_bicolorablE = false;
                break;
            }
        }
    }

    if(!is_bicolorablE) cout<<"IMPOSSIBLE";
    else
    {
        for(int i=1; i<=nodes; i++)
        {
            cout<<color[i]<<" ";
        }
    }
    return 0;
}


