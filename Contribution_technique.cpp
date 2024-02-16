/*
really interesting topic. We will reduce the time complexity of O(n^2) cases
with this technique, just some observation is needed.

Ex : 1 => Sum of All pairs.
here, if we do the problem in a brute force way, it will take O(n^2) time
complexity. if we observe the thing:
a = a[1], a[2], a[3];
a[1] + a[1], a[1] +a[2], a[1] + a[3]
a[2] + a[1], a[2] + a[2], a[2] + a[3]
a[3] + a[1], a[3] + a[2], a[3] + a[3]
see, every element has contributed 6 times in a 3 sized array
and which means they contributed 6 times each. thus, 2*n.
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     vector<int> a = {1, 9, 3, 2, 4};
//     ll ans = 0;
//     int n = a.size();
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             ans += (a[i] + a[j]);
//         }
//     }
//     cout << "O(n^2) => " << ans << "\n";
//     ans = 0;

//     for(int i = 0; i < 5; i++) ans += (2 * n * a[i]);
//     cout << "O(1) => " << ans << "\n";
//     return 0;
// }

//-----------------------------------------
//------------------------------------
/*
Ex : 2 => Sum of Sub-array sums.
a = a[1], a[2], a[3]...a[i]...a[n];
There will be total n * (n + 1) / 2 sub-arrays.
if we look at a[i], a[i] will be included in i*(n - i + 1)
subarrays. how?
To include a[i], it's previous elements' will have to take
the subarrays past a[i] or with a[i].
a[1], a[2], a[3]...a[i], a[i+1], a[i+2]...a[n];
so, every element including a[i] from a[1] will create n - i + 1
different sub-arrays.
*/

/*
Ex : 3 => Sum of Subset sums.
Number of subsets of an array = 2^n (including the empty subset)
a[1], a[2], a[3]...a[i]...a[n];
for every element we have two choices to build a subarray, whether we will
take it or not.
so, n elements, 2^n choices. 2^n subsets.
Of the total subsets(2^n), a[i] is included in half of them and excluded in the
other half. So, a[i] is included in 2^(n-1) subsets. Thus, there will be 2^(n-1)
subsets which will not contain a[i]. AND, 2^(n-1) subsets will contain a[i].
(2^n - 2^(n-1) = 2^(n-1)) [2^(n-1) = 2^n/2]; so, subset sum will be = from(1 to
n) => a[i] * 2^(n-1);
Imagine you have an array of 3 elements: [1, 2, 3].

There are 8 subsets: [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3].
Each element (1, 2, and 3) appears in exactly half of these subsets (4 out of
8). So, for each element, you're essentially multiplying it by the number of
subsets it appears in (which is 2^(3-1) = 4) to get its total contribution to
the sum of all subset sums.
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     vector<int> a = {1, 2, 3}; // Example array
//     ll subsetSum = 0;
//     int n = a.size();
//     // Calculate the number of subsets each element appears in
//     ll subsetsCount = 1 << (n - 1); // 2^(n-1)
//     // Calculate the total sum of all subset sums
//     for(int i = 0; i < n; i++) subsetSum += a[i] * subsetsCount;
//     cout << "Sum of all subset sums: " << subsetSum << "\n";
//     return 0;
// }

//--
/*
Ex : 4 => XOR of Sub-arrays XOR
it's like sub-array sums, but we just need to if i * (n - i + 1) is odd or even.
If even, then it won't contribute to the total XOR. If odd, it will.
If it says all pairs' XOR, then it will be absolute zero. You know why 😉
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     vector<int> a = {1, 9, 3, 2, 4};
//     ll result_xor = 0; int n = a.size();
//     for(int i = 0; i < n; ++i) {
//         ll subarrays_count = (i + 1) * (n - i);
//         if(subarrays_count % 2 != 0) result_xor ^= a[i];
//     }
//     cout << "XOR of Sub-arrays XOR: " << result_xor << "\n";
//     return 0;
// }
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*
Ex : 5 => Sum of max - min of subsets.
here, suppose, 1 2 3 4 5.
we will fix the max and the min element. If we fix the min and the max,
we can't take any element from the right of the max and from the left of the min
to the subset calculations. Then we will have k elements in between them. We
will be able to create 2^k subsets with that max and the min. We are now
calculating the sum of every possible max and min. first we sort the array to do
this. We exclude the single subsets because it will have a difference of 0.
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n = 5, ans = 0;
//     vector<int> a = {1, 3, 5, 4, 2};
//     sort(a.begin(), a.end());
//     for(int i = 0; i < n; i++)
//         for(int j = i + 1; j < n; j++)
//             ans += (a[j] - a[i]) * (1 << (j - i - 1));
//     cout << ans << '\n';
//     return 0;
// }
/*
fun fact is it can be solved in O(n);
how?
we can take the contribution of how many times an element will be max and how
many times it will be min and we will subtract the min contribution from the
max.
suppose,  1 2 3 4 5
4 will be max in 2^(4 - 1) subsets. so max = 4 * 2^(4 - 1). here, second 4 =
index(n); 4 will be min in 2^(2 - 1) subsets, so min = 4 * 2^(2 - 1). Not
including single subsets including only 4 anywhere(min or max), because, they
will give 0.
*/
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     vector<int> a = {1, 2, 3, 4, 5};
//     ll ans = 0;
//     int n = a.size();
//     sort(a.begin(), a.end());
//     for(int i = 0; i < n; i++) {
//         ll maxContribution = (ll)a[i] * (1LL << i);
//         ll minContribution = (ll)a[i] * (1LL << (n - i - 1));
//         ans += (maxContribution - minContribution);
//     }
//     cout << "Sum of max-min of subsets: " << ans << '\n';
//     return 0;
// }

