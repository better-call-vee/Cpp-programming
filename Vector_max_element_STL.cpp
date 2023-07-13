// https://codeforces.com/contest/1433/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

bool GayVector(const vector<int> &chck)
{
    int firstElement = chck[0];
    for (int i = 1; i < chck.size(); i++)
        if (chck[i] != firstElement)
            return false;

    return true;
}

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> Piranhas(n);

        int index = -1;

        for (int i = 0; i < n; i++)
            cin >> Piranhas[i];

        int maxo = *max_element(Piranhas.begin(), Piranhas.end());

        if (GayVector(Piranhas))
        {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (Piranhas[i] == maxo && i > 0)
            {
                if (Piranhas[i] > Piranhas[i - 1] || Piranhas[i] > Piranhas[i + 1])
                {
                    index = i + 1;
                    break;
                }
            }
            else if (Piranhas[i] == maxo && i == 0)
            {
                if (Piranhas[i] > Piranhas[i + 1])
                {
                    index = i + 1;
                    break;
                }
            }

            else if (Piranhas[i] == maxo && i == n - 1)
            {
                if (Piranhas[i] > Piranhas[i - 1])
                {
                    index = i + 1;
                    break;
                }
            }
        }

        cout << index << "\n";
    }

    return 0;
}
