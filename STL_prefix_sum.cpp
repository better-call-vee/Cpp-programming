/*
It computes the sum of elements in a given range,
storing each intermediate sum in a new range.and You get a sequence where
each element is the sum of all preceding elements in the input range,
including itself.

Syntax:
partial_sum(InputIterator first, InputIterator last, OutputIterator result);
partial_sum(InputIterator first, InputIterator last, OutputIterator result,
BinaryOperation binary_op);

Parameters:
first, last: Iterators to the start and end of the range.
result: An output iterator for the cumulative sums.
binary_op: Optional. A binary function for custom accumulation (replaces
addition).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> sums(nums.size()), products(nums.size());

    partial_sum(nums.begin(), nums.end(), sums.begin());
    partial_sum(nums.begin(), nums.end(), products.begin(), multiplies<int>());
    // binary_op examples: plus<>(), divides<>(), minus<>()

    for(int sum : sums) cout << sum << " ";
    // Output: 1 3 6 10 15
    cout << "\n";
    for(int product : products) cout << product << " ";
    // Output: 1 2 6 24 120
}
