/*
Now we will be given k options. 1 stone, 2 stones....k stones jump. A frog now can jump over at most
100 stones at a time. And the rest of the statement is the same.

5 3
10 30 40 50 20
here, the frog can jump 3 stones at most at a time.
He will at first jump 1 stone => 10 to 30 = cost 20
then, 30 to 20(3 stones at a time) => cost 10
so, answer will be 30.

3 1
20 30 20
here, the k is 1. So, the frog has only one option that's jumping 1 stone at a time!
So, the output will be 20!

now, let's understand another thing
 1     2      3     4      5     6      7     8
🪨    🪨    🪨    🪨    🪨    🪨    🪨    🪨
suppose the k is 4. if the ith stone is 6. We can reach there from i-4, i-3, i-2, i-1.
                                                                     2,   3,   4,   5.
That's the main point. We can reach i from (i-1, i-2, i-3....i-k)

OUR 3 BASIC DP STATES:
1) stone(n) -> Min cost to reach stone N
2) stone(i) -> min{stone(i-1) + |hi-h(i-1)|,.....stone(i-k) + |hi-h(i-k)};

previously, we called the function with stone(n) and that's why the time complexity of the program
will be O(n) and we were checking only two options with O(1) time complexity!
But now, we have to check 1 to k times!! So, the updating step's time complexity will be O(k).
So, the ultimate time complexity of this code will be O(n*k)
And the space complexity will remain the same {O(n)} because we are only taking an array of n elements

https://atcoder.jp/contests/dp/tasks/dp_b
in this problem, the max value of N and k are correspondingly 10^5 and 10^2
so the max time complexity will be 10^7

*/
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int h[N], dp[N];
int n, k;

int stone_2(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    // if answer is already calculated, return it.
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // calculate answer from smaller subproblems.
    int ans = INF;

    // handle corner case
    int limit = min(k, n - 1);
    if (limit <= 0)
        limit = 1;

    for (int i = 1; i <= limit; i++)
    {
        int candidate_ans = stone_2(n - i) + abs(h[n] - h[n - i]);
        ans = min(ans, candidate_ans);
    }

    dp[n] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    dp[1] = 0; // initialize base case
    for (int i = 2; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << stone_2(n) << endl;

    return 0;
}

/*
67-69 lines explanation
In the for loop inside the stone_2 function, we consider all possible distances that can be covered in
a single jump, from 1 to k. However, we need to be careful when considering distances that could take
us out of bounds of the stones.

Let's consider an example where we have 4 stones and k=3. The stones are at heights 10 20 30 40,
respectively.

stones: 1   2   3   4
height: 10  20  30  40
Starting from the first stone, we can jump a maximum of k=3 stones. This means we can reach stones
2, 3, and 4 in a single jump.

If we are at the first stone, we can jump to stones 2, 3, or 4. The cost of jumping to stone 2 is
abs(20 - 10) = 10. Similarly, the cost of jumping to stone 3 is abs(30 - 10) = 20, and the cost of
jumping to stone 4 is abs(40 - 10) = 30.

Now let's consider the second stone. From the second stone, we can jump to stones 3, 4, or 5. However,
there is no fifth stone, so we need to be careful when calculating the cost of jumping from the second
stone.
We need to consider only the stones that are reachable from the current stone within k jumps.

If we try to jump from the second stone to the fifth stone (which doesn't exist), we would get an out
of bounds error. This is why we need to make sure that we only consider jumps that won't take us out
of bounds.

In general, when we are at the ith stone, we can jump to stones i+1, i+2, ..., i+k. However, if i+k
is greater than n, then we would be trying to jump out of bounds, which we don't want to do.

Therefore, we need to limit the maximum distance we can jump from the ith stone to min(n-i, k). This
ensures that we only consider jumps that won't take us out of bounds.

In the updated code, this is done using the line:

int limit = min(k, n - 1);
If n is less than or equal to 1, we set limit to 1 to avoid getting a negative value in the loop.
Then, in the for loop, we consider distances from 1 to limit, which ensures that we only consider
jumps that won't take us out of bounds.

an example:
For the input 2 4, the function stone_2 will return 90, which is the correct answer.

When n=2 and k=4, the for loop in the stone_2 function will run for i=1 and i=2, since min(k, n-1) = 1.
For i=1, the candidate_ans will be calculated as stone_2(n-i) + abs(h[n] - h[n-i]) which is equal to
stone_2(1) + abs(10 - 100) = 0 + 90 = 90, since h[1] = 100 and h[2] = 10. Similarly, for i=2,
candidate_ans will be calculated as stone_2(n-i) + abs(h[n] - h[n-i]) which is equal to
stone_2(0) + abs(10 - 100). Since n-i = 0, stone_2(n-i) will return 0, and hence candidate_ans will
be equal to 0 + 90 = 90. Finally, ans will be set to the minimum value of candidate_ans, which is 90.
Therefore, the function will return 90 as expected.

Another explanation from me why it's n-1:
look everytime in the loop we are taking the dp[n-i]. if i is equivalent to n already, it will be
dp[0] which we don't handle. So, we go for n-1

*/

/// TABULATION

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int h[N], dp[N];

int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    dp[1] = 0; // base case

    // loop through the states
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;
        // calculate answer for smaller sub-problems

        int limit = min(i - 1, k);
        if (limit <= 0)
            limit = 1;

        for (int j = 1; j <= limit; j++)
        {
            int candidate_ans = dp[i - j] + abs(h[i] - h[i - j]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }

    cout << dp[n] << endl;

    return 0;
}