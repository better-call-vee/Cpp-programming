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
by 2^number of combinations.


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
half means division by 2 and thus power one minus.
now, come to the zeroes. they will make nit 2^(cnt[0]) subsets.
now, ulitmately => 2^(cnt[0] + cnt[1] - 1) subsets will be there with odd 1
count(XOR 1, not 0)
which is actually 2^(n - 1) [cnt[0] + cnt[1] == n]

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
//calculations.
//         int contribution = 1 << (n - 1);
//         ans += contribution * (1 << i);
//         // bit by bit calcultaion, so for sum we need to apply
//         // this(why=stated previously: line 1)
//     }
//     cout << ans;
//     return 0;
// }