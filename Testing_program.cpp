#include <bits/stdc++.h>
using namespace std;
int t, n, i, k;
string s;
main()
{
    for (scanf("%d", &t); t--; puts(k ? "YES" : "NO"))
    {
        cin >> n >> s;
        for (i = k = 0; i < 5; i++)
            if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020")
                k = 1;
    }
}