/*
pref[i][j] for all i and j in O(nm) time using the following formula:
pref[i][j]= pref[i−1][j] + pref[i][j−1] − pref[i−1][j−1] + a[i][j].

Description and Visualization:
https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
https://cses.fi/problemset/task/1652/
here is a standard problem to understand 2D prefix sum's mechanism.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q, x1, x2, y1, y2;
    char x;
    cin >> n >> q;
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0)),
        prefix2D(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            if(x == '*') forest[i][j]++;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            prefix2D[i][j] = prefix2D[i - 1][j] + prefix2D[i][j - 1] +
                             forest[i][j] - prefix2D[i - 1][j - 1];
    for(int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        << "\n";
        cout << prefix2D[x2][y2] - prefix2D[x1 - 1][y2] - prefix2D[x2][y1 - 1] +
                    prefix2D[x1 - 1][y1 - 1]
    }

    return 0;
}

/*
Constructing the 2D Prefix Sum Array:

prefix2D[i][j] = prefix2D[i - 1][j] + prefix2D[i][j - 1] + forest[i][j] - prefix2D[i - 1][j - 1]; 
This part of the code calculates the prefix sum for each
cell in a 2D grid.
prefix2D[i][j] represents the sum of all elements in the
rectangle from (1,1) to (i,j).
The formula adds the sum above (prefix2D[i - 1][j]) and the sum to
the left (prefix2D[i][j - 1]) of the current cell, then
adds the current cell value (forest[i][j] which is 1 if there's a tree and 0
otherwise).
It subtracts the sum of the overlapping area (prefix2D[i - 1][j - 1]), which was
added twice (once in each of the left and above sums). This step
effectively builds a 2D prefix sum array that can be used to quickly calculate
the sum of elements in any submatrix of the grid.



Querying the Number of Trees in a Given Rectangle:

cout << prefix2D[x2][y2] - prefix2D[x1 - 1][y2] - prefix2D[x2][y1 - 1] + prefix2D[x1 - 1][y1 - 1];
This part of the code uses the 2D prefix sum array to find the number of trees in a rectangle 
defined by the corners (y1, x1) and (y2, x2). 
prefix2D[x2][y2] gives the sum of elements in the rectangle from (1,1) to
(x2,y2). 
To get the sum within the desired rectangle, it's necessary to subtract
the sums of the areas outside the rectangle but within the larger (1,1) to
(x2,y2) rectangle. These are the areas above (prefix2D[x1 - 1][y2]) and to the
left (prefix2D[x2][y1 - 1]) of the desired rectangle. However, the area that's
both above and to the left gets subtracted twice, so it's added back once
(prefix2D[x1 - 1][y1 - 1]).
*/