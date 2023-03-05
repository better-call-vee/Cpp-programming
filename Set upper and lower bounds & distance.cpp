/**
std::lower_bound and std::upper_bound are two functions in C++ that are used to
search for elements in a sorted range of values. Both of these functions take two
iterators as arguments: a beginning iterator and an ending iterator. They also
take a value to search for within that range.

ANALOGIES:
Imagine you are a teacher and you have a list of students' grades that are sorted
in ascending order. You want to find the first student who got a grade of 80 or
higher.

std::lower_bound: You start looking through the list of grades from the beginning
and compare each grade to the value you're looking for (80). When you find the
first grade that is greater than or equal to 80, you stop and return the iterator
pointing to that grade. This is similar to std::lower_bound, which returns the
iterator pointing to the first element in the range that is greater than or equal
to the search value.

std::upper_bound: Alternatively, you could also start looking through the list of
grades from the beginning, but instead of stopping when you find the first grade
that is greater than or equal to 80, you keep looking until you find the first
grade that is strictly greater than 80. This is similar to std::upper_bound,
which returns the iterator pointing to the first element in the range that is
strictly greater than the search value.
"strictly greater than" means "greater than and not equal to"
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    std::vector<int> v = {1, 3, 4, 4, 7, 8, 9};
    int x = 4;

    // Find the lower bound of x
    auto it1 = std::lower_bound(v.begin(), v.end(), x);
    std::cout << "Lower bound of " << x << " is at index " << std::distance(v.begin(), it1) << std::endl;

    // Find the upper bound of x
    auto it2 = std::upper_bound(v.begin(), v.end(), x);
    std::cout << "Upper bound of " << x << " is at index " << std::distance(v.begin(), it2) << std::endl;

    std::set<int> s = {1, 3, 5, 7, 9};

    // Find the lower bound of 4
    auto it = s.lower_bound(4);
    std::cout << "Lower bound of 4 in set: " << *it << std::endl;
    return 0;
}
