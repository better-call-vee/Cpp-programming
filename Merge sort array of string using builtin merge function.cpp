#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool string_compare(const string& a, const string& b) {
    return a < b;
    //this boolean function return the lexicographically shorter string.
}

void merge_sort(string arr[], int size) {
    if (size > 1) {
        int mid = size / 2;
        merge_sort(arr, mid);
        merge_sort(arr + mid, size - mid);
        inplace_merge(arr, arr + mid, arr + size, string_compare);
        //here, if we do this for ordinary array, we don't need the string_compare
        //parameter
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    string arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge_sort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//The inplace_merge function is a C++ Standard Library algorithm that performs an
//in-place merge of two sorted ranges in a container. It is similar to the merge
//function, but it does not allocate a temporary buffer to hold the merged ranges.
//The function takes three bidirectional iterators that define two sorted ranges:
//[first, middle) and [middle, last). The two ranges must be sorted in ascending
//order.
//
//The inplace_merge function merges the two ranges in place, so that the resulting
//range [first, last) is also sorted in ascending order. The function preserves
//the relative order of elements that are equivalent.
