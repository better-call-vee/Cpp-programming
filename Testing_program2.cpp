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

    string ans;
    cin >> ans;

    sort(ans.begin(), ans.end()); cout<<ans;

    return 0;
}