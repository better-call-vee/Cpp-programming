https : // codeforces.com/contest/988/problem/B

#include <bits/stdc++.h>
        using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

bool Sub(string &a, string &b)
{
    return b.find(a) != string::npos;
}

bool stcmp(string &a, string &b)
{
    if (a.empty() && !b.empty())
        return true;

    if (a == b)
        return false;

    return Sub(a, b);
}

int main()
{
    fast;

    int n;
    cin >> n;

    if (n < 2)
    {

        string s;
        cin >> s;

        cout << "YES\n"
             << s;

        return 0;
    }

    vector<string> st(n);

    for (int i = 0; i < n; i++)
        cin >> st[i];

    sort(st.begin(), st.end(), stcmp);

    bool reordered = true;
    for (int i = 1; i < n; i++)
        if (!Sub(st[i - 1], st[i]))
        {
            reordered = false;
            break;
        }

    if (reordered)
    {
        cout << "YES\n";
        for (string &s : st)
            cout << s << "\n";
    }
    else
        cout << "NO\n";

    return 0;
}