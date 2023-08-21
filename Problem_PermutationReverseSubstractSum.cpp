#include <iostream>
#include <algorithm>
using namespace std;
// UPSOLVING of Another Permutation Problem from codeforces 892 div 2.
/*
I will be given a number, the number will obviously have n! permutations. among them I have to
take a permutation, which will have the maximum sum of it's values*indices - max(values*indices).
input:
5
2
4
3
10
20
output:
2
17
7
303
2529

suppose n = 4. according to the conditions, the permutation will be 1, 2, 4, 3.
1x1 + 2x2 + 4x3 + 3x4 = 29. and substract the max = 29 - (4x3) = 17
like this.
*/

void run_case()
{
    int N;
    cin >> N;
    int best = 0;

    // Iterate through all possible values of r
    for (int r = 1; r <= N; r++)
    {
        int sum = 0, maximum = 0; // Initialize sum and maximum for this permutation

        // Iterate through all elements from 1 to N
        for (int i = 1; i <= N; i++)
        {
            // Calculate the value based on the condition, influenced by r
            int value = i * (N - i < r ? N - r + 1 + N - i : i);

            sum += value;                  // Add the value to the sum
            maximum = max(maximum, value); // Update the maximum value
        }

        // Update the best cost by considering the sum minus the maximum value
        best = max(best, sum - maximum);
    }

    cout << best << '\n';
}

/*
1) Starting Point: You have a sequence of numbers from 1 to N, e.g., for N=6, the sequence is
1,2,3,4,5,6.
2) Introducing Reversal: The idea is to reverse a segment of the sequence starting from a specific index.
The length of this reversed segment is controlled by a parameter r.
3) Choosing r: You experiment with different values of r, starting from 1, to reverse different
segments of the sequence. For example, for r=3, you reverse the last 3 elements, resulting in
1,2,3,6,5,4.
4) Why Reverse?: By reversing a segment, you change the maximum value in the sequence. This change
in the maximum value is key to maximizing the expression, as it impacts both the sum and the
subtraction of the maximum value.
5) Finding the Best r: You try all possible values of r from 1 to N to find the one that gives
the maximum value of the expression. It's like experimenting with different reversal points to
find the best one.
6) Expression Calculation: For each r, you calculate the expression's value using the permutation
formed by the reversal. The expression N − r + 1 + N − i is the mathematical way to perform the
reversal.
7) Visualizing the Process: Think of the sequence as a line of numbers. Choosing r is like picking a
point to start folding the line back on itself. As you increase r, you fold more and more of the line,
reversing different segments.
r=1: No reversal, sequence stays the same.
r=2: Reverse last number, sequence becomes 1,2,3,4,5,6 → 1,2,3,4,6,5.
r=3: Reverse last 3 numbers, sequence becomes 1,2,3,4,5,6 → 1,2,3,6,5,4.
Let's take r=3 and see how the permutation is formed:
For i=1,2,3, the values are 1,2,3 (since N − i ≥ r).
For i=4,5,6, we use the expression N − r + 1 + N − i:
For i = 4 : 6−3+1+6−4=6.
For i = 5 : 6−3+1+6−5=5.
For i = 6 : 6−3+1+6−6=4.   LIKE THIS
r=N: Reverse all numbers, sequence becomes 1,2,3,4,5,6 → 6,5,4,3,2,1.

The solution is like a controlled folding exercise where you experiment with different folding points
(reversal points) to find the one that maximizes the expression. The mathematical part,
N − r + 1 + N − i, is the mechanism to achieve this folding, and the logic of iterating through
r ensures that you explore all possible ways to do it. It's a clever and intuitive way to navigate 
the challenge, ensuring that you find the optimal solution.
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
