// https://codeforces.com/contest/1742/problem/E

#include <iostream>
#include <vector>
#include <algorithm>
/*
another grueling problem to understand. I'll be given the heights of the stairs. And then I will
be given some sample lengths of Timur's legs. I have to determine or give output how far Timur can
go with that length of legs.
*/
using namespace std;
// 4 5
// 1 2 1 5
// 1 2 4 9 10
void solve()
{
    int n, q;
    cin >> n >> q;

    vector<long long> prefix_sum; // at first we will take the prefix sum of the heights.
    prefix_sum.push_back(0);

    vector<int> prefix_max;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        prefix_sum.push_back(prefix_sum.back() + x); // learn the technique of calculating
        // prefix sum with vector.

        if (i == 0)
            prefix_max.push_back(x); // If we are at the first position (i == 0), we push the height
        // x to the prefix_max vector since it is the only maximum height encountered so far.
        else
            prefix_max.push_back(max(prefix_max.back(), x));
        // Otherwise, we compare the current height x with the maximum height encountered so far
        //  (prefix_max.back()), and we push the maximum of the two values to the prefix_max vector.
        //  This ensures that prefix_max always stores the maximum height up to the current position.
    }

    // The purpose of maintaining the prefix_max vector is to quickly determine the maximum height of
    // the stairs that Timur can step on with his current leg length.

    for (int i = 0; i < prefix_sum.size(); i++)
        cout << prefix_sum[i] << " ";
    cout << "\n";

    for (int i = 0; i < prefix_max.size(); i++)
        cout << prefix_max[i] << " ";

    cout << "\n";

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;

        int index = upper_bound(prefix_max.begin(), prefix_max.end(), k) - prefix_max.begin();
        cout << "THE REAL BOUND = " << index << "\n";

        cout << prefix_sum[index] << " "
             << "\n";
        /*
        upper_bound function to find the iterator pointing to the first element in prefix_max that
        is greater than k. This function returns an iterator to the first element that is greater
        than the given value, using a binary search algorithm. In other words, it finds the
        smallest element in prefix_max that is strictly greater than k(strictly greater means
        greater than k but not equivalent to k)
        */
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
