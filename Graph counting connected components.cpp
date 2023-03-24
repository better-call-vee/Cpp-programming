#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>nodes[N];
bool visited[N];

void compcount(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int next : nodes[curr])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
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
        int one, two;
        cin >> one >> two;
        nodes[one].push_back(two);
        nodes[two].push_back(one);
    }

    int comp = 0;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            comp++;
            compcount(i);
        }
    }

    cout<<comp;

    return 0;
}


/**
5 3
0 1
1 2
2 0
here the answer will be 3. 4 and 5 are not connected but they're two separate
components and parts of the group

5 4
0 1
1 2
2 3
3 4
here the answer will be 1.
**/
