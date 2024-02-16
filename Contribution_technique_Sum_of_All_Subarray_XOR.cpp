// SUM OF ALL SUBARRAY XOR:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), prefix_xor(n + 1, 0);
        vector<vector<int>> cnt(30, vector<int>(2, 0));
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
        ll sum = 0;
        for(int i = 0; i < 30; i++) cnt[i][0]++;
        for(int i = 1; i <= n; i++) {
            for(int k = 0; k < 30; k++) {
                int bit = (prefix_xor[i] >> k & 1);
                sum += 1LL * cnt[k][bit ^ 1] * (1 << k);
            }
            for(int k = 0; k < 30; k++) {
                int bit = (prefix_xor[i] >> k & 1);
                cnt[k][bit]++;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
The XOR operation has two key properties that are crucial for this problem:

XOR of a Number with Itself is Zero:
A⊕A=0. This means if a number appears an even number of times in a series of XOR
operations, its overall contribution is nullified. XOR of a Number with Zero is
the Number Itself:
A ⊕ 0 = A. This implies that the initial presence of a number (without any prior
XOR operations) is its own value.

The Concept of Cumulative XOR:
Cumulative XOR, or prefix XOR, is constructed by XORing each element of the
array with all previous elements' XOR. The cumulative XOR up to index i
represents the XOR of all elements from the start of the array to i. This allows
us to quickly calculate the XOR of any subarray from i to j as prefix_xor[j] ^
prefix_xor[i-1] (where ^ denotes XOR).

Bit-level Analysis for XOR Contribution
To understand how each bit contributes to the total sum, we analyze the problem
at the bit level. Each bit position in an integer can be either 0 or 1. The XOR
operation's result at each bit position is determined by comparing corresponding
bits in two numbers:
If the number of 1s at a bit position is even, that bit's contribution to the
overall XOR is 0. If the number of 1s is odd, the contribution is 1.

The Algorithm's Logic Initialization: We prepare a cnt array to track how many
times each bit (0 to 29, covering 30 bits for integers within the problem's
scope) is 0 or 1 in the cumulative XORs. This setup is crucial for understanding
how frequently each bit changes state across all subarrays.

Cumulative XOR Calculation: As we calculate the cumulative XOR for each element
in the array, we're essentially building a map of how the bits evolve through
the sequence. This step is foundational for determining the XOR of any subarray.

Determining Bit Contributions:
Here's the crux(gist) of the intuition:
For any bit position, the total sum contribution is calculated by considering
how many times it can potentially flip from 0 to 1 or vice versa across all
subarrays.
The flipping happens based on the XOR operation's nature: A bit flips
when it encounters an opposite bit. Thus, the contribution of a bit to the total
sum is its value (2 raised to the bit position) multiplied by the count of
opposite bits it encounters. Why count opposite bits? Because XOR is essentially
a binary addition without carry over. A bit contributes (flips) when paired with
an opposite bit (0 with 1 or 1 with 0). The number of such pairs is what
determines the total contribution of that bit across all subarrays.

Consider an array [1, 2, 3]:
Cumulative XOR: [0, 1, 3, 0] (including an initial 0 for the empty subarray)
Let's focus on a single bit position: the least significant bit (LSB, or 0th
bit). For each cumulative XOR, the LSB flips from 0 → 1 → 0 → 0. The counts of
0s and 1s at this position determine the flipping action. In this case, the LSB
of the XOR result contributes based on how many times it encounters an opposite
bit across all subarrays. The contribution calculation involves multiplying the
bit's value (2^0 for the LSB) by the number of times it encounters an opposite
bit.
*/