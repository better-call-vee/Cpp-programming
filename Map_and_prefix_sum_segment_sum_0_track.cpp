#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
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
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        unordered_map<int, int, custom_hash> tr;
        int n, p = 0, cnt = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        tr[0] = 1;
        for(int i = 0; i < n; i++) {
            p += a[i];
            if(tr[p]) {
                cnt++;
                tr.clear();
                tr[0] = 1;
                p = 0;
            } else
                tr[p]++;
        }
        cout << cnt << nl;
    }
    return 0;
}

// here, we just need to count max number of non overlapping segments having sum
// 0