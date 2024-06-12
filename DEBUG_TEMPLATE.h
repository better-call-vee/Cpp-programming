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
