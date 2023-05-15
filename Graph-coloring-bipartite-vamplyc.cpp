/**
The Vampires and Lykans are fighting each other to death. The war has become so fierce that, none
knows who will win. The humans want to know who will survive finally. But humans are afraid of going
to the battlefield.

So, they made a plan. They collected the information from the newspapers of Vampires and Lykans.
They found the information about all the dual fights. Dual fight means a fight between a Lykan and
a Vampire. They know the name of the dual fighters, but don't know which one of them is a Vampire or
a Lykan.

So, the humans listed all the rivals. They want to find the maximum possible number of Vampires or
Lykans.

Input
Input starts with an integer T (≤ 10), denoting the number of test cases.

Each case contains an integer n (1 ≤ n ≤ 10^5), denoting the number of dual fights. Each of the next
n lines will contain two different integers u v (1 ≤ u, v ≤ 20000) denoting there was a fight between
u and v. No rival will be reported more than once.

Output
For each case, print the case number and the maximum possible members of any race.
Input:
2
2
1 2
2 3
3
1 2
2 3
4 2
Output :
Case 1: 2
Case 2: 3

It's quite like the coloring bipartite problem. But here, we don't have the input of nodes. We have
to do it by taking the max of the nodes while taking the inputs.
102, 107, 114th lines are the key lines.
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 20001;
int visited[N];
int vamp = 0;
int lyc = 0;
int team[N];
vector<int> rival[N];

void fight(int node)
{
    visited[node] = 1;
    for (int adj_node : rival[node])
    {
        if (visited[adj_node] == 0)
        {
            if (team[node] == 1)
            {
                team[adj_node] = 2;
                lyc++;
            }
            else
            {
                team[adj_node] = 1;
                vamp++;
            }
            fight(adj_node);
        }
        else
            continue;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, test = 1;
    scanf("%d", &t);

    while (t--)
    {
        int duals;
        scanf("%d", &duals);

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            rival[i].clear();
            visited[i] = 0;
        }

        int max_node = 0;
        for (int i = 0; i < duals; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            rival[u].push_back(v);
            rival[v].push_back(u);
            max_node = max(max_node, max(u, v));
        }

        for (int i = 1; i <= max_node; i++)
        {
            vamp = 0, lyc = 0;
            if (visited[i] == 0 && rival[i].size() > 0)
            {
                vamp++;
                team[i] = 1;
                fight(i);
            }
            ans += max(vamp, lyc); // there can be separate subgraphs. so we are considering them
            // separately and everytime taking a node, we are resetting the value of vamp and lyc
            // then we are adding the max of them to the answer. just because of the possibility of
            // having subgraphs.
        }

        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}
