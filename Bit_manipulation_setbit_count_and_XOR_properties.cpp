// https://codeforces.com/contest/1895/problem/D
/*
☞ Better.Call.Vee ☜
created: 04th November, 2023 06:01:09 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> bitcounts(2, vector<int>(20));
void cnt_setbit(int id, int num) {
    while(num) {
        int LSB = num & -num, th_position = __lg(LSB);
        bitcounts[id][th_position]++;
        num &= (num - 1); // or num -= LSB;
        // Clears the least significant set bit in num. This is a standard
        // technique in bit manipulation: subtracting 1 from num flips all bits
        // up to and including the first set bit, and the bitwise AND with the
        // original num clears that bit.
        // or, Subtracting LSB from num directly removes the least significant
        // set bit.
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, inp;
    cin >> n;

    vector<int> xor_sum(n);
    xor_sum[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> inp;
        xor_sum[i] = xor_sum[i - 1] ^ inp;
        cnt_setbit(0, i), cnt_setbit(1, xor_sum[i]);
    }

    int b_zero_modifier = 0;
    for(int i = 0; i < 20; i++)
        if(bitcounts[0][i] != bitcounts[1][i]) b_zero_modifier |= (1 << i);

    for(int i = 0; i < n; i++) cout << (b_zero_modifier ^ xor_sum[i]) << " ";

    return 0;
}