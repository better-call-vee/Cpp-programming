/**
You are given an array of n
 integers, and your task is to find two values (at distinct positions) whose
 sum is x
.

Input

The first input line has two integers n
 and x
: the array size and the target sum.

The second line has n
 integers a1,a2,…,an
: the array values.

Output

Print two integers: the positions of the values. If there are several solutions,
you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2*10^5

1≤x,ai≤10^9

Example

Input:
4 8
2 7 5 1

Output:
2 4

**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(make_pair(num, i + 1));
    }

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = nums[left].first + nums[right].first;

        if (sum == x)
        {
            cout << nums[left].second << " " << nums[right].second;
            return 0;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}

