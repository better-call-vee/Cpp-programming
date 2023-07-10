#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

vector<int> marked(100001, 0);

int main()
{
    fast;

    int n;
    cin >> n;

    vector<int> multis;

    int maxo = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        multis.push_back(inp);
        maxo = max(inp, maxo);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (maxo % multis[i] == 0 && marked[multis[i]] != 1)
        {
            marked[multis[i]] = 1;
            multis.erase(multis.begin() + i);
        }
    }

    sort(multis.begin(), multis.end());

    cout << maxo << " " << multis[multis.size() - 1];

    return 0;
}