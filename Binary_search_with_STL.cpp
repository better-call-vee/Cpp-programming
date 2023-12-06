/*
We can use some STL to do the binary search automatically which is really cool.
ranges::partition_point and ranges::iota_view are there to rescue.

here's a code for example:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

        auto range =
            ranges::iota_view(0, int(1e9)); // it takes the range, it's like a
        //view, needed for parameter of partition_point, typecasting is necessary(int or, ll) for this.
        int k = *ranges::partition_point(range, [&](int mid) { //here, lambda function returns true or false
            int start = 0, end = 0;
            for(int i = 0; i < n; i++) {
                start -= mid, end += mid;
                start = max(start, l[i]), end = min(end, r[i]);
                if(start > end) return true;
            }
            return false;
        });
        //if lambda function returns true, the partition will go left = mid + 1(this way, means greater way);
        //else, it goes right = mid - 1;
        cout << k << "\n";
    }

    return 0;
}

/*

*/
