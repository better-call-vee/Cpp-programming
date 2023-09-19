// https://codeforces.com/contest/1863/problem/B

#include <iostream>
#include <vector>
using namespace std;

void run_case()
{
    int N;
    cin >> N;
    vector<int> P(N + 1);
    vector<int> location(N + 1, -1);

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
        location[P[i]] = i;
    }

    int ans = 0;

    for (int i = 1; i < N; i++)
        ans += location[i] > location[i + 1];

    cout << ans << '\n';
}

/*
In the given code, the loop checks for every consecutive pair (i,i+1) to see if i appears after 
i+1 in the permutation. If it does, that means we need an operation (choosing x = i+1) to correct
this.
By counting these instances, we determine how many operations are required to sort the permutation.
The final count provides the minimum number of operations needed to sort the permutation.
The logic behind this algorithm is based on the understanding that each operation can at most 
correct the order between one pair of consecutive numbers in the desired final permutation. 
Thus, by counting the number of these inversions, we have the answer.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
        run_case();

    return 0;
}

/*
How's it guarrented that every operation will fix a pair???
Suppose, location[i], i is 3, it's location is on 4th index. and location[i+1], i is 4, it's location
is on 3rd index.
So, we need an operation. we take x as i+1 which is 4. 
now, the less elements than 4 go in front of 4 in the sequence. and the greater elements go after
it. But eventually selecting i+1 as x fix the pair of 3 and 4, 3 goes in front of 4. 
thus, an operation fix a pair.And the minimum number of operations are the count of pair fixation.

Cascade Effect: By ensuring each i+1 are in the right order, we indirectly make sure the entire
sequence is sorted. 
Consider a simple example: if you ensure 1 is before 2, 2 is before 3, 3 is before 4, and so on,
then by extension, you've ensured that 1 is before 4, 2 is before 5, etc.

Cascade effect means inevitable cyclic operations.
*/