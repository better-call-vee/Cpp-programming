#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    double sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    cout << fixed << setprecision(6) << (1LL * 4.0 * sum / n);
    return 0;
}

/*
Sum of all possible outcomes / number of all possible outcomes = Expected value

in this very problem, we need to print an expected sum of 4 values from the
given elements. And the expected value can be got from 4*all values' sum / n;
*/