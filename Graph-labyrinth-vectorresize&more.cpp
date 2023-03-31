//You and some monsters are in a labyrinth.Your goal is to reach from cell A to
//one of the safe boundary cell.You can walk left, right, up and down.But you
//can't go to those cells , if there is a monster in that cell or the cell
//contains a wall.You can only go to the safe(.) cell.


#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>>monster;
vector<vector<int>>visited;
pair<int, int>END;
vector<vector<pair<int, int>>>pp;
int v[4] = {1, -1, 0, 0};
int h[4] = {0, 0, -1, 1};
char dir[4] = {'D', 'U', 'L', 'R'};
bool gotcha = false;
vector<pair<int, int>>way;

void montra(int x, int y)
{

    queue<pair<int, int>>tra;
    tra.push({x, y});
    visited[x][y] = 1;
    pp[x][y] = {-1, -1};

    while(!tra.empty())
    {
        pair<int, int>go = tra.front();
        tra.pop();
        if(gotcha) break;
        for(int i=0; i<4; i++)
        {
            int dv = go.first+v[i];
            int dh = go.second+h[i];
            if((monster[dv][dh]=='.') && ((dv==0||dv==n-1) || (dh==0||dh==n-1)))
            {
                visited[dv][dh] = 1;
                pp[dv][dh] = go;
                END.first = dv;
                END.second = dh;
                gotcha = true;
                break;
            }
            else if(monster[dv][dh]!='#' && monster[dv][dh]!='M' && visited[dv][dh]==0)
            {
                visited[dv][dh] = 1;
                pp[dv][dh] = go;
                tra.push({dv, dh});
            }
        }
    }
}

int main ()
{
    cin >> n >> m;
    int starti, startj;

    monster.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m));
    pp.resize(n, vector<pair<int, int>>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> monster[i][j];
            if(monster[i][j] == 'A')
            {
                starti = i;
                startj = j;
            }
        }
    }

    montra(starti, startj);

    if(gotcha)
    {
        cout<<"YES\n";

        int x = END.first;
        int y = END.second;

        way.push_back({x, y});

        while(pp[x][y] != make_pair(-1, -1))
        {
            pair<int, int>p = pp[x][y];
            x = p.first;
            y = p.second;
            way.push_back({x, y});
        }
    }

    reverse(way.begin(), way.end());

    string ans;
    for(int i=0; i<way.size()-1; i++)
    {
        for(int j=0; j<4; j++)
        {
            int nv = way[i].first + v[j];
            int nh = way[i].second + h[j];
            if((nv==way[i+1].first) && (nh==way[i+1].second))
            {
                ans.push_back(dir[j]);
                break;
            }
        }
    }

    cout<<ans.size()<<"\n"<<ans;

    return 0;
}
