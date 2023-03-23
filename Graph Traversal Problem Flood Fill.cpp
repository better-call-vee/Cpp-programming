/**
You are given a map of a building, and your task is to count the number of its
rooms. The size of the map is n×m squares, and each square is either floor or wall.
You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n and m : the height and width of the map.

Then there are n lines of m characters describing the map. Each character is
either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000

Example

Input:
5 8
########    when we are starting from a point and doing bfs, then when the
#..#...#    bfs stops, we get one room. the number of bfs run will be equal to
####.#.#    the answer. the bfs traversals will be running until there is no blank
#..#...#    cell(part of a room) remaining.
########

Output:
3

steps:
while there exists an empty cell
   -find an empty unvisited cell
   -run bfs() from that cell
**/

#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
int maze[N][N], visited[N][N];
int n, m;
int new_x, new_y;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(x>=0 && x<n && y>=0 && y<m) return true;
    else return false;
}

bool is_safe(pair<int, int>coord)
{
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y] == -1) return false;
    else return true;
}

void bfs(pair<int, int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second] = 1;
    q.push(src);

    while(!q.empty())
    {
        pair<int, int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            new_x = x + dx[i];
            new_y = y + dy[i];

            pair<int, int>adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

//we'll check if there is any blank cell in the maze. Only when it'll not be
//visited and a existing valid cell in the maze, then we will start a bfs.
pair<int, int>find_unvisited()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main ()
{
    cin >> n >> m;

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
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<maze[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    //it's recommended to check that after modifying the input of grid problem to
    //other expressions

    int room_count = 0;

    while(true)
    {
        pair<int, int>unvisited_cell = find_unvisited();
        if(unvisited_cell == pair<int,int>(-1,-1)) break;
        bfs(unvisited_cell); //when we call a bfs with an unvisited cell, we visit
        //the rest unvisited cells in the room. so, after a bfs, no unvisited cell
        //remains in the room.
        room_count++;
    }

    cout<<"TOTAL ROOMS: "<<room_count;
    return 0;
}


/**
5 8
########
#..#...#
####.#.#
#..#...#
########
for input
**/
































