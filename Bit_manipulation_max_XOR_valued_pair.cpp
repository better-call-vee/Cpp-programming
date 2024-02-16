#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll l, r, x, y;
    cin >> l >> r;
    ll frst_diff = (l ^ r);
    frst_diff |= ((1LL << (63 - __builtin_clzll(frst_diff))) - 1);
    cout << frst_diff;
    return 0;
}

/*
We need to output the greatest XOR value of the possible pairs between l and r.
Here l is the lower number and r is the greater number and the first bit they will
differ, will be a set bit for the greater number(r) and unset bit(0) for smaller
number(l).
No matter what, we can't set the matching bits.
so, we need to stop thinking about them

1 1 1 0 1 0 1 0 0 => r
1 1 0 1 0 0 1 0 0 => l
    -
see, here, for l the 3rd bit(from left) is unset and for r, it's set.
it's set that means the later bits , to the right, can be 0(every bit)
and for l, it can be set to 1. This will also ensure they are in range of
l and r because, the first varying bit is explored. And the number in 
between them will be there no matter what we change the bits.
*/