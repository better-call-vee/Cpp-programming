/*
This is a problem to learn the pre increment, frequency
and also sliding window with a different approach at the same time.
So, intuitive problem.
The problem is about TV shows. I will be given a number of TV shows.
The types of the TV shows and The number of consecutive days I have
to watch .
I have to give output of the minimum number of subscriptions needed
for the shows to watch dayNums consecutive days incessantly.
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 2E5;
constexpr int MAX_K = 1E6; // better version of const;

int testCases;
int numShows, numTypes, dayNums;
int shows[MAX_N];
int frequency[MAX_K];

void solve()
{
    cin >> numShows >> numTypes >> dayNums;

    for (int i = 0; i < numShows; ++i)
    {
        cin >> shows[i];
        --shows[i]; // 0-based indexing. The type of the
        // shows will be given as 1-indexed
        /*
16 9 8
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
here, it will be in as 2 0 3 0 4 8 1 5 4 2 4 7 8 6 8 2
I will be simulating this test case for every explanation below
        */
    }

    int uniqueCount = 0;
    for (int i = 0; i < dayNums; ++i)
        if (frequency[shows[i]]++ == 0) // here a post increment
            // logic is working so clever. everytime the if
            // statement is being checked, so no matter what it's
            // true or not, frequency will be updated successfully.
            uniqueCount++;
    // we count the initial unique shows for the first 8 days. which is 7
    int answer = uniqueCount; // we set the answer to that unique
    // count which will be changed later according to the unique
    // count

    // here is the main charisma.now is the time to check the possibility
    // to get less unique number in the range of 8. here the logic of
    // sliding window works but so clever.
    for (int i = dayNums; i < numShows; ++i)
    {
        if (frequency[shows[i]]++ == 0)
            uniqueCount++;
        if (--frequency[shows[i - dayNums]] == 0)
            uniqueCount--;
        // everytime, this frequency[shows[i-daynums]] points as the left
        // range's element's frequency. suppose for the first time, when we
        // start from the i=dayNums, we start from i = 8, so 8-8 means shows[0]
        // we lessen the frequency of shows[0] by one, means we are going
        // forward, like the sliding window. and if we found that it's frequency
        // becomes 0 after the decrement, we simply lessen the unique count and
        // thus, we take the minimum of the answer set beforehand and the
        // uniquecount. the ++ frequency part also works automatically
        // everytime. it's like right++, and the -- part is like left++. sliding
        // window but in a smarter way.
        answer = min(answer, uniqueCount);
    }

    for (int i = numShows - dayNums; i < numShows; ++i)
        --frequency[shows[i]];
    // After processing through the sliding window loop, frequencies of only the
    // last 'dayNums' shows are left incremented since the window never moved
    // past them. So, to reset our frequency array for the next test case, we
    // only need to decrement the frequencies for these shows. This ensures our
    // frequency array is primed and ready for the next test case without
    // carrying over data.

    cout << answer << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> testCases;

    while (testCases--)
        solve();

    return 0;
}
