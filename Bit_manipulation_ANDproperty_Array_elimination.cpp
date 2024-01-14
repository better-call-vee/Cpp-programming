/*
Thinking in Binary (0s and 1s): When you encounter a problem related to bits,
the first step is to shift your thinking from the regular decimal numbers to
binary numbers, which are composed exclusively of 0s and 1s.
This means interpreting the problem's elements (like an array of numbers) in
their binary form. For example, instead of seeing numbers like 5, 7, 8, you
should think of them as 101, 111, 1000 in binary.

Array of Binary Numbers: If the problem involves an array of numbers, consider
this array as a collection of binary numbers. Each element of the array should
be viewed not as a single value but as a sequence of bits (0s and 1s).

Independence of Each Bit: In many bit manipulation problems, the bits of a
number can be treated independently. This means that the operations or
calculations for one bit (like the least significant bit) do not affect or
depend on the other bits (like the most significant bit). This independent
nature allows you to analyze and solve the problem for each bit position
separately.

Bit-by-Bit Analysis: Once you've adopted the mindset of treating each bit
independently, you can then focus on solving the problem for each bit position
across all the numbers in the array. This might involve operations like counting
the number of 1s in a particular bit position across all numbers, or applying
bitwise operations (AND, OR, XOR) on each bit position.
https://codeforces.com/contest/1601/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), cnt(30);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 30; j++) cnt[j] += (1 << j & a[i] ? 1 : 0);
        // or, (a[i] >> j & 1); this directly gives the set bit check.
        for(int k = 1; k <= n; k++) {
            int ok = 1;
            for(int j = 0; j < 30; j++)
                if(cnt[j] % k != 0) {
                    ok = 0;
                    break;
                }
            if(ok) cout << k << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
AND property:
Suppose, we AND two numbers, after that if we subtract both the numbers with
their AND value, the both values will be lessened by the number of set bits of
the AND value. Suppose: 13 AND 7 => 5. 13 = 1101, 7 = 111. 13 - 5(101) = 1000, 7
- 5 = 10.

In this problem, when the count of a bit position is divided by k, we can make
pair of that k and subtract leading to zero(0). thus we check cnt[j] % k is 0 or
not.
*/