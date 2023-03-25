/**
╔═══╦═══╦═══╗
║   ║ M ║ x ║
╠═══╬═══╬═══╣
║   ║ x ║ x ║
╠═══╬═══╬═══╣
║   ║   ║ F ║
╚═══╩═══╩═══╝
M wants to reach F. x are the main obstacles here. M can only go left right
up down.
Think the grid as a graph. the x nodes will be removed and the other will remain.
we will bfs it by going up down right left and checking if we can move up/down/
right/left.

It's like a maze or labyrinth.

n--n
|
n      it will be a graph like this eventually.
|
n--n--n

PROBLEM STATEMENT:
You are given a map of a labyrinth, and your task is to find a path from start to
end. You can walk left, right, up and down.

Input

The first input line has two integers n
 and m
: the height and width of the map.

Then there are n
 lines of m
 characters describing the labyrinth. Each character is . (floor), # (wall), A
 (start), or B (end). There is exactly one A and one B in the input.

Output

First print "YES", if there is a path, and "NO" otherwise.

5 8
########
#.A#...#
#.##.#B#
#......#
########
output->
YES
9

**/

#include<bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze [N][N], visited[N][N];
int level [N][N];

int n, m; //row and column
int new_x, new_y;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

bool is_safe(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y] == -1) return false;
    return true;
}

void bfs(pair<int, int>src)
{

    queue<pair<int, int>>q; //because it's a grid.
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0; //defining source's level to go on.

    q.push(src);
    while(!q.empty())
    {
        pair<int,int>head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;
//there are four adjacent nodes. right left up down.
//y for columns, x for rows.
//in a 2D array. we will get the
//right -> (x, y + 1)
//left  -> (x, y - 1)
//up    -> (x - 1, y) okay, if you go up in an 2d array, the row number
//gets decreased.
//down  -> (x + 1, y)
        /*
        1. is the cell within the maze?
        2. is the cell forbidden / wall?
        3. is the cell visited?
        these checks will be on those four nodes.

        x   y    the values we have to add for right, left, up, down.
        0   1
        0  -1
        -1  0
        1   0

        dx[] = {0,0,-1,-1}  this is direction array.
        dy[] = {1,-1,0,0}
        */
        for(int i=0; i<4; i++)
        {
            new_x = x + dx[i];
            new_y = y + dy[i]; //we will get the four adjacent nodes through
            //this. four times => four adjacent nodes.

            pair<int, int> adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y]==0)
            {
//checking the eligiblity
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1; //level equation;
                q.push(adj_node);
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    pair<int, int>src, dst;

    for(int i=0; i<n; i++)
    {
        //it implies that whose levels are -1, we have not visited them. we
        //need this to check if the destination has been reached or not.
        for(int j=0; j<m; j++)
        {
            level[i][j] = -1;
        }
    } //though we could do this with visited array. but just a logic example,
    //might need later.

    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<m; j++)
        {
            if(input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if(input[j] == 'A')
            {
                src = {i,j}; //because it's a grid
            }
            else if(input[j] == 'B')
            {
                dst = {i,j};
            }
        }
    }

//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            cout<<maze[i][j]<<"\t";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
    bfs(src);

    if(level[dst.first][dst.second] == -1)
    {
        cout<<"NO"<<"\n";
    }
    else
    {
        cout<<"YES"<<"\n";
        cout<<level[dst.first][dst.second]<<"\n";
    }

}


