#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, l = 0, r;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> freq;
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(r = 0; r < n; r++) {
        freq[a[r]]++;
        while(freq.size() > k and l <= r) {
            freq[a[l]]--;
            if(freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }

        ans += r - l + 1;
    }
    cout << ans << "\n";
    return 0;
}

/*
https://cses.fi/problemset/task/2428/
we're going in opposite direction. starting with r.

Sliding Window:

The idea is to maintain a window [l, r] that contains at most 'k' distinct
elements. As we slide the window, we keep track of the frequency of each element
in the current window using the 'freq' map. Expanding and Shrinking the Window:

Expanding: Iterate 'r' from 0 to n-1. For each 'r', include a[r] in the current
window and update its frequency in 'freq'.

Shrinking: If the size of 'freq' (the
number of distinct elements) exceeds 'k', shrink the window from the left by
increasing 'l' until the 'freq' size is back to 'k' or less. While doing this,
decrease the frequency of a[l], and if its frequency becomes zero, remove it
from the map. Counting Subarrays:

For each position of 'r', the number of subarrays ending at 'r' with at most 'k'
distinct elements equals 'r - l + 1'.
*/