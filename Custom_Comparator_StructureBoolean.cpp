// https://codeforces.com/contest/1849/problem/B

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

struct CmpPairs
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpPairs> Monsters;
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            Monsters.push({inp, i + 1});
        }

        while (!Monsters.empty())
        {
            pair<int, int> curr = Monsters.top();
            Monsters.pop();

            int cmp = curr.first - k;
            if (cmp <= 0)
                result.push_back(curr.second);

            else
                Monsters.push({cmp, curr.second});
        }

        for (int mNO : result)
            cout << mNO << " ";
        cout << "\n";
    }

    return 0;
}