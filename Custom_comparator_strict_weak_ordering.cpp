/*
In C++, the comparator function must follow the strict weak ordering rule. It means that
the comparator function must return false for equal elements. If the comparator returns
true for equal elements, the sort function will not work properly.

For example, the following comparator function does not follow the strict weak ordering rule:
bool cmp(int a, int b) {
  return a <= b;
}
This comparator function returns true for equal elements. So, the sort function will not work properly
with this comparator. This might give you a wrong answer or even a runtime error.
*/

#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort (s + 1, s + n + 1, [](string a, string b) {
    return a + b < b + a; //wrong when you'll write a + b <= b + a;
  });
  for (int i = 1; i <= n; i++) {
    cout << s[i];
  }
  cout << '\n';
  return 0;
}