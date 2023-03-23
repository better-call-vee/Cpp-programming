//We want to measure how far are the other nodes from a single node with the
//shortest distance.
//Our solution below will only work for Unweighted graphs!
/**
M--------D
|        |\
|        | K------A
|        | |
Z--------S |
 \        \|
  \________B

  Here, suppose we want to go from M to A. If we take the path M->Z->S->B->K->A,
  it will be a long path but if we take M->D->K->A, that'll be a shorter path.
  So, Our job is here => Finding the shortest path for each node from source
  node(M)

  We know BFS. BFS go level by level.

      0       level 0
     / \
    1---2     level 1
        |
    4---3     level 2

    level[adjacent node] = level[head] + 1. Here, 2's level is 1. it's head is
    0 whose level is 0 and plus 1 = 1. here 3's level is 2. It's head is 2 whose
    level is 1+1=2, yo.
    Bfs goes level by level that's why it gives us the shortest path.

**/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector<int>adj_list[N];

bool visited[N];
int level[N]; //taking an array to store the level information.

void bfs(int src)
{
    queue<int>q;

    visited[src] = true;
    level[src] = 0; //source's level will obviously be 0.
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        for(int adj_node: adj_list[head])
        {
            if(!visited[adj_node])
            {
                visited[adj_node] = true;
                level[adj_node] = level[head] + 1; //like I stated before, the
                //level of the current adjacent node will be the level of
                //head + 1.
                q.push(adj_node);
            }
        }
    }
}

int main ()
{
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    bfs(src);

    for(int i=0; i<n; i++)
    {
        cout<<"node "<<i<<" -> level: "<<level[i]<<"\n";
    }

    return 0;
}


/**

0----1----2----3
     |    |
     |    |
     5----4
6 6
0 1
2 3
1 5
1 2
2 4
5 4

**/
