//Well, there is an another problem I got like this. I will explain the code there. 
#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefixSum(n, 0);

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
        int rightSum = prefixSum[n - 1] - prefixSum[i];

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
        {
            cin >> nums[i];
        }

        int PivotIndex = findPivotIndex(nums);
        cout << PivotIndex << endl;
    }

    return 0;
}
