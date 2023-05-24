/*
The problem statement is a bit grueling to understand.
Once upon a time, King Alexander of Greece lost his kingdom in a war. He could have saved his life
by hiding in a tunnel. He told his commander how he could be found in the tunnel.

The tunnel is made of blocks, each with a number written on the wall. King Alexander explained that
he would be in the leftmost block where the sum of all the numbers strictly to the left of that block
is equal to the sum of all the numbers strictly to the right of the block. Each block can be
represented by an index starting from zero. Can you now tell me the leftmost index where the king
is hidden?

If the index is on the left edge of the array, then the left sum is 0 because there are no elements
to the left. This also applies to the right edge of the array.

If the king cannot be found, it means that he is no longer alive. In that case, you need to indicate
-1.

Input Format
First line will contain T, the number of test cases.
Second line will contain N, the number of blocks in that tunnel.
Third line will contain an integer array A of N values that were written on each block.
Constraints
1 <= T <= 1000
1 <= N <= 10^5
-1000 <= A[i] <= 1000 ; Where 0 <= i < N
Output Format
Output the index of the block in which king could be found, otherwise print -1.
Sample Input 0
3
6
1 7 3 6 5 6
3
1 2 3
3
2 1 -1
Sample Output 0
3
-1
0
Explanation 0
In the first test case, the index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
In the second test case, there is no index that satisfies the conditions in the problem statement.
In the third test case, the index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

Here, I just need to find an index which have equal sums for both of it's right and left part
suppose, 1 2 3 4 6
here, index 3 have equal sums for it's both left and right part which is 6.
*/

#include <iostream>
#include <vector>

using namespace std;

int findKingIndex(const vector<int> &nums)
{
    int n = nums.size();         // first we take a vector to store the prefix sum
    vector<int> prefixSum(n, 0); // set to 0 initially

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++
        prefixSum[i] = prefixSum[i - 1] + nums[i]; //everytime a new element of the nums is being 
        //taken and being added to the prefix sum.

    for (int i = 0; i < n; i++)
    {
        int leftSum = (i == 0) ? 0 : prefixSum[i - 1];  // ternary operator
        int rightSum = prefixSum[n - 1] - prefixSum[i]; // finally we take the left sum and right
        // sum from a particular index and check if they are equal or not.

        if (leftSum == rightSum)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> nums(N);
        for (int i = 0; i < N; i++)
            cin >> nums[i];

        int kingIndex = findKingIndex(nums);
        cout << kingIndex << endl;
    }

    return 0;
}
