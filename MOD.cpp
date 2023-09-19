#include <bits/stdc++.h>
using namespace std;
//The use of MOD made this time efficient. 
//https://codeforces.com/contest/1863/problem/C
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int missing = -1;
        vector<int> trk = nums;
        sort(trk.begin(), trk.end());
        for (int i = 0; i < n; i++)
        {
            if (i != trk[i])
            {
                missing = i;
                break;
            }
        }
        if (missing == -1)
            missing = n;

        list<int> numsList(nums.begin(), nums.end());

        if (k > n)
            k = (k % (n + 1));
        for (int i = 0; i < k; i++)
        {
            numsList.push_front(missing);
            missing = numsList.back();
            numsList.pop_back();
        }

        for (int val : numsList)
            cout << val << " ";

        cout << "\n";
    }

    return 0;
}
