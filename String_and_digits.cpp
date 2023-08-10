//https://codeforces.com/contest/1857/problem/B
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
        string num;
        cin >> num;
        ll sz = num.size();

        if (num[0] >= '5')
        {
            string new_num(sz, '0');
            cout << "1" + new_num << "\n";
            continue;
        }

        for (int i = sz - 1; i > 0; i--)
            if (num[i] >= '5' && num[i - 1] != '9')
                num[i - 1] = char(num[i - 1] + 1);

        int idx = -1;
        bool got = false;
        for (int i = 0; i < sz; i++)
        {
            if (num[i] >= '5')
            {
                idx = i;
                got = true;
                break;
            }
        }

        if (num[0] >= '5')
        {
            string new_num(sz, '0');
            cout << "1" + new_num << "\n";
            continue;
        }

        if (got)
        {
            string add = num.substr(idx, sz - idx);
            string first = num.substr(0, idx);
            for (int i = 0; i < add.size(); i++)
                add[i] = '0';
            num = first + add;
        }
        cout << num << "\n";
    }

    return 0;
}
