#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> game(n, 0);

        for (int i = 0; i < n; i++)
            cin >> game[i];

        int dif = abs(game[0] - game[1]);
        for (int i = 1; i < n - 1; i++)
        {
            int score = max(abs(game[i] - game[i - 1]), abs(game[i + 1] - game[i]));
            dif = min(dif, score);
        }
        dif = min(dif, abs(game[n - 1] - game[n - 2]));
        cout << dif << "\n";
    }

    return 0;
}
