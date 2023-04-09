/*
Suppose an array => arr[1, 2, 3, 4, 5]
[1]/[1,2]/[4,5]/[1,2,3,4,5] and more are the subarrays of array arr. Not like this: [2,4]/[1,5]
It has to be contiguous.

The problem is we will be given an array and a length "k". We have to find out a "k" length subarray
which has the maximum sum among all the "k" length subarrays.

in the array, first we take [1,2], then [2,3], then [3,4]. look it's sliding right. that's why it's
called sliding window.
k will be fixed

suppose another array => sw[5 7 9 14 2 23]
                          l,r
l and r are at the same position now. Then we move(slide). Suppose the k is 2.
sw[5  7  9  14  2  23]
   l  r
in 0  1  2   3  4   5
so, k => r-l + 1.
when we will hit the destined k value, we will approach differently. we will substract the l
from sum and add the r everytime and then increase l and r's indices by 1.
for the sw array,
previously sum = 12. then we move l to 7 from 5. r to 9 from 7. substract 5 from sum => 7+9 =>
new sum = 16. like this. Look there's a sliding visible while we are doing this.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, k;
   cin >> n >> k;
   vector<int> v(n); // taking the n sized array.
   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
   }

   int l = 0, r = 0, sum = 0, ans = -1;

   while (r < n)  //array's indexing is one less than the given n input.
   {
      sum += v[r]; //like I described above.

      if (r - l + 1 < k)
      {
         r++; // we are moving forward/sliding until the length of the
         // subarray is equivalent to k.
      }
      else if (r - l + 1 == k)
      {
         ans = max(ans, sum);
         sum -= v[l]; //like I described above.
         r++;
         l++;
      }
   }

   cout << ans;
   /*
   9 3
   5 6 1 13 7 5 12 8 2
   25
   */
   return 0;
}