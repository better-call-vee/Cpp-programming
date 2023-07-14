#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int n;
    cin >> n;

    vector<int> instability(n);

    for (int i = 0; i < n; i++)
        cin >> instability[i];

    sort(instability.begin(), instability.end());

    int comp1 = instability[n - 2] - instability[0];
    int comp2 = instability[n - 1] - instability[1];

    if (n > 2)
        cout << min(comp1, comp2);

    else
        cout << 0;

    return 0;
}