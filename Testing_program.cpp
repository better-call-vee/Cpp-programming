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
        int n, k;
        cin >> n >> k;

        vector<int> prb(n);

        for (int i = 0; i < n; i++)
            cin >> prb[i];

        vector<int> prBB(n);
        prBB = prb;

        sort(prb.begin(), prb.end());
        sort(prBB.begin(), prBB.end(), greater<int>());

        int i = 0, j = 1, err = 0;
        while (j < n)
        {
            if (prb[j] - prb[i] <= k)
            {
                i++;
                j++;
            }
            else
            {
                j++;
                err++;
            }
        }

        i = 0;
        j = 1;
        int err2 = 0;
        while (j < n)
        {
            if (prBB[i] - prBB[j] <= k)
            {
                i++;
                j++;
            }
            else
            {
                j++;
                err2++;
            }
        }

        cout << min(err, err2) << "\n";
    }

    return 0;
}