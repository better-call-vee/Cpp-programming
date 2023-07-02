// https://codeforces.com/problemset/problem/1843/D

/*
It's a problem where there will be an apple tree and a vertice can contain at most 2 apples.
Every apple will fall eventually. We have to count the ways of the apples' falling on the ground.
we will have queries(apple will be falling from two nodes)
suppose a tree
       1
       |
       2
       |
       3
     /   \
    4     5

here if the queries are:
3 4 => the combination will be 2*1 = 2. from node 3 there are two possibilities => 4, 5. from node
4, there are one possibility => 4. 
1 3 => the combination will be 2*2 = 4. from node 3 there are two leaf nodes+from node 1 there are
eventually 2 leaf nodes. 
like this. but here the main concept is calculating leaf nodes.
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> v[200005];
long long leaf[200005];
bool visited[200005];
long long count_leaf(long long src) //at first we get the main source(root, which is written in the question)
{
    visited[src] = true; //we go on making the source visited.
    long long ans = 0; //taking the ans variable set to zero which will ultimately count the number
    //of leaf nodes from each node.
    bool last = true; // checking if it's the last node or not. it's actually our base case. if it's 
    //the last node(the parametre of the function), then we set the leaf[src] to 1. it's also a sign
    //of using dp.

    for (long long i = 0; i < v[src].size(); i++)
    {
        if (!visited[v[src][i]])
        {
            last = false; //if we gets an unvisited node, then we make the last false, because
            //there might be a chance that it's not the last node. rather, it may have children.
            ans += count_leaf(v[src][i]); //recursion.
        }
    }

    if (last) //but but, when we get the visited of the last node true, and then when we go 
    //recursively and still the visited of the last node is true+it's the leaf node, then simply it 
    //goes out of the for loop and sets the leaf[src] to 1. and thus we get the return and base case
    //is met.
        return leaf[src] = 1; //if this is the last node we return leaf node's count = 1;
    else
        return leaf[src] = ans; //else we go recursively to count the number of leaf nodes.
}

void solve()
{
    long long n;
    cin >> n;
    long long e = n - 1;

    memset(visited, false, sizeof(visited));
    memset(leaf, 0, sizeof(leaf));

    while (e--)
    {
        long long a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    long long q;
    count_leaf(1);
    cin >> q;
    while (q--)
    {
        long long x, y;
        cin >> x >> y;
        cout << leaf[x] * leaf[y] << endl;
    }

    for (long long i = 1; i <= n; i++)
        v[i].clear();
}

int main()
{

    long long t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}