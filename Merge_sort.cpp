/*
Merge Sort: A Tale of Splitting, Sorting, and Merging

The Grand Picture:
Imagine you're a chef sorting your spices. Merge Sort is like sorting each jar one by one,
and then combining them together in order, to create an organized spice rack.

Divide and Conquer:
Merge Sort is like a wise ruler who divides the land (array) into smaller territories(sub-arrays)
to manage them more efficiently.

The Recursive Dance:
It’s a dance of dividing and conquering. Each step, we split the array into smaller ones,
like a tree branching out. We keep going until each branch has a single leaf (element).

The Magic of Merging:
Two tiny, sorted armies (sub-arrays) line up. The commanders (pointers) compare soldiers (elements). 
The smallest soldier steps forward to form a new, larger, sorted army.

A Symphony of Sorting:
Imagine an orchestra. Each musician (element) finds their right spot, creating a harmonious
melody (sorted array).


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
Each split cuts the array in half - a logarithmic process (like peeling an onion layer by layer).
Merging each level takes linear time - adding up the elements.

Overall: O(n log n) - Efficient like a well-organized assembly line.

Recap with Your Array [5,3,7,1,8,9]:
Imagine splitting [5,3,7,1,8,9] into [5,3,7] and [1,8,9].
They break down further, like a family tree, until everyone is standing alone.
Then, a graceful merge. Like dancers finding their perfect spot on stage.
Result: [1, 3, 5, 7, 8, 9] - a parade of numbers in perfect order.

In Essence:
Merge Sort is a story of breaking things down, sorting the pieces, and then putting them
all back together in a perfect arrangement. It's a dance, a strategy, and an art form, 
all rolled into one.
*/


#include<bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int leftIndex = 0, rightIndex = 0;

    // Merge elements from left and right arrays
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) 
            result.push_back(left[leftIndex++]);
        else 
            result.push_back(right[rightIndex++]);
    }

    // Add remaining elements from left array
    while (leftIndex < left.size()) 
        result.push_back(left[leftIndex++]);

    // Add remaining elements from right array
    while (rightIndex < right.size()) 
        result.push_back(right[rightIndex++]);

    return result;
}

// Function for merge sort
vector<int> merge_sort(vector<int>& a) {
    // Base case: if the array is empty or has one element, it is already sorted
    if (a.size() <= 1) return a;

    // Find the middle index for splitting the array
    int mid = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());

    // Recursively sort both halves
    left = merge_sort(left);
    right = merge_sort(right);

    // Merge the sorted halves
    return merge(left, right);
}

int main() {
    vector<int> a = {5, 3, 7, 1, 8, 9};
    vector<int> sortedArray = merge_sort(a);

    // Print the sorted array
    for (int val : sortedArray) 
        cout << val << " ";

    return 0;
}
