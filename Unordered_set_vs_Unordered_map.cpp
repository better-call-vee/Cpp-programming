#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'

// Custom hash function to avoid collisions
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(const std::string &str) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = FIXED_RANDOM;
        for(char c : str) {
            hash ^= (hash << 5) + (hash >> 2) + c;
        }
        return splitmix64(hash);
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, L, n, x;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
    vector<int> b(M);
    for(int i = 0; i < M; i++) cin >> b[i];
    cin >> L;
    vector<int> c(L);
    for(int i = 0; i < L; i++) cin >> c[i];
    cin >> n;

    // Use unordered_set instead of unordered_map for efficiency
    unordered_set<int, custom_hash> sums;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < L; j++) {
            sums.insert(b[i] + c[j]);
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> x;
        bool found = false;
        for(int j = 0; j < N; j++) {
            if(sums.find(x - a[j]) != sums.end()) {
                cout << "Yes\n";
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "No\n";
        }
    }

    return 0;
}

/*
Explanation:

1. Using unordered_set:
   - We use unordered_set instead of unordered_map to store the sums of elements
from vectors b and c.
   - unordered_set is more suitable because we only need to check the presence
of a sum, not store any associated value.
   - This reduces redundancy and memory overhead.

2. Memory Efficiency:
   - unordered_set is more memory-efficient as it only stores keys, while
unordered_map stores key-value pairs, even if the values are not needed.

3. Performance Optimization:
   - unordered_set has streamlined operations focused solely on keys, leading to
slightly better performance.
   - Both unordered_set and unordered_map have average O(1) time complexity for
lookups, but unordered_set is more efficient in this context due to reduced
operations.

Conclusion:
   - By switching from unordered_map to unordered_set, we reduce memory usage
and streamline operations.
   - This change improves overall efficiency, helping avoid the Time Limit
Exceeded (TLE) error.
*/
