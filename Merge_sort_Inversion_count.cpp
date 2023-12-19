#include <bits/stdc++.h>
using namespace std;

// don't forget to use long long in some problems
// Modified merge function that also counts inversions.
pair<vector<int>, int> merge(vector<int> &l, vector<int> &r) {
    int n = l.size(), m = r.size();
    vector<int> ans;
    int i = 0, j = 0, inversions = 0;

    while(i < n && j < m) {
        if(l[i] <= r[j]) {
            ans.push_back(l[i++]);
        } else {
            ans.push_back(r[j++]);
            inversions += n - i; // Count inversions: remaining elements in 'l'
                                 // will be inversions.
            // we then go right. and thus all the left elements from the current
            // one have inversion with that right element
        }
    }

    while(i < n) ans.push_back(l[i++]);
    while(j < m) ans.push_back(r[j++]);

    return {
        ans,
        inversions}; // Return both the merged array and the inversion count.
}

vector<int> a; // Global array to hold the input.

// Modified merge_sort function to return both the sorted array and inversion
// count.
pair<vector<int>, int> merge_sort(int l, int r) {
    if(l == r) return {{a[l]}, 0}; // Single element array has no inversions.

    int mid = (l + r) >> 1;
    auto [left, left_inv] =
        merge_sort(l, mid); // Sort and count inversions in left half.
    auto [right, right_inv] =
        merge_sort(mid + 1, r); // Sort and count inversions in right half.

    auto [merged, merge_inv] =
        merge(left, right); // Merge and count inversions during merge.
    return {merged, left_inv + right_inv +
                        merge_inv}; // Combine inversions from all steps.
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto [sorted_array, inversions] =
        merge_sort(0, n - 1); // Perform merge sort and count inversions.

    cout << "Sorted array: ";
    for(int x : sorted_array) cout << x << ' ';
    cout << "\nInversions count: " << inversions
         << '\n'; // Print the number of inversions.

    return 0;
}

/*
Another clean code:


#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays and count inversions
int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left;    // Index for left subarray
    j = mid;     // Index for right subarray
    k = left;    // Index for resultant merged subarray

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Inversion will occur.
            inv_count += (mid - i);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge sort function
int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts
        mid = (right + left) / 2;

        // Count inversions in left and right parts
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge two parts and count inversions during merge
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Utility function to count inversions
int countInversions(vector<int> arr) {
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}

// Main function
int main() {
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << "Number of inversions are: " << countInversions(arr) << endl;
    return 0;
}

*/

/*
Function merge():

Purpose: Merges two sorted subarrays and counts the number of inversions.

Parameters: The main array arr, a temporary array temp, and the indices left,
mid, right marking the bounds of the subarrays.

Inversion Count Logic: When an element in the right subarray is smaller than an
element in the left subarray, it means all elements from the current position to
the end of the left subarray will form an inversion with this element. The
inversion count is incremented by the number of remaining elements in the left
subarray. 



Function mergeSort():
Purpose: Recursively sorts the array and counts inversions.

Inversion Counting: Each recursive call returns the count of inversions in the
left half, the right half, and those counted during the merge process. These are
summed up to get the total inversion count for the subarray. 


Function countInversions():
Purpose: Serves as a wrapper for ease of use. It initializes the process and
returns the total inversion count for the entire array. 


Example: Let's consider
a small array: [5, 3, 2, 4, 1]

First Split: [5, 3, 2] and [4, 1]
Further Split and Sort:
[5], [3, 2] ⇒ [3, 2] becomes [2, 3] (1 inversion)
[4], [1] ⇒ [1, 4] (1 inversion)
Merge and Count:
Merge [2, 3] and [5] ⇒ No new inversions.
Merge [1, 4] with the sorted left half ⇒ Several inversions as 1 is smaller than
all elements in the left half. 

Visual Explanation Imagine sorting and merging as organizing books on shelves:
Splitting: You divide the books into smaller groups.
Sorting & Merging: You arrange each small group in order and then start
combining these groups. 
Inversion Counting: Every time a book from a right group
is placed before several books from a left group, it's like finding several
misplacements (inversions).
*/