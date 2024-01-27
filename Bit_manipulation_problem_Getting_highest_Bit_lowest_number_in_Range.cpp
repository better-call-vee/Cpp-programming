#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r; ll ans = l;
        for(int i = 0; i < 60; i++)
            if((ans | (1LL << i)) <= r) ans |= (1LL << i);
        cout << ans << "\n";
    }
    return 0;
}

/*
We just need to find the smallest number in between the range which will
have the highest number of bits. We go with ans set to l(lowest number in the
range) from LSB to MSB so that it ensures we take the smallest possible number.
Everytime before setting the bit, we check if it's less or equivalent to r, if
yes, we go on. Thus, we go on and it totally satisfies the condition.
*/