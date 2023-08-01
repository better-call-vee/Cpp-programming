// https://codeforces.com/problemset/problem/1766/B

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
        int n;
        cin >> n;

        string inp;
        cin >> inp;

        bool yeah = false;
        for (int i = 0; i < n - 1; i++)
        {
            string srch = inp.substr(i, 2);

            size_t khoj = inp.find(srch, i + 2); // starting searching from the element after the
            // selected substring.
            if (khoj != string::npos)
            {
                yeah = true;
                break;
            }
        }
        if (yeah)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}