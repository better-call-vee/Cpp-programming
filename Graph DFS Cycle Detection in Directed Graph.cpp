/**
       3
     +/ \-
1--->2<--4    + means directed up, - means directed down.

this is a cyclic directed graph.

There are 3 types of node in DFS:
1. Unvisited
2. Paused
3. Done

for a DFS directed graph traversal when we get a paused node, it's considered as a
cyclic directed graph.

look at the given example. let's dfs it.
first 1, it's paused, going to 2. 2 is paused, going to 3. 3 paused, going to 4.
again, 4 paused, now we will go to 2. But it was paused. As we can see that we are
moving towards a paused adjacent node, it will be a directed cyclic graph.

2--->3
^    |    here, starting from 1, 1 paused going 5. now, 5 is only a directed
|   \ /   adjacent node of 1. So, 1 is marked done. Now we will select a new
4--->1--->5   node, 2, 2 paused, going on 3. 3 paused, going to 4. 4 paused, going
to 1, 1 is done. so, it's not cyclic yet. going to 2, 2 was paused. it's cyclic

so, for cycle detection, we will check if we find any paused node while traversing.

**/

/**
Problem Statement: https://cses.fi/problemset/task/1678

There are n cities in a country. I have to design a round trip where I can't visit
a city multiple times but once and I have to start and end at the same city.
there will be m flight connections. The flight connections will be one way flights
and thus it's all directed.
Output the number of cities on the route. Then I have to print the cities in the
order they will be visited. any valid solution is granted and if there is no
solution output "IMPOSSIBLE";
4 5
1 3
2 1
2 4
3 2
3 4
Output:
4
2 1 3 2

4 4
1 3
2 1
2 4
3 4
No cycle
**/


#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int>adj_list[N];
int visited[N];

bool detect_cycle(int node)
{
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        /*
        visited[adj_node] == 0 -> unexplored node |apply dfs
        visited[adj_node] == 1 -> Paused node |cycle detected
        visited[adj_node] == 2 -> done node |continue
        */
        if(visited[adj_node] == 0)
        {
            bool got_cycle = detect_cycle(adj_node);
            if(got_cycle) return true;
        }
        else if(visited[adj_node] == 1) return true;
        //we don't need to write any continue statement at the end of the loop
    }
    visited[node] = 2; //when a node exploration is done, we have to mark them as
    //done.
    return false;
}

int main ()
{

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >>v;
        adj_list[u].push_back(v); //we dunno either we can go to v to u or not.
    }
    bool cycle_exists = false;

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = detect_cycle(i);
            if(got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }
    }
    if(cycle_exists) cout<<"Cycle Exists"<<endl;
    else cout<<"No cycle"<<endl;
    return 0;
}
