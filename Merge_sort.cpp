/*
Merge Sort: A Tale of Splitting, Sorting, and Merging

The Grand Picture:
Imagine you're a chef sorting your spices. Merge Sort is like sorting each jar
one by one, and then combining them together in order, to create an organized
spice rack.

Divide and Conquer:
Merge Sort is like a wise ruler who divides the land (array) into smaller
territories(sub-arrays) to manage them more efficiently.

The Recursive Dance:
It’s a dance of dividing and conquering. Each step, we split the array into
smaller ones, like a tree branching out. We keep going until each branch has a
single leaf (element).

The Magic of Merging:
Two tiny, sorted armies (sub-arrays) line up. The commanders (pointers) compare
soldiers (elements). The smallest soldier steps forward to form a new, larger,
sorted army.

A Symphony of Sorting:
Imagine an orchestra. Each musician (element) finds their right spot, creating a
harmonious melody (sorted array).


Visual Journey Through Merge Sort:
The Initial Array:
Picture an array: [5, 3, 2, 7, 1]
It's like a mixed deck of cards.

Splitting Phase:
First Split: [5, 3] and [2, 7, 1]
Like dividing a deck of cards into two smaller piles.

Further Splits: [5], [3], [2], [7], [1]
Each card is now separate, like leaves fallen from a tree.

Sorting and Merging Phase:
Merge [5] and [3] into [3, 5] - the first sorted pair.
Merge [7] and [1] into [1, 7].
Now, [2] joins [1, 7] to become [1, 2, 7].
It's like dancers finding their partners and forming groups.

The Final Merge:
The grand finale: [3, 5] and [1, 2, 7] merge.
A careful dance: Compare, select, and place.
Outcome: [1, 2, 3, 5, 7] - a beautifully sorted array.

Time Complexity :-
Each split cuts the array in half - a logarithmic process (like peeling an onion
layer by layer). Merging each level takes linear time - adding up the elements.

Overall: O(n log n) - Efficient like a well-organized assembly line.

Recap with Your Array [5,3,7,1,8,9]:
Imagine splitting [5,3,7,1,8,9] into [5,3,7] and [1,8,9].
They break down further, like a family tree, until everyone is standing alone.
Then, a graceful merge. Like dancers finding their perfect spot on stage.
Result: [1, 3, 5, 7, 8, 9] - a parade of numbers in perfect order.

In Essence:
Merge Sort is a story of breaking things down, sorting the pieces, and then
putting them all back together in a perfect arrangement. It's a dance, a
strategy, and an art form, all rolled into one.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays into one sorted array.
vector<int> merge(vector<int> &l, vector<int> &r) {
    int n = l.size(), m = r.size(); // Sizes of the left and right arrays.
    vector<int> ans;                // Vector to store the merged result.
    int i = 0, j = 0; // Pointers for traversing the left and right arrays.

    // Merge elements from the left and right arrays in sorted order.
    while(i < n && j < m) {
        if(l[i] < r[j])
            ans.push_back(l[i++]); // If left element is smaller, add it to ans.
        else
            ans.push_back(r[j++]); // Otherwise, add the right element.
    }

    // Add remaining elements from left array, if any.
    while(i < n) ans.push_back(l[i++]);

    // Add remaining elements from right array, if any.
    while(j < m) ans.push_back(r[j++]);

    return ans; // Return the merged sorted array.
}

vector<int> a; // Global array to hold the input.

// Recursive function to perform merge sort.
vector<int> merge_sort(int l, int r) {
    if(l == r) return {a[l]}; // Base case: single element is already sorted.

    int mid = (l + r) >> 1; // Find the middle index for splitting.
    vector<int> left = merge_sort(l, mid); // Recursively sort the left half.
    vector<int> right = merge_sort(mid + 1, r); // Recursively sort the right half.

    return merge(left, right); // Merge the sorted halves and return.
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;    // Read the number of elements.
    a.resize(n); // Resize the global array to hold n elements.
    for(int i = 0; i < n; i++) cin >> a[i]; // Read elements into the array.

    vector<int> ans = merge_sort(0, n - 1); // Perform merge sort on the array.

    // Print the sorted array.
    for(int i = 0; i < n; i++) 
        cout << ans[i] << ' ';

    return 0;
}

/*
                                [5, 3, 7, 1, 8, 9]
                                      /       \
                             [5, 3, 7]         [1, 8, 9]
                              /      \            /    \
                          [5, 3]    [7]        [1, 8]   [9]
                          /   \      |          /  \     |
                        [5]  [3]    [7]      [1]   [8]  [9]
                         \    /      |          \  /     |
                         [3, 5]     [7]        [1, 8]   [9]
                             \      /            \      /
                           [3, 5, 7]            [1, 8, 9]
                                 \                /
                                 [1, 3, 5, 7, 8, 9]

*/