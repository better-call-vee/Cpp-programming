// https://codeforces.com/problemset/problem/1846/C
// https://github.com/tanvee009/XPSC_ARCHIEVE/tree/main/WEEK%2011/Day_5
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;

        vector<vector<int>> a;

        for (int i = 0; i < n; i++)
        {
            vector<int> t;
            for (int j = 0; j < m; j++)
            {
                int in;
                cin >> in;
                t.push_back(in);
            }
            sort(t.begin(), t.end());
            a.push_back(t); // we are taking a vector for each participant.
        }
        vector<pair<int, pair<int, ll>>> vp; // for index, points and penalties.

        for (int i = 0; i < n; i++)
        {
            int points = 0, tot = 0;
            ll penalty = 0;
            vector<ll> p;
            for (int j = 0; j < m; j++)
            {
                if (tot + a[i][j] > h) // checking if the total time is going beyond fulltime or not.
                    break;
                points++;
                tot += a[i][j];
                if (j == 0)
                    p.push_back(a[i][j]);
                else
                    p.push_back(p.back() + a[i][j]);
            }
            // penalties are calculated counting the summation of each problem's solving moment.
            for (auto now : p)
                penalty += now;
            vp.push_back({i, {points, penalty}});
        }

        sort(vp.begin(), vp.end(), [&](pair<int, pair<int, ll>> x, pair<int, pair<int, ll>> y)
             {
                 // comparing two elements and sorting. this is called custom comparator.
                 if (x.second.first == y.second.first && x.second.second == y.second.second)
                     return x.first < y.first; // if both scores and penalties are the same, then
                 // we have to consider the index number.

                 else if (x.second.first == y.second.first)
                     return x.second.second < y.second.second; // when the scores are the same, we
                 // have consider the one with the lowest penalties

                 return x.second.first > y.second.first; // generally, only when the scores are
                 // different.
             });

        int rank;
        for (int i = 0; i < n; i++)
        {
            if (vp[i].first == 0) // we have to output just Rudolf's rank.
            {
                rank = i + 1;
                break;
            }
        }
        cout << rank << "\n";
    }

    return 0;
}