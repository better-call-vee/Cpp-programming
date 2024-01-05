#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q, x1, x2, y1, y2, x;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)),
        diff(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x;
        diff[x1][y1] += x;
        diff[x1][y2 + 1] -= x;
        diff[x2 + 1][y1] -= x;
        diff[x2 + 1][y2 + 1] += x;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            diff[i][j] = diff[i - 1][j] + diff[i][j - 1] + diff[i][j] -
                         diff[i - 1][j - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) a[i][j] += diff[i][j];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
/*
Input:
4 5
1 2 3 1 1
1 1 2 0 1
0 4 4 0 1
0 1 2 3 4
1
2 2 3 4 5

Line 15:
Makes it looks like :
1 2 3 1 1
  |--------
1 |6 7 5 6|
0 |9 9 5 6|
0 |6 7 8 9|from a[2][1], it takes the whole rectangle and adds 5
  ---------

Line 16:
Makes it looks like
1 2 3 1 1
 -------
1|6 7 5| 1
0|9 9 5| 1
0|6 7 8| 4  It now excludes the extra column.

Line 17:
Excludes the extra row but also does subtract extra x from
the a[x2+1][y2+1].
so, finally we add there x.
*/