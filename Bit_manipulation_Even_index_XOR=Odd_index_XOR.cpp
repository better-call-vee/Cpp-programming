#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, nth = 0;
        cin >> n;
        for(int i = 1; i <= n - 3; i++) {
            cout << i << " ";
            nth ^= i;
        }
        nth ^= (1 << 21);
        nth ^= (1 << 20);
        cout << (1 << 21) << " " << (1 << 20) << " " << nth << "\n";
    }
    return 0;
}

/*
Loop for First n-3 Elements:

The loop runs from 1 to n-3, inclusive. For a 1-indexed array, these positions
are odd for i = 1, 3, 5, ... and even for i = 2, 4, 6, .... As the loop
progresses, each i is XORed into nth. After the loop, nth contains the
cumulative XOR of all these numbers. Last Three Elements:

The last three elements are chosen as 2^21, 2^20, and nth ^= (1 << 21) ^= (1 <<
20). After the loop, nth is XORed with 2^21 and 2^20. This step is crucial to
balance the XOR sums of even and odd positions. Balancing XOR:

By adding 2^21 and 2^20 to the array, and adjusting the last element
accordingly, the code ensures that the XOR of all even positions equals the XOR
of all odd positions. Understanding the XOR Balancing: Even-Odd Positioning:

If n is even, the positions n-2 and n are even, and n-1 is odd.
If n is odd, the positions n-2 and n are odd, and n-1 is even.


Impact of Last Three Elements:
The choice of 2^21 and 2^20 for the penultimate and antepenultimate elements is
strategic. These are large powers of 2 with distinct single bits set, ensuring
they don't interfere with each other when XORed. The calculated value for the
last element (nth ^= (1 << 21) ^= (1 << 20)) is designed to ensure the XOR sums
of even and odd positions are equal. Example of Balancing: Case of n Being Even:

Odd positions: Cumulative XOR of 1, 3, 5, ..., n-3 and nth (last element).
Even positions: Cumulative XOR of 2, 4, 6, ..., n-4, 2^21, and 2^20.
The last element (nth) is calculated to ensure these two XOR sums are equal.
Case of n Being Odd:

Odd positions: Cumulative XOR of 1, 3, 5, ..., n-4, 2^21, and 2^20.
Even positions: Cumulative XOR of 2, 4, 6, ..., n-3 and nth (last element).
Again, nth is set to balance the XOR sums.


Conclusion:
The code creates an array where the XOR of elements at even positions equals the
XOR of elements at odd positions. The strategic choice of 2^21 and 2^20 for the
last three elements, combined with the calculated value for the final element,
achieves this balance. This approach effectively zeroes out all bits in the XOR
sum by ensuring that for every bit set in the cumulative XOR of the first n-3
elements, there is a corresponding bit set in one of the last three elements.
This clever use of bitwise XOR properties fulfills the problem's requirements.
*/