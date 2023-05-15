#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    const int MAX_SUM = 100 * 1000 + 1;
    vector<bool> possible(MAX_SUM);
    possible[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = MAX_SUM - 1; j >= coins[i]; j--)
        {
            if (possible[j - coins[i]])
                possible[j] = true;
        }
    }

    int distinctSums = 0;

    for (int i = 1; i < MAX_SUM; i++)
    {
        if (possible[i])
            distinctSums++;
    }

    cout << distinctSums << "\n";

    for (int i = 1; i < MAX_SUM; i++)
    {
        if (possible[i])
            cout << i << " ";
    }

    return 0;
}

