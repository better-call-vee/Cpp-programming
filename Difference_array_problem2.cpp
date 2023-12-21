/*Problem Statement:
Given an array 'a' of length 'n' and 'q' queries of the form (l, r, x), for each
query, add 'x' to all elements of 'a' from 'l' to 'r' inclusive. Print the final
array after all queries.

Constraints:
1 ≤ n, q ≤ 10^6
1 ≤ l ≤ r ≤ n
−10^9 ≤ x ≤ 10^9
−10^9 ≤ a[i] ≤ 10^9

Solution:
Using a naive approach for the queries would lead to a time complexity of O(nq),
which is too slow. Instead, we can achieve O(n + q) time complexity using a
difference array.

Approach:
1. Initialize a difference array 'd' of length 'n'.
2. For each query, the update will affect only two elements of 'd': d[l] and d[r
+ 1].
3. Process all queries in O(q) time.
4. Reconstruct the original array from the difference array in O(n) time.

By following these steps, we can efficiently handle the queries and obtain the
final array.*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
long long a[N], d[N];

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        d[i] = a[i] - a[i - 1];
    }

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + d[i];
    }

    for(int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}