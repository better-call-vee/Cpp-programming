#include <bits/stdc++.h>
using namespace std;

unordered_map<int, long long> memo;

long long trib(int n)
{
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    if (memo.count(n))
        return memo[n];
    /*
    it actually checks whether memo.count(n) returns a non-zero value, which means that there is
    an entry in the memo map with key equal to n.
    Since unordered_map returns zero when the key is not found in the map, the if condition is
    essentially checking whether memo contains an entry with key equal to n. If it does, the
    function returns the cached result. If it doesn't, the function computes the result recursively
    and stores it in the memo map for future use.
    */
    long long ans = trib(n - 1) + trib(n - 2) + trib(n - 3);
    memo[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << trib(n) << endl;
    return 0;
}

/*
unordered_map is a standard C++ container that provides a hash-based associative array. In this code,
memo is an unordered map with integer keys and long long values, used to store previously computed
Tribonacci numbers. When trib(n) is called, the function first checks if memo already contains the
result for n, and if so, it returns the cached value. If not, it computes the Tribonacci number for
n recursively and caches the result in memo for future use.
A cached result means that the function has already computed the result for a given input value, and
it has stored the result in the memo map. This way, when the function is called again with the same
input value, it can retrieve the result from the map instead of computing it again, which can save
time and resources.
*/