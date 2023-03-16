//So, the problem is, I will write n numbers of integers on the board but in a
//random order. I have to rearrange the inputs in such an order that the every
//value's next is either one-third of it or double of it.
//ex:
//In: 6
//In: 4 8 6 3 12 9
//Out: 9 3 6 12 4 8

//It's quite a similar concept to Graph BFS.

//here, each value is a vertex. suppose we are starting from 9. we can go to 6 or
//3 or any other nodes here because they're unvisited but we will go to 3 according
//to the condition and so on
//we will randomly select the source, and a vertex will have edges with the rest
//of the vertices. It's an undirected graph.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll; //the typedef keyword is used to create an alias for the
//long long type, with the name ll. This makes it easier to use long long
//throughout the code, without having to type the entire name every time.
//if I write typedef int yo; from now on everytime when I will write int values
//I will write yo a = 3;, like this instead of int a = 3.

int n; //we are declaring it globally because: look at the bfs function. when
//are checking the ans vector, we are in need of the value of n

map<ll, bool> visited; // taking a map to keep the visited or unvisited update
//keys are the nodes and the seconds are either true or false.

map<ll, vector<ll>> adj; //taken a map for nodes and their adjacents. ll for
//nodes here & vector for each node present there.

vector<ll>ans; //output sequence;
bool found = false;

void bfs(ll s)
{
    queue<ll>q;
    visited[s] = true; //marking the node visited.
    q.push(s);
    ans.push_back(s); //pushing to the answer as well but with possibilites, not
    //certainly

    while(!q.empty())
    {
        if(ans.size()==n) //when we will get the answer sequence.
        {
            found = true;
            return;
        }

        ll parent = q.front();
        q.pop();
        for(ll child : adj[parent])
        {
            if((parent*2)==child && !visited[child]) //only if the child is not
                //visited then we will push to the queue
            {
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
                break; //after getting the desired child, we don't need to
                //look for the rest. then we will move on for the next.
                //suppose, selected node is 3 now, we get the child according
                //to the condition which is 6. now we will move on to 6.
            }
            else if((parent%3==0) && (parent/3==child) && !visited[child])
            {
//suppose: 9 is the
//source/selected node. it's children are 2,4,6,8,12. so, we are checking if 9
//is divisible by 3 and it's one third is same to the child(which is 3 here) or
//not
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
                break;
            }
        }
    }
}

void init () {   //if we couldn't find the actual ans, then we have to clear
    //it again and have to make the visited map clear again. otherwise, it will
    //be an error. we are running the bfs for every node
    ans.clear();
    visited.clear();
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    //it'll be a complete undirected graph, so:
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j) //we don't push the same node as
                //adjacent because that will be a self loop.
            {
                adj[v[i]].push_back(v[j]); //pushing the adjacents for specific
                //nodes in the map.
            }
        }
    }

    for(auto val : adj)
    {
        cout << val.first << " -> ";
        for(auto nod : val.second)
        {
            cout << nod << " ";
        }
        cout << "\n";
    }

    for(auto val : adj)
    {
        bfs(val.first); //we will call bfs for every vertex because we dunno
        //from which node we will get the correct sequence. suppose, for the
        //test case given, how would we know at the first place that our answer's
        //source node is 9!
        if(found) break; //when we will find the answer and it's true, we don't
        //need to run the function anymore.
        init();
    }

    cout<<"\n";
    for(auto val : ans) {
        cout << val << " ";
    }

    return 0;
}

