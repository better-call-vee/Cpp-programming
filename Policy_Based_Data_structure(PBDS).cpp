// it's like set or multiset, but we can do indexing.
// we can access it with logn time complexity.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    PBDS<int> s;

    s.insert(2);
    s.insert(4);
    s.insert(9);
    s.insert(10);

    for (auto val : s)
        cout << val << " ";

    cout << "\n";

    return 0;
}