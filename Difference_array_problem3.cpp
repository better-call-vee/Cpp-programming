/*
The task is to manage n lists, initially empty, and process q queries. Each
query instructs the program to add a certain element x to all lists within a
specified range [l, r]. After processing all queries, the program should output
the count of unique elements in each list.

Problem Statement:
We have n lists, numbered from 1 to n.
Each list starts as empty.
There are q queries. Each query is of the form (l, r, x).
For each query, we append x to all lists from l to r (inclusive).
After processing all queries, the task is to print the number of unique elements
in each list.
Constraints:
1 ≤ n, q ≤ 10^6
1 ≤ l ≤ r ≤ n
1 ≤ x ≤ 10^9

Solution Approach:
The code optimizes the process of adding elements to the lists. Instead of
directly inserting x into each list from l to r, it uses a more efficient
approach.
For each query (l, r, x), x is added to the lth list and a note is made to
remove x from the r + 1th list. This implies that x should be considered part of
all lists from l to r. The actual insertion and deletion from the lists are not
performed immediately. Instead, the code maintains two vectors, add and remove,
that record these operations. The map<int> mp is used to keep track of the
current elements in each list as the code iterates from 1 to n. When reaching a
list, the code applies all the pending additions and removals for that list. The
unique elements in each list at any point are represented by the keys in mp.
Their count gives the number of unique elements in the current list.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<int> add[N], remove[N];

int main() {
    int n, q;
    cin >> n >> q;
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        add[l].push_back(x);
        remove[r + 1].push_back(x);
    }

    map<int> mp;
    for(int i = 1; i <= n; ++i) {
        for(int x : add[i]) {
            mp[x]++;
        }
        for(int x : remove[i]) {
            mp[x]--;
            if(mp[x] == 0) {
                mp.erase(x);
            }
        }
        cout << mp.size() << endl;
    }
}

/*
Processing Each Query
add[l].push_back(x);: For the current query, this line adds x to the vector
add[l]. It implies that x should be added to all lists starting from l.

remove[r+ 1].push_back(x);: This line schedules the removal of x from all lists
starting from r + 1. This effectively limits the addition of x to lists from l
to r.


Iterating Through Lists
map<int> mp;: A map mp is used to keep track of the current unique elements. It
maps each element to its count.
for (int i = 1; i <= n; ++i) { ... }: This loop iterates through each list.


Applying Additions and Removals
for (int x : add[i]) { mp[x]++; }: For the ith list, this loop adds each element
from add[i] to the map mp, incrementing the count of the element.

for (int x :remove[i]) { ... }: This loop handles the removals. It decrements
the count of each element in remove[i] from mp. If the count becomes zero, it
means the element is no longer present in the current list, so it's removed from
mp.

Output
cout << mp.size() << endl;: After processing additions and removals for each
list, the size of mp is printed. mp.size() gives the count of unique elements in
the current list. Summary of the Approach The code avoids directly adding or
removing elements from each list for each query, which would be inefficient.
Instead, it uses the add and remove vectors to track what needs to be added or
removed from each list. As it iterates through each list, it applies these
additions and removals, keeping track of the current set of unique elements
using a map. This approach significantly reduces the complexity, especially when
dealing with a large number of lists and queries.
*/