<snippet>
    <content><![CDATA[
#define TANVEE009

#include "D:\CP\DEBUG_TEMPLATE.h"
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 1e18
#define int long long
string nl = "\n";

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef DEBUG_MODE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
#endif

    return 0;
}
]]></content>
    <tabTrigger>comp</tabTrigger>
    <scope>source.c++</scope>
    <description>C++ Competitive Programming Template with pbds</description>
</snippet>



#ifndef DEBUG_TEMPLATE_H
#define DEBUG_TEMPLATE_H
#include <bits/stdc++.h>
using namespace std;
#ifdef TANVEE009
#define debug(x) do { cerr << #x << ": "; _print(x); cerr << endl; } while(0)
#else
#define debug(x)
#endif
template <typename T> void _print(const T &t) { cerr << t; }
template <typename T, typename V> void _print(const pair<T, V> &p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T> void _print(const vector<T> &v) { cerr << "["; for (const auto &e : v) { _print(e); cerr << " "; } cerr << "]"; }
template <typename T> void _print(const set<T> &s) { cerr << "{"; for (const auto &e : s) { _print(e); cerr << " "; } cerr << "}"; }
template <typename T> void _print(const multiset<T> &ms) { cerr << "{"; for (const auto &e : ms) { _print(e); cerr << " "; } cerr << "}"; }
template <typename T> void _print(const unordered_set<T> &us) { cerr << "{"; for (const auto &e : us) { _print(e); cerr << " "; } cerr << "}"; }
template <typename T, typename V> void _print(const map<T, V> &m) { cerr << "{"; for (const auto &p : m) { _print(p.first); cerr << " : "; _print(p.second); cerr << ", "; } cerr << "}"; }
template <typename T, typename V> void _print(const multimap<T, V> &mm) { cerr << "{"; for (const auto &p : mm) { _print(p.first); cerr << " : "; _print(p.second); cerr << ", "; } cerr << "}"; }
template <typename T, typename V, typename H> void _print(const unordered_map<T, V, H> &um) { cerr << "{"; for (const auto &p : um) { _print(p.first); cerr << " : "; _print(p.second); cerr << ", "; } cerr << "}"; }
template <typename T, size_t N> void _print(const T (&arr)[N]) { cerr << "["; for (size_t i = 0; i < N; ++i) { _print(arr[i]); if (i + 1 != N) cerr << ", "; } cerr << "]"; }
template <size_t N> void _print(const bitset<N> &bs) { cerr << "["; for (size_t i = 0; i < N; ++i) { cerr << bs[i]; if (i + 1 != N) cerr << " "; } cerr << "]"; }
template <typename T, typename C, typename Comp> void _print(priority_queue<T, C, Comp> pq) { cerr << "["; while (!pq.empty()) { _print(pq.top()); pq.pop(); cerr << " "; } cerr << "]"; }
template <typename T> void _print(stack<T> st) { vector<T> v; while (!st.empty()) { v.push_back(st.top()); st.pop(); } _print(v); }
template <typename T> void _print(queue<T> q) { vector<T> v; while (!q.empty()) { v.push_back(q.front()); q.pop(); } _print(v); }
template <typename T> void _print(deque<T> dq) { cerr << "["; for (const auto &e : dq) { _print(e); cerr << " "; } cerr << "]"; }
template <size_t I = 0, typename... Args>
typename enable_if<I == sizeof...(Args), void>::type _print_tuple(const tuple<Args...> &) {}
template <size_t I = 0, typename... Args>
typename enable_if<I < sizeof...(Args), void>::type _print_tuple(const tuple<Args...> &t) {
    if (I > 0) cerr << ", ";
    _print(get<I>(t));
    _print_tuple<I + 1, Args...>(t);
}
template <typename... Args> void _print(const tuple<Args...> &t) {
    cerr << "(";
    _print_tuple(t);
    cerr << ")";
}
template <typename... Args> void _print(const vector<tuple<Args...>> &v) {
    cerr << "[";
    for (const auto &e : v) {
        _print(e);
        cerr << " ";
    }
    cerr << "]";
}
#endif // DEBUG_TEMPLATE_H


<snippet>
    <content><![CDATA[
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ${1:}
    return 0;
}
]]></content>
     <tabTrigger>cppfast</tabTrigger>
</snippet>



struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }

  size_t operator()(const std::string& str) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      uint64_t hash = FIXED_RANDOM;
      for (char c : str) {
          hash ^= (hash << 5) + (hash >> 2) + c;
      }
      return splitmix64(hash);
  }
};

unordered_map<, , custom_hash> ;


{
    "cmd": ["g++", "-Wall", "${file}", "-o", "${file_base_name}"],
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c++, source.cxx, source.cpp",
    "variants": [
        {
            "name": "Run",
            "shell_cmd": "${file_base_name} < input.txt > output.txt",
            "working_dir": "${file_path}"
        }
    ],
    "shell": true
}
