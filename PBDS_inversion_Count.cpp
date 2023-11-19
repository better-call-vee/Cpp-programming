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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        PBDS<int> p;
        ll ans = 0;

        /*
        What is inversion?
        => suppose an array 2 4 5 7 9 1 3 2
        here if we count the number of inversion, we have to keep in mind i<j && a[i]>a[j].
        so, we start from the end, because i<j is the condition, and it's the easiest way to do this.
        we start from 2. as it doesn't have any other elements to it's right, we skip and go on by simply
        inserting it in the pbds.
        next, 3, i<j and 3>2. we count the strictly less than elements of 3 in the pbds. and add it to the
        answer. so ans = 1 now.
        next, 1, i<j but 1 isn't greater than any of the rightest 2 elements of it. so we move on.
        next, 9, i<j and the pbds now has 3 strictly less elements than 9.
        and thus, we go on. the final count will be 14.
        */

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == (n - 1))
                p.insert(a[i]);

            else
            {
                ans += p.order_of_key(a[i]); // counting the strictly less elements than a[i].
                p.insert(a[i]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

//the sorted permutation will have an inversion count of 0.
//if we swap two adjacent elements, suppose a[i] and a[i+1], if a[i+1] is greater than a[i] then 
//the inversion count will be ans+1. else the inversion will be one less.
//descendingly sorted array/ something will have the maximum inversions.



/*
ans += p.size() - p.order_of_key(a[i] + 1);
this is for finding strictly greater elements.

p.order_of_key(a[i]) gives the strictly less elements count
thant a[i]. we add 1 with a[i] to also include equivalent elements
count. then we subtract this from the total size and get the
strictly greater element count
*/