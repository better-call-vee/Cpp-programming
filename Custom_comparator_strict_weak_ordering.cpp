/*
In C++, the comparator function must follow the strict weak ordering rule. It
means that the comparator function must return false for equal elements. If the
comparator returns true for equal elements, the sort function will not work
properly.

For example, the following comparator function does not follow the strict weak
ordering rule: bool cmp(int a, int b) { return a <= b;}
This comparator function returns true for equal elements. So, the sort function
will not work properly with this comparator. This might give you a wrong answer
or even a runtime error.

Sorting algorithms rely on the comparator to consistently and accurately
determine the order of elements. If the comparator violates this rule, as in the
case of returning true for equal elements (a <= b), it disrupts the algorithm's
ability to correctly judge and arrange elements. This can lead to issues like
infinite loops, undefined behavior, or incorrect sorting results.

Irreflexivity is violated: For any a, cmp(a, a) returns true (since a <= a is
true), which implies that an element is considered less than itself.
Asymmetry is violated: If a and b are equal, cmp(a, b) and cmp(b, a) would both return
true, which contradicts the requirement that if a is less than b, then b cannot
be less than a.
*/

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1, [](string a, string b) {
        return a + b < b + a; // wrong when you'll write a + b <= b + a;
    });
    for(int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}