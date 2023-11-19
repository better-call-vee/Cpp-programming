// it's like set or multiset, but we can do indexing.
// we can access it with logn time complexity.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// here, after null_type, if we write greater instead of less, then we can make it descendingly sorted.

// if we write less_equal/greater_equal, then it will work like a multiset(accepting duplicate values),
// but it's not safe.find, erase, lower bound, upper bound don't work correctly.

// but there's a solution for this.
/*
we don't need to write less_equal/ greater_equal.
except, we have to insert the values like a pair.

pbds<pair<int, int>>s;
s.insert({2, 1});
s.insert({2, 2});
s.insert({4, 1});
s.insert({9, 1});
s.insert({2, 3});
s.insert({7, 1});
s.insert({1, 1});
s.insert({7, 2});

the output will be : 1 2 2 2 4 7 7 9
and all the other functions will work accordingly.
*/
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
    s.insert(3);
    s.insert(3);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    s.insert(13);

    for (auto val : s)
        cout << val << " ";

    cout << "\n";

    cout << "3rd index has value: " << *s.find_by_order(3) << "\n"; // accessing 3rd index.
    // if we wanted to do this with set, we had to do this with O(n)

    cout << "Number of strictly less elements than 9: " << s.order_of_key(9) << "\n"; // we can also
    // do it by O(logn) time complexity.
    // and by this, we can also get the number of strictly greater elements.
    ll less = s.order_of_key(9);
    cout << "Number of strictly greater elements than 9: " << s.size() - less << "\n";
    // it will give wrong output because there are duplis in the inserts.

 // Adding a unique identifier to each element in a Policy-Based Data Structure (PBDS) when
 // using pairs is essential to handle duplicates effectively. The unique identifier 
 // distinguishes elements with the same value, ensuring each pair in the PBDS is distinct. 
    PBDS<pair<int, int>> s2;
    s2.insert({2, 1});
    s2.insert({2, 2});
    s2.insert({4, 1});
    s2.insert({9, 1});
    s2.insert({2, 3});
    s2.insert({7, 1});
    s2.insert({1, 1});
    s2.insert({7, 2});

    for (auto &val : s2)
        cout << val.first << " ";

    cout << "\nNumber of strictly less elements than 7: " << s2.order_of_key({7, 0}) << "\n";
    // cout << "Number of strictly greater elements than 7: " << s2.size() - s2.order_of_key({7, 0} << "\n";
    // we have to handle it with frequency
    return 0;
}