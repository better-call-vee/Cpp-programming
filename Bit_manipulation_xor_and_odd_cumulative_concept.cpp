#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 1, maxi = 4001;
bitset<maxi> prefix_mask_a[N], prefix_mask_b[N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q, l1, r1, l2, r2;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    prefix_mask_a[0].reset();
    for(int i = 1; i <= n; i++) {
        prefix_mask_a[i] = prefix_mask_a[i - 1];
        prefix_mask_a[i].flip(a[i]);
    }
    // if a number is present odd number of times, the prefix_mask_a[i][a[i]]
    // will end up with bitset consisting only 1. it's like a vector of bitsets
    // where we store bitset for the values. suppose, in 'a' array 10 is present
    // 3 times, first it will be 1, then 0, then again 1. it's
    // prefix_mask_a[i][a[i]] ^= 1; where that value's bit will be flipped.
    // here actually we store the odd count. suppose, we have 10 2 3 2 3 3
    // then only the 10th bit and 3rd bit will contain 1, rest will be 0.
    prefix_mask_b[0].reset();
    for(int i = 1; i <= m; i++) {
        prefix_mask_b[i] = prefix_mask_b[i - 1];
        prefix_mask_b[i].flip(b[i]);
    }
    while(q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        auto subarray_mask_a = prefix_mask_a[r1] ^ prefix_mask_a[l1 - 1];
        auto subarray_mask_b = prefix_mask_b[r2] ^ prefix_mask_b[l2 - 1];
        auto merged_mask = subarray_mask_a ^ subarray_mask_b;
        // in the end we use cumulative xor concept and take the all xor count.
        int odds = merged_mask.count();
        // the numbers of set bit in the end is the answer.
        cout << odds << "\n";
    }
    return 0;
}

/*
https://www.codechef.com/problems/ODTPIC
don't worry, the total odd count in the end will be the merged odd count.
*/