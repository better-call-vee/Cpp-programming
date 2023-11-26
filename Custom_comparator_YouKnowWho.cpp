#include<bits/stdc++.h>
using namespace std;

// Custom comparator as a function
bool cmp(pair<int, int> a, pair<int, int> b) {
  // Sort by first element in descending order
  // If first elements are equal, sort by second element in ascending order
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}

int main() {
  vector<pair<int, int>> v = {{1, 2}, {2, 1}, {2, 3}, {1, 1}, {3, 2}};
  sort(v.begin(), v.end(), cmp);
  for (auto p : v) {
    cout << p.first << ' ' << p.second << '\n';
  }
  cout << '\n';
  // Custom comparator as a lambda expression
  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { // no capture method is better as 
    // we dont wanna change anything outside
    // Sort by second element in descending order
    // If second elements are equal, sort by first element in ascending order
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
  });
  for (auto p : v) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}