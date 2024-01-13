#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://codeforces.com/problemset/problem/835/C
// we just need to output the count of stars which are included in the
// view rectangle.
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q, c, x, y, s, t, x1, y1, x2, y2;
    cin >> n >> q >> c;
    vector<vector<vector<int>>> stars(
        c + 1, vector<vector<int>>(101, vector<int>(101, 0)));
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> s;
        stars[s][x][y]++;
    }
    for(int br = 0; br <= c; br++)
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= 100; j++)
                stars[br][i][j] = stars[br][i][j] + stars[br][i][j - 1] +
                                  stars[br][i - 1][j] - stars[br][i - 1][j - 1];
    for(int i = 0; i < q; i++) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for(int br = 0; br <= c; br++) {
            int brightness = (br + t) % (c + 1); // here, c + 1 because, after
            // reaching c, the brightness will be reset back to 0. suppose, the
            // brightness has reached c, it will be c(c % c+1 = c). but when it
            // will reach c+1, it will become 0.
            int cnt = stars[br][x2][y2] - stars[br][x1 - 1][y2] -
                      stars[br][x2][y1 - 1] + stars[br][x1 - 1][y1 - 1];
            ans += brightness * cnt;
        }
        cout << ans << "\n";
    }
    return 0;
}