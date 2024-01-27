// sum of the elements in the array using Bitlaw.
// look at a number, say 19 => 2^4 + 2^1 + 2^0 => 10011.
// so, every number can be stated as the sum of 2's powers.
// thus:
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n, x;
//     cin >> n;
//     vector<int> bitcnt(30, 0);
//     for(int i = 0; i < n; i++) {
//         cin >> x;
//         for(int bit = 0; bit < 30; bit++)
//             if(x >> bit & 1) bitcnt[bit]++;
//     }
//     for(int i = 0; i < n; i++) ans += bitcnt[i] * (1 << i);
//     cout << ans << "\n";
//     return 0;
// }

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

/*
Sum of all pair XORs:
Typically it will take O(n^2) to get the some of all
pair xors.
for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) sum += a[i] ^ a[j];
like this.

We have to think it in O(n)
So, the first rule of a bit related problem is think it with 0 and 1 containing
array.
So, let's take an array with only 0 and 1.
0 1 0 0 1 1 0
we know that 0^1 is 1 and 1^1 is 0. So, we will take only those pairs which will
make it 1 => {0, 1} and {1, 0};
there are 4 zeroes and 3 ones in the array. so, there can be 4 x 3 of {0, 1}
pair combination and 4 x 3 of {1, 0} combination. so, count of 0s and count of
1s x 2 => sum of all pair XORs.

Now we will do it bit by bit because XOR's independent.
0 1 0 1 => 5
0 1 0 0 => 4
1 0 1 0 => 10
1 0 0 0 => 8
every bit by bit operation will be there.
previously with the 0 and 1 array we depicted every bit
actually, take a look at the bits. i.e.: the 3rd bit: 0 0 1 1.
there will be 2*2*2 combinations where 0 and 1 will pair. and thus,
we will get 1. therefore, that will be added in total contribution
by 2^number of combinations(setting that msb);


for AND => cnt[1] * cnt[1];
for OR => cnt[1] * cnt[1] + 2*cnt[1]*cnt[0];
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n, x, ans = 0;
//     cin >> n;
//     vector<vector<int>> cnt(31, vector<int>(2, 0));
//     for(int i = 0; i < n; i++) {
//         cin >> x;
//         for(int bit = 0; bit <= 30; bit++)
//             (x >> bit & 1) ? cnt[bit][1]++ : cnt[bit][0]++;
//     }
//     for(int i = 0; i <= 30; i++) {
//         int contribution = cnt[i][0] * cnt[i][1] * 2;
//         ans += contribution * (1 << i);
//         // bit by bit calcultaion, so for sum we need to apply
//         // this(why=stated previously: line 1)
//     }
//     cout << ans;
//     return 0;
// }

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

/*
Sum of All subsets XOR:

Now we need to count the number of subsets which have a XOR of 1.
in a subset, if one's count is even, the XOR will be 0. else XOR will be 1.

Let's follow the main rule and start with a 0, 1 containing array.
0 0 1 0 1 0 1 1 0
0 0 0 0 0 1 1 1 1 (after sorting, to make the learning easier)
see, for 1 1 1 1, we will be able to make 2^4 subsets, among them half will make
subsets with odd number of 1. it's a simple logic, just simple thinking. among
2^4 subsets, the subsets which have odd number of 1, there will be even number
of 1 after we will add one more 1. so half odd, half even. thus, 2^(cnt[1] - 1);
half means division by 2 and thus power one minus. Make subsets of four 1s, you
will be able to observe.
now, come to the zeroes. they will make nit 2^(cnt[0])
subsets. now, ulitmately => 2^(cnt[0] + cnt[1] - 1) subsets will be there with
odd 1 count(XOR 1, not 0) which is actually 2^(n - 1) [cnt[0] + cnt[1] == n]

N.B: We will need the usage of mod for this. high values expected.

For AND, we will only take 2^(cnt[1]). this time no minus needed, AND just need
1. No demand, no complain only one. That's AND for you.
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n, x, ans = 0;
//     cin >> n;
//     vector<vector<int>> cnt(31, vector<int>(2, 0));
//     for(int i = 0; i < n; i++) {
//         cin >> x;
//         for(int bit = 0; bit <= 30; bit++)
//             (x >> bit & 1) ? cnt[bit][1]++ : cnt[bit][0]++;
//     }
//     for(int i = 0; i <= 30; i++) {
//		   if(!cnt[i][1]) continue; // corner case
//		   // if there is no one, then what's the point of all
// calculations.
//         int contribution = 1 << (n - 1);
//         ans += contribution * (1 << i);
//         // bit by bit calcultaion, so for sum we need to apply
//         // this(why=stated previously: line 1)
//     }
//     cout << ans;
//     return 0;
// }
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*
Number of Sub-arrays with XOR 0:

Compute the prefix XOR array p. Then, for each i, we need to find the number of
l < r such that p[r] ⨁ p[l-1] = 0. So, we need to find the number of l < r such
that p[r] = p[l-1]. We can use a map to store the number of times each value
appears in the prefix XOR array. Then, for each r, we can get the number of 1 ≤
l ≤ r such that p[r] = p[l-1] which is same as number 0 ≤ l < r such that p[r] =
p[l]; T.C. => O(nlogn);
The XOR of a sub-array from l to r can be found by p[r] ⨁ p[l-1]. If this is 0,
then p[r] = p[l-1]

Imagine a = [4, 2, 2, 6, 4].
Prefix XOR p = [0, 4, 6, 4, 2, 6] (with p[0] = 0).
Thus mp[p[0]]++;
*/
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e6 + 9;
// int a[N], p[N];

// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         p[i] = p[i - 1] ^ a[i];
//     }
//     map<int, int> mp;
//     long long ans = 0;
//     mp[p[0]]++; // don't forget to add this (why?)
//     for(int i = 1; i <= n; i++) {
//         ans += mp[p[i]];
//         mp[p[i]]++;
//     }
//     cout << ans << '\n';
//     return 0;
// }

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*
SUM OF ALL SUBARRAY XOR * LENGTH.

Just print the code with example:
3
1 2 3
and try to understand.
We take the cumulative prefix XOR.
why c[b^1]?
You know what prefix[r] = prefix[l] when their xor is 0.
So, we only take which have a cumulative XOR not equal to 0.
and then, we just subtract the opposite set's(if set = 1, then opposite = 0 and
vice versa) cumulative indices count, which is because they will make subarrays
among themselves and their length should be out of count.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9, mod = 998244353;
int a[N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    int ans = 0;
    for(int k = 0; k < 2; k++) {
        vector<int> s(2), c(2);
        c[0] = 1;
        for(int i = 1; i <= n; i++) {
            int b = (a[i] >> k) & 1;
            cout << "b => " << b << "\n";
            cout << "c[b^1] => " << c[b ^ 1] << "\n";
            cout << "s[b^1] => " << s[b ^ 1] << "\n";
            ans = (ans + 1LL * (1LL * c[b ^ 1] * i % mod - s[b ^ 1] + mod) %
                             mod * (1 << k)) %
                  mod;
            cout << "ans => " << ans << "\n";
            c[b]++;
            for(int i = 0; i < 2; i++) {
                cout << "c[" << i << "]: " << c[i] << "\n";
            }
            s[b] = (s[b] + i) % mod;
            for(int i = 0; i < 2; i++) {
                cout << "s[" << i << "]: " << s[i] << "\n";
            }
            cout << "\n";
        }
        cout << "\n\n\n";
    }
    cout << ans << '\n';
    return 0;
}

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//PERMUTATIONS OF ALL PAIR XOR between a and b array https://codeforces.com/gym/104333/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n), cnt(20, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll perms = 1, sum = 0;
    for(int i = 1; i < n; i++) perms = (1LL * perms * i) % mod;
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < n; j++)
            if((a[j] >> i) & 1) cnt[i]++;
    for(int i = 0; i < 20; i++) {
        ll contrb = (1LL * perms * (1 << i)) % mod;
        for(int j = 0; j < n; j++) {
            if((b[j] >> i) & 1)
                sum += (n - cnt[i]) * contrb % mod;
            else
                sum += cnt[i] * contrb % mod;
        }
    }

    cout << sum % mod;
    return 0;
}

/*
Line 13:
the key observation is that each particular element from array a will be paired
with every element from array b exactly (n - 1)! times across all n!
permutations. This is because for any fixed position in the permutation, there
are (n - 1)! ways to arrange the remaining elements. Therefore, the code
calculates cntx as (n - 1)! to represent the number of times each a[i] will be
paired with each bit position of the b array elements.

Line 20 to 23:
we stored 'a' array's set bit counts of each element in the cnt vector. Now XOR
will only contribute while 1 ^ 0 will happen. For all pair XORs of permutation
between a and b, if 'b' array's current bit is not set, we go with the count of
set bits of 'a' array on that position. Also, when 'b' array's current bit is
set, we go with the 'a' array's not set bit count on that particular position.
*/