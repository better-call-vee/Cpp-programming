/*
Suppose, they ask me to change l to r segment(update). Then, everytime,
we will be needed to update all the leaf nodes of that segment. So, O(nlogn) can
be the complexity, which is even worse than O(n)!!
//https://www.shafaetsplanet.com/?p=1591 => read this

si = segment index, ss = segment start, se = segment end, us = update start, ue
= update end, qs = query start, qe = query end

The concept is almost the same. Here as we have to update a range, if we follow
the brute force method, we may need to visit each and every leaf node!!
Here, as soon as we get ss and se is in the range of the update / the query,
we simply just set the lazy values to that segment node's children so that later
it can be carried on. line(38)
And whenever while the recursion, if the lazy value is not zero, we got to
update that node of segment and doing the same thing we did before(set the
children's propagation). And finally we will set the lazy value of that segment
index to 0 to make it correct as we have already used it. (line 28, 53)
*/
#include <bits/stdc++.h>
using namespace std;
class sextree {
  private:
    int n;
    vector<int> tree, lazy, arr;
    void build(int ss, int se, int si) {
        if(ss == se) {
            tree[si] = arr[ss];
            return;
        }
        int ln = 2 * si, mid = (ss + se) / 2, rn = 2 * si + 1;
        build(ss, mid, ln), build(mid + 1, se, rn);
        tree[si] = tree[ln] + tree[rn];
    }
    void update(int si, int ss, int se, int us, int ue, int diff) {
        int mid = (ss + se) / 2, ln = si * 2, rn = si * 2 + 1;
        if(lazy[si] != 0) {
            tree[si] += (se - ss + 1) * lazy[si]; // adding the changed
            // value to the current node. The number of nodes it has below
            // it * propagated value set before. This is the ending of this
            // particular node's propagation. Now it propagates this to it's
            // children. It's like descendence of kingdom.
            if(ss != se) lazy[ln] += lazy[si], lazy[rn] += lazy[si];
            lazy[si] = 0;
        }
        if(ss > se || ss > ue || se < us) return;
        if(ss >= us && se <= ue) {
            tree[si] += (se - ss + 1) * diff;
            if(ss != se) lazy[ln] += diff, lazy[rn] += diff;
            return;
        }
        // also when the segment index's range is in between the update
        // range, then we simply update the current segment index's value
        // and propagates the diff to its children. As its calculation is
        // done here directly, we don't even need to consider about
        // further propagation down the tree at this moment. Future accesses
        // to the children will handle the propagation as needed, thanks to
        // the lazy values we've set.
        update(ln, ss, mid, us, ue, diff);
        update(rn, mid + 1, se, us, ue, diff);
        tree[si] = tree[ln] + tree[rn];
    }
    int query(int ss, int se, int qs, int qe, int si) {
        int mid = (ss + se) / 2, ln = 2 * si, rn = 2 * si + 1;
        if(lazy[si] != 0) {
            tree[si] += (se - ss + 1) * lazy[si];
            if(ss != se) lazy[ln] += lazy[si], lazy[rn] += lazy[si];
            lazy[si] = 0;
        }
        if(ss > se || ss > qe || se < qs) return 0;
        if(ss >= qs && se <= qe) return tree[si];
        return query(ss, mid, qs, qe, ln) + query(mid + 1, se, qs, qe, rn);
    }
  public:
    sextree(vector<int> &inp) {
        n = inp.size();
        arr = inp;
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
        build(1, n, 1);
    }
    void up(int us, int ue, int diff) { update(1, 1, n, us, ue, diff); }
    int qry(int qs, int qe) { return query(1, n, qs, qe, 1); }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sextree st(arr);
    // Example usage
    cout << "Sum of values in range [2, 4] before updating: " << st.qry(2, 4)
         << endl;
    st.up(1, 6, 10); // Update range [1, 6] by adding 10
    cout << "Sum of values in range [2, 4]: " << st.qry(2, 4) << endl;
    st.up(4, 9, 20); // Update range [4, 9] by adding 20
    cout << "Sum of values in range [5, 6]: " << st.qry(5, 6) << endl;

    return 0;
}
