/*
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a
city, goes through two or more other cities, and finally returns to the starting city. Every
intermediate city on the route has to be distinct.

Input
The first input line has two integers n and m : the number of cities and roads. The cities are
numbered 1,2,…,n.

Then, there are m lines describing the roads. Each line has two integers a and b : there is a road
between those cities.

Every road is between two different cities, and there is at most one road between any two cities.

Output
First print an integer k : the number of cities on the route. Then print k cities in the order
they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2*10^5
1≤a,b≤n

Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

  1------3
  | \    |
  |   \  |
  2     \| 
  |      5
  |     / 
  4-----       

Output:
4
3 5 1 3 or,
5 3 1 5
*/

//let's do it in a different way with the structure. With structure we can quite create a
//class of variables of different datatypes and use them as a single datatype. We can save
//memory by doing this for this problem.

#include <bits/stdc++.h>
using namespace std;

struct GraphData
{
    vector<vector<int>> cities;  //vector of vector for the adjacency list.
    vector<int> parent; //we need to detect cycle for an undirected graph that's why we need
    //a parent vector
    vector<int> visited;
    int city;
    int cyc1; //when we get a cycle, the source node will be set to this variable
    int cyc2; //and the adjacent node of the source code will be set to this variable of
    //that cycle edge.
    //think for the 1---5 cycle. 5 is cyc1 & 1 is cyc2.
};

bool thecycle(int src, GraphData &data)
{
    data.visited[src] = 1;

    for (int links : data.cities[src])
    {
        if (data.parent[src] == links)
            continue;

        if (data.visited[links] == 0)
        {
            data.parent[links] = src;
            bool dfs = thecycle(links, data);
            if (dfs)
            {
                return true;
            }
        }
        if (data.visited[links] == 1)
        { //here is where we get that pair. when we get a visited==1 node(paused), we detect
        //the cycle & then we store the pair.
            data.cyc1 = src;
            data.cyc2 = links;
            return true;
        }
    }
    data.visited[src] = 2;
    return false;
}

int main()
{
    int city, roads;
    cin >> city >> roads;

    GraphData data;
    data.city = city;
    data.cities.resize(city + 1);
    data.parent.resize(city + 1);
    data.visited.resize(city + 1);
    data.cyc1 = -1;
    data.cyc2 = -1;

    for (int i = 0; i < roads; i++)
    {
        int a, b;
        cin >> a >> b;
        data.cities[a].push_back(b);
        data.cities[b].push_back(a);
    }

    bool gotcycle = false;

    for (int i = 1; i <= city; i++)
    {
        if (data.visited[i] == 0)
        {
            bool gocyc = thecycle(i, data);
            if (gocyc)
            {
                gotcycle = true;
                break;
            }
        }
    }

    if (gotcycle)
    {
        vector<int> ans;
        int temp = data.cyc1;  //we have to set the first one to a temporary variable

        ans.push_back(temp);

//if we traverse the cycle with the parent nodes(way of path printing), we will be able to
//print the cycle.
        while (temp != data.cyc2)
        {
            ans.push_back(data.parent[temp]);
            temp = data.parent[temp]; //we have to be careful in these places. eg: if we write
            //data.parent[cyc1], it will be a complete wrong syntax.
        }

        ans.push_back(data.cyc1);
        cout << ans.size() << "\n";

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}
