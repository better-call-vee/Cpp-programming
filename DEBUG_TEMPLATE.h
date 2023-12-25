#ifndef DEBUG_TEMPLATE_H
#define DEBUG_TEMPLATE_H

#include <bits/stdc++.h>
using namespace std;

#ifdef TANVEE009
#define debug(x)                                                               \
    do {                                                                       \
        cerr << #x << ": ";                                                    \
        _print(x);                                                             \
        cerr << endl;                                                          \
    } while(0)
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(float t) { cerr << t; }

// Add this function to the debug template to handle priority_queue types.
template <typename T> void _print(const priority_queue<T> &pq) {
    priority_queue<T> temp = pq; // Copy the pq to a temporary variable as we
                                 // will need to pop the elements
    cerr << "[ ";
    while(!temp.empty()) {
        _print(temp.top()); // Print the top element
        temp.pop();         // Remove the top element to move to the next
        cerr << " ";
    }
    cerr << "]";
}

template <typename T, typename Container, typename Compare>
void _print(const priority_queue<T, Container, Compare> &pq) {
    priority_queue<T, Container, Compare> temp = pq;
    cerr << "[ ";
    while(!temp.empty()) {
        _print(temp.top());
        temp.pop();
        cerr << " ";
    }
    cerr << "]";
}

// Place pair's print definition here
template <typename T, typename V> void _print(const pair<T, V> &p) {
    cerr << "{ ";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << " }";
}

// Now all other container types can use it
template <typename T, size_t N> void _print(const T (&arr)[N]) {
    cerr << "[ ";
    for(size_t i = 0; i < N; ++i) {
        _print(arr[i]);
        cerr << " ";
    }
    cerr << "]";
}

template <size_t N> void _print(const std::array<int, N> &arr) {
    cerr << "[ ";
    for(const int &element : arr) {
        _print(element);
        cerr << " ";
    }
    cerr << "]";
}

template <typename T> void _print(const vector<T> &v) {
    cerr << "[ ";
    for(const T &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <typename T, typename V> void _print(const vector<pair<T, V>> &v) {
    cerr << "[ ";
    for(const auto &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <typename T> void _print(const set<T> &s) {
    cerr << "{ ";
    for(const T &x : s) {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

template <typename T, typename V> void _print(const set<pair<T, V>> &s) {
    cerr << "{ ";
    for(const auto &x : s) {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

template <typename T, typename V> void _print(const map<T, V> &m) {
    cerr << "{ ";
    for(const auto &pair : m) {
        _print(pair.first);
        cerr << " : ";
        _print(pair.second);
        cerr << ", ";
    }
    cerr << "}";
}

template <typename T, typename V, typename W>
void _print(const map<pair<T, V>, W> &m) {
    cerr << "{ ";
    for(const auto &pair : m) {
        _print(pair);
        cerr << " ";
    }
    cerr << "}";
}

template <typename T, typename V, typename W>
void _print(const map<T, pair<V, W>> &m) {
    cerr << "{ ";
    for(const auto &pair : m) {
        _print(pair);
        cerr << " ";
    }
    cerr << "}";
}

template <typename T> void _print(const multiset<T> &ms) {
    cerr << "{ ";
    for(const T &x : ms) {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

template <typename T> void _print(const queue<T> &q) {
    queue<T> temp = q;
    cerr << "[ ";
    while(!temp.empty()) {
        _print(temp.front());
        temp.pop();
        cerr << " ";
    }
    cerr << "]";
}

template <typename T> void _print(const stack<T> &st) {
    stack<T> temp = st;
    vector<T> vec;
    while(!temp.empty()) {
        vec.push_back(temp.top());
        temp.pop();
    }
    cerr << "[ ";
    for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
        _print(*it);
        cerr << " ";
    }
    cerr << "]";
}

template <typename T> void _print(const deque<T> &dq) {
    cerr << "[ ";
    for(const T &x : dq) {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

#endif // DEBUG_TEMPLATE_H