//-------------------------------------------------------------------------------------------
/*
Ex : 6 => Sum of Sum * length over all Subarrays.
Means, we have to multiply the lengths of the subarrays with their sum every
time and then we have to ouput the total sum.
quite a tough one.
let's think: while getting the sub-array sums
we take the sum considering i * (n - i + 1). (read 39-49 lines)
so, if we consider the lengths, the equation is (r - l + 1);
here,
 i   n
 Σ   Σ (r - l + 1)
l=1 r=i

=>  i
    Σ  (Sum(i, n) - l(n - i + 1) + (n - i + 1));
   l=1
(for r, we are taking the sum of possible r, n - i + 1 values will be there,
so n - i + 1 times l is being subtracted and 1 is being added.)
now,
--------------------------------------------------------------
=> Sum(i, n) * i - (n - i + 1) * Sum(1, i) + i * (n - i + 1);|
--------------------------------------------------------------
(l's value is 1 to i, so, Sum(i, n) is getting multiplied i times,
sum of 1 to i goes in place of l, and i times multiplied with (n - i + 1));
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int a[N];
int F(int n) { return (1LL * n * (n + 1) / 2) % mod; }
int S(int l, int r) { return (F(r) - F(l - 1) + mod) % mod; } // range sum.
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int contrib = (1LL * S(i, n) * i % mod -
                       1LL * (n - i + 1) * S(1, i) % mod + mod) %
                      mod;
        // + mod because it can produce negatives, so negative's mod formula
        // applied.
        contrib = (contrib + 1LL * (n - i + 1) * i % mod) % mod;
        ans += 1LL * a[i] * contrib % mod;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}

/*
Ex : 7 => Sum of Number of Inversions in Permutations
there will be n! permutations of n numbered of elements.
suppose, 1 2 3.
1 2 3
1 3 2   see, 3 1, this inversion is 3 times there and the other 3 times 1 3.
3 2 1   so, every half of the n! is it's inversion count. now why n*(n-1)/2?
3 1 2   for, 3, it will have inversions with 2 and 1. for 1, no one. for 2,
2 3 1   only 1. so, sum of 1 to n - 1.
2 1 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(int n) {
    if(n <= 1) return 1;
    return n * f(n - 1);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << f(n) << "\n";
    cout << 1LL * (f(n) / 2) * (n * (n - 1) / 2);
    return 0;
}

/*
sum of vowel containing sub-arrays:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or
           s[i] == 'u')
            ans += 1LL * (i + 1) * (n - i);
    }
    cout << ans << "\n";
    return 0;
}
*/

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*
SUM of all pairs Differences where i < j(subsets):

It's quite similar to the sum of all subsets max - min problem. Here, just an
addition is multiplying the whole sum with 2^(n-2). Why? see, when we will take
the difference of two numbers in account we will have n-2 choices to add an
element to that subset. So, with that particular i and j, we will be able to get
2^(n-2) subsets. Which implies that we will get a particular amount of
combinations where a particular i and j will make combination and that is
2^(n-2).
For (1,5,9,2): [1, 5]  [1, 2]  [1, 9]  [5, 2]  [5, 9]  [9, 2]  [1, 5, 9]
[1, 5, 2]  [1, 9, 2]  [5, 9, 2]  [1, 5, 9, 2];

see, every combination here is 2^(n-2) times present.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e5;
vector<int> twospower(N, 1);
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 1; i < N; i++) twospower[i] = twospower[i - 1] * 2 % mod;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) {
        cout << a[0];
        return 0;
    }
    sort(a.begin(), a.end());
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ll contrb =
            ((1LL * a[i] * i - 1LL * a[i] * (n - i - 1)) % mod + mod) % mod;
        total = (total + contrb) % mod;
    }
    cout << (1LL * total * twospower[n - 2]) % mod;
    return 0;
}

/*

Educational Outreach: To inform and educate users about the historical and
cultural significance of each site, promoting a deeper understanding of
Bangladesh's rich heritage. Cultural Preservation: To contribute towards the
preservation of historical sites by raising awareness and fostering a sense of
responsibility among the populace and authorities. Tourism Enhancement: To boost
local and international tourism by showcasing the beauty and historical depth of
Bangladesh's sites, thus contributing to economic development. Community
Engagement: To involve local communities in the storytelling process, ensuring
that oral histories and lesser-known facts are preserved and shared.
*/