/*
DAG => DIRECTED ACYCLIC GRAPH
We've learnt how to find the shortest paths with many algorithms.
Now we will learn how to find the longest path in DAG with DP.
                1
              ↙   ↘
            4 <---- 3
          ↙   ↘
         5      2
Here, suppose we want to reach 4 from 1. The longest path is 2(1-->3-->4).
if we want to count the longest path of a particular node, we can simply take the max of the particular
node's parents' max distances. and finally simply add 1 with that.
Our base case is the distance of root which is constant and 0.
Here, we will use a dp so a node won't be used twice ever. suppose, we want to calculate the Longest
path of 5, but here if 4's longest path is previously calculated so we will simply use the dp array.
The time complexity will be O(V+E) as we previously learned about it in the Graph tutorials(going
down from up, here the exact opposite and more convenient because we are using the nodes only once)

Sample input:
5 5
1 3
1 4
3 4
4 2
4 5
1 4
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> parent_list[N];
int dp[N];
int root, target_node;

int max_distance(int node)
{
    if (node == root)
        return 0;

    if (dp[node] != -1)
        return dp[node];

    int ans = 0;
    for (int parent : parent_list[node])
    {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans; // we need to take the maximum distance among all parents.
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v; // there exists an edge from u to v(u--->v) #directed graph
        cin >> u >> v;
        parent_list[v].push_back(u); // pushing u to v's parent list because we can go to v from u
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }

    cin >> root >> target_node;

    cout << max_distance(target_node);

    return 0;
}