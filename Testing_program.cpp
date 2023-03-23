#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
vector<int>sex[N];
vector<int>visited(N, -1);
int nodes, edges;

void chod(int pussy)
{
    queue<int>dhon;
    visited[pussy] = 1;
    dhon.push(pussy);

    while(!dhon.empty())
    {
        int head = dhon.front();
        dhon.pop();
        for(int maal : sex[head])
        {
            if(visited[maal]==0)
            {
                visited[maal] = 1;
                dhon.push(maal);
            }
        }
    }
}

int findthemofo()
{
    for(int i=0; i<N; i++)
    {
        if(visited[i]==0) return i;
    }
    return -69;
}

int main()
{
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        int one, two;
        cin >> one >> two;
        sex[one].push_back(two);
        sex[two].push_back(one);
        visited[one] = 0;
        visited[two] = 0;
    }
    int chodacount = 0;
    while(true)
    {
        int maagi = findthemofo();
        if(maagi==-69) break;
        else chod(maagi);
        chodacount++;
    }

    cout<<"TOTAL CHODACHODI COMPONENTS: "<<chodacount;

    return 0;
}
/**
6 5
1 2
1 3
2 3
4 5
6 6
**/
