/*
I just need to print the ids of the pairs which make a sum of exactly "k"

☞ Better.Call.Vee ☜
created: 21th November, 2023 13:32:25 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multimap<int, int> ids;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, inp, got = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> inp;x
        auto srch = ids.find(k - inp);
        if(srch != ids.end()) {
            got = 1;
            cout << i + 1 << " " << srch->second << "\n"; // pointer accessing.
            ids.erase(srch);
        }
        ids.insert({inp, i + 1});
    }

    if(!got) cout << "IMPOSSIBLE";

    return 0;
}