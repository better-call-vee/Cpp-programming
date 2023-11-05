/*
A tuple is another container template that allows you to store a fixed-size
collection of elements of different data types. Unlike pairs, which hold two
elements, tuples can hold multiple elements of different types, making them more
versatile when working with related data that requires more than two values to
be combined as a single entity.

Declaration:
tuple<data_type1, data_type2, ..., data_typeN> tuple_name;
Example:
tuple<int, double, char> t1;

Use make_tuple to initialize a tuple:
tuple<int, double, char> t1 = make_tuple(1, 2.5, 'a');

Use get to access the elements of a tuple:
cout << get<0>(t1) << ' ' << get<1>(t1) << ' ' << get<2>(t1) << '\n';

You can also use tie to access the elements of a tuple:
int x; double y; char z; tie(x, y, z) = t1;

Use structured binding to access the elements of a tuple:
auto [first_element, second_element, third_element] = t1;
 (C++17 or above)

You can also have an array of tuples, tuples of tuples, tuples of pairs, etc.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    tuple<int, double, char> t1;

    // Initialization using make_tuple
    tuple<int, double, char> t2 = make_tuple(42, 3.14, 'A');

    // Accessing elements
    cout << "get<0>(t2): " << get<0>(t2) << ", get<1>(t2): " << get<1>(t2)
         << ", get<2>(t2): " << get<2>(t2) << '\n';

    // Using structured binding (C++17 or above)
    t1 = make_tuple(10, 2.718, 'X');
    auto [first_element, second_element, third_element] = t1;
    cout << "get<0>(t1): " << first_element
         << ", get<1>(t1): " << second_element
         << ", get<2>(t1): " << third_element << '\n';

    // Using tie to access the elements of a tuple
    int x;
    double y;
    char z;
    tie(x, y, z) = t2;
    cout << "x: " << x << ", y: " << y << ", z: " << z << '\n';

    // tuples of pairs
    tuple<pair<int, int>, int, tuple<int, int>> t3 =
        make_tuple(make_pair(0, 1), 2, make_tuple(3, 4));
    cout << get<0>(t3).first << ' ' << get<0>(t3).second << ' ' << get<1>(t3)
         << ' ' << get<0>(get<2>(t3)) << ' ' << get<1>(get<2>(t3)) << '\n';
    return 0;
}