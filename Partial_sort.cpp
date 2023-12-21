#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {4, 1, 7, 3, 8, 5};
    std::partial_sort(v.begin(), v.begin() + 3, v.end());

    // Output the sorted part
    for(int i = 0; i < 3; ++i) {
        std::cout << v[i] << " ";
    }
    // Output: 1 3 4
}

/*
Concept of Partial Sort
Partial Sort: Unlike a full sort that orders an entire range, a partial sort
reorders a range so that it is divided into two parts:
the smallest n elements are sorted and placed in the first part of the range;
the remaining elements are left in an unspecified order in the second part.

Syntax in C++:
partial_sort(begin, middle, end); where begin is the iterator to the start
of the range, middle is the iterator to the end of the sorted part, and end is
the iterator to the end of the range.

How It Works Example: If you have an array[4, 1, 7, 3, 8, 5] and you call
partial_sort with middle pointing to the third element, the result might be [1,
3, 4, 8, 7, 5]. The first three elements are sorted, but the order of the last
three is unspecified. Efficiency: It's more efficient than a full sort when you
only need the first n smallest elements sorted, especially for large datasets.
*/