#include<bits/stdc++.h>
using namespace std;

const int maxN = 1000;
vector<int>adj[maxN]; //vector is considered as a 2D array. every array's
//each element can contain another vector/vectors.
//এটি দিয়ে array এর মধ্যে vector আছে এইরকম বুঝানো হচ্ছে,
//যেমন: N=3 হলে,
//[ vector<int> adj_list, vector<int> adj_list, vector<int> adj_list]
//এইখানে, 1st vector কে access করতে চাইলে adj_list[0] দিয়ে করা যাবে,
//এখন যদি 1st vector এর 1st element access করতে চাইলে adj_list[0][0] দিয়ে করা যাবে।
//এইভাবে বাকি গুলো access করা যাবে। ধরুন, আপনার নোড যদি চারটা হয় তাহলে চারটা নোডের একটা অ্যারে ক্রিয়েট হবে(adj[4])
//এবং অ্যারে এর প্রত্যেকটা ইনডেক্সে একটা করে ভেক্ট্রর রাখতে পারবেন যেখানে একটা নোড কয়টা নোডের সাথে কানেক্টেড সেই
//নোড গুলো থাকবে। this concept is called nesting in vector.

//now the visited and queue formulas were described in the theory codes.

bool visited[maxN]; //visited checking array. every index has a value of 0 set
//here

void bfs (int s)
{
    queue<int>q;
    cout << s << " ";//initial step where we print the source
    memset(visited, false, sizeof(visited)); //reset visited array , here in
    //place of false, if we write any number, the array will be set with that
    //number for every element
    visited[s] = true; //making source's index 0 to 1 which means marking it
    //as visited.
    q.push(s); //then pushing it to the queue

    while(!q.empty())
    {
        int node = q.front(); //selecting the front node from the queue and
        //storing in a variable.

        q.pop(); //popping the front element from the queue so that next time
        //we can selected the next node, lol I am being too naive just for me
        //so that I can understand this later from anywhere of the world, may
        //Allah bless me.

        for(int child : adj[node])   //exploring the selected node. selected
            //node's children, vector's vector concept.
        {
            if(!visited[child])
            {
                visited[child] = true;
                q.push(child);
                cout<< child << " "; //making visited marked, pushing to queue,
                //printing.
            }

        }
    }
}

int main ()
{
    int n, e;
    cin >> n >> e; //taking the input of number of nodes, edges.
    /**
    suppose, n=10, e=8.

    1 2                      1 -> 2 3                   1
    1 3                      2 -> 1 4                 /   \
    2 4                      3 -> 1 4 6              2     3
    3 4                      4 -> 2 3 6               \   /|
    3 6                      5 ->                       4  |
    4 6                      6 -> 3 4 7 8               |  |
    6 7                      7 -> 6                     6--|
    6 8                      8 -> 6                    / \
                             9 ->                     8   7
                             10 ->
    **/


    for(int i=1; i<=e; i++) //running a loop of number of edges
    {
        int u, v; //taking those two nodes everytime according to the edges
        cin >> u >> v;
        adj[u].push_back(v); //if a node contain an edge with another node, then
        //both of their adjacency list contain themselves
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cout << i << " -> ";
        for(int child : adj[i]) //this child is an iterator, takes each and
        //every element from start to end and it's being printed.
        {
            cout << child << " ";
        }
        cout<<"\n";
    }

    cout<<"\nPrinting by BFS traversal, source=>1 :\n";
    bfs(1);

    cout<<"\nPrinting by BFS traversal, source=>6 :\n";
    bfs(6);

    return 0;
}
