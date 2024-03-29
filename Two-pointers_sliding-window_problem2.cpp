/*
Problem 1 : Segment with Small Sum
I will be given an array of integers and number which is actually a limit of sum.
I have to print an integer which is the length of the longest sub-array, which will
have the total sum less than or equivalent to the limit.

7 20
2 6 4 3 6 8 9
4
here, the longest sub-array with at most sum of 20 will have a length of 4.

comparing to the previous problem, k(length of sub-array) is not fixed here & sum is
given.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, r = 0, sum = 0, ans = 0;

    while (r < N)
    {
        sum += arr[r];

        if (sum > K)
        {
            while (sum > K)  
            {
                sum -= arr[l];
                l++;
            }
        }

        if (sum == K) // if we find the sum == target sum, we take the max length.
            ans = max(ans, r - l + 1);

        r++; // we will simply move the right pointer everytime...
    }

    // if the sum is being greater than the target sum, we need to move the left pointer. and after
    // moving we will substract the arr[l]

    cout << ans;

    return 0;
}