// https://atcoder.jp/contests/abc194/tasks/abc194_e?lang=en
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1.5e6 + 1;
struct helper {
    set<int> numbers;
    map<int, int> cnt;
    helper() {
        for(int i = 0; i < N; i++) numbers.insert(i);
    }
    void add(int x) {
        cnt[x]++;
        if(cnt[x] == 1) numbers.erase(x);
    }
    int mex() { return *(numbers.begin()); }
    void move(int x) {
        cnt[x]--;
        if(cnt[x] == 0) numbers.insert(x);
    }
} help;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), meX;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        help.add(a[i]);
        if(i >= m - 1) {
            meX.push_back(help.mex());
            help.move(a[i - m + 1]);
        }
    }
    cout << *min_element(meX.begin(), meX.end());
    return 0;
}