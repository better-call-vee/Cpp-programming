/**
I am a student of Information and communications Technology. There are some courses
remaining for my semester. 101, 201, 301, 131, 231.
To do 301, I have to complete prerequisitely 201 & for 201, I need 101.
To start 231, I have to complete prerequisitely both 131 & 201. Now I have gone
to a guide to be instructed about the courses. He told me two sequences:
101->131->201->231->301.

101->201->301
        |-->231
    131---->231

He said he can suggest me more sequences. But I chose the first one.
All are correct.
Topological sorting is like this.
This is called Dependency graph. Dependency graph will always be directed graph

##CYCLIC Directed graph can't be a dependency graph.

1--->2---->3    suppose here, we want to take the no. 2. then we need to take 1 and
     ^      \   4. 1 taken. taking 4, but for 4, we need to take 3. for taking 3,
     |      _\/ we need to take 2!!! So, for cyclic graph, it's not possible.
     |--------4

Topological sorting can't be done with cyclic or undirected graph.
If we make any undirected graph directed, there will be multiple cycles created
easily.

Topological sorting can only be done with DAG(directed acyclic graph)
**/

/**
<<<A SIMULATION>>>
Will do with DFS.
101->201->301
        |-->
            |231
    131---->
Starting with 201, it has two adjacent nodes(301 and 231). First we will go to 301.
301 has become a done node, it has no adjacent node, 201 was paused, now we are
returning to it again. We will store the done nodes in a stack named "done".
Done[301].
now, going to 231. 231 done. back to 201 and 201 is also done. Done[301, 231, 201]
now, going to 101. 101's only adjacent node 201 is already done. So, 101 is also
done: Done[301, 231, 201, 101].
Notice one thing, we ain't getting any paused adjacent node while exploring which
proves that the graph is not cyclic.
In the end, 131 will be pushed to the stack. Then we will pop all the elements
of the stack one by one.
we will get: 131, 101, 201, 231, 301. which is a correct sequence for this graph's
topological sorting.
**/

/**
A PROBLEM: https://cses.fi/problemset/task/1679
It's quite the same as my given example.
Input:
5 3
1 2
3 1
4 5

4--->5 (5's prerequisite 4)
3--->1--->2 (1's prerequisite 3 and 2's prerequisite 1)

Output:
3 4 1 5 2
**/

//suppose, our inputs will only be acyclic graphs. for cyclic graph, we need
//to write some lines to check and give the error output.

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int>adj_list[N];
int visited[N];

stack<int>done;

void dfs(int node)
{
    visited[node] = 1;
    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
    done.push(node); //after the dfs is done, we're pushing the node in the
    //stack.(for a particular node)
}

int main ()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }

    while(!done.empty())
    {
        cout<<done.top()<<" ";
        done.pop();
    }

    return 0;
}


/*
Or this can be done by indegree count.

*/