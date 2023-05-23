/*
Suppose, I am given an array of integers. I need to find the maximum/minimum sum possible of 3
integers among them.
6
4 8 2 9 1 6
At first, we will sort the array.
1 2 4 6 8 9
Then we will just take the first three elements from the array to get the minimum sum and will take
the first last three elements to take the maximum sum.
This is called Greedy algorithm.
It's like an ad hoc algorithm. Ad hoc means something that has been formed or used for a special and
immediate purpose, without previous planning. We never know where to use the Greedy Algorithm.

But let's look at a problem:
What if they ask for the maximum product of the given numbers using 3 numbers.
There can be many corner cases. Let's look at all types of cases.

Normal Greedy Approach: 8 9 1 3 4
all positive numbers. Here we can just simply apply the greedy approach and sort the array. Then
take the maximum 3 numbers(which will be the last three numbers)

Mixture of positive and negative numbers: -3 -7 -9 1 9 7
after sorting: -9 -7 -3 1 7 9
If we just take the greatest 3 numbers => 1*7*9 = 63
But here the maximum product will be => -9*-7*9 = 567
So, we have to handle this case as well => if there are negative numbers, we have to compare the
products if we take the 3 max int with if we take 2 neg nums and a positive int.

So, greedy's matter is like this. At first we will go for brute force and then we will go for
different test cases and find the corner cases. Then we will try to fix.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int pro1 = 1;
    int pro2 = 1;

    for (int i = n - 3; i < n; i++)
        pro1 *= nums[i];

    for (int i = 0; i < 2; i++)
        pro2 *= nums[i];

    pro2 *= nums[n - 1];

    if (pro1 > pro2)
        cout << "The maximum sum of 3 numbers here is: " << pro1;
    else
        cout << "The maximum sum of 3 numbers here is: " << pro2;

    return 0;
}

// dijkstra is also an example of greedy algorithm