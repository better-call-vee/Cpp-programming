#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], st[N * 4]; // ***
void build(int node, int l, int r) {
    if(l == r) {
        st[node] = a[l];
        return;
    }
    int lch = 2 * node, rch = 2 * node + 1, mid = (l + r) / 2;
    build(lch, l, mid);
    build(rch, mid + 1, r);
    st[node] = st[lch] + st[rch];
    // st[node] = max(st[lch], st[rch]);  if they ask the max of a segment.
    /*
   We are using a recursive method(merge sort and divide & conquer).
   It's totally a brute force and we are using an array to store the
   tree. We are starting from (1 to n) range sum storing. Everytime we
   are dividing the range into two parts.
   5th line: there can be at most 4n nodes. So, N * 4  (***)
   8th line: Base case, whenever we will reach the base case(l == r), means
             we have reached the leaf node. And here we need to set the node's
             value directly as the array's value lcd = left child, rch = right
             child.
   14th line: Current node is definitely the addition of it's two
   children range.
    */
}
int query(int node, int l_range, int r_range, int l, int r) {
    if(l_range > r or r_range < l) return 0;
    // return INT_MIN; if they ask for the minimum value of a segment and the
    // elements can be minimum. OR, we can use a flag for AND or other
    // operation. like, we will return something weird likely values and then
    // check in the end that if the return is that or not. If yes, then we will
    // not merge them.

    if(l_range >= l and r_range <= r) return st[node];
    int mid = (l_range + r_range) / 2, lch = 2 * node, rch = 2 * node + 1;
    return query(lch, l_range, mid, l, r) + query(rch, mid + 1, r_range, l, r);
    // also here, we can output max / min of this two portions if they ask for
    /*
    31st line: means the range is completely out of the nodes range
    38th line: great observation needed. it means the node is partially or
               totally in the range. Thus we add the sum to it.
    39th line: We divide this into two parts and go to left and right. and again
    divide and conquer.
    */
}
void update(int node, int l_range, int r_range, int i, int x) {
    if(l_range > i or r_range < i) return;
    if(l_range == i and r_range == i) {
        st[node] = x;
        return;
    }
    int lch = 2 * node, rch = 2 * node + 1, mid = (l_range + r_range) / 2;
    update(lch, l_range, mid, i, x);
    update(rch, mid + 1, r_range, i, x);
    st[node] = st[lch] + st[rch];
    // also here, st[node] = max/min(st[lch], st[rch]);
    /*
       almost the same thing. But here, we only need to update that single
       index and also all the nodes containing that single index. So, we go on
       with the divide and conquer and in the end: line 59 adds the left and
       right sides' addition to the current node because we need to update all
       the segments containing that particular index. Also, line 52: we only
       searching for that only one index at first, so go on in quest of that
       leaf node which contain that particular index, and then we track back
       updating all the nodes containing that particular index.
    */
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = 5;
    for(int i = 1; i <= n; i++) a[i] = i;
    build(1, 1, n);
    cout << st[1] << "\n"; // will print the whole array's sum as 1 to n's sum
    // is stored in the first node.
    cout << query(1, 1, n, 2, 4)
         << "\n"; // taking query from 2 to 4th indices' sum
    update(1, 1, n, 3, 10);
    cout << query(1, 1, n, 2, 4) << "\n"; // after updating..
    return 0;
}

// For every operation like gcd, XOR, OR, AND etc, this can be used as well.
// because it doesn't matter in which sequence we are doing these. So, they can
// be done.

// BUT, getting distinct values in a segment is not possible with this.