#include <iostream>
#include <algorithm>
using namespace std;

// Function to handle each test case
void run_case()
{
    int N;
    cin >> N;
    int best = 0; // To keep track of the best cost

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

    cout << best << '\n'; // Print the result
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // Optimize input and output

    int tests;
    cin >> tests; // Read the number of test cases

    // Run each test case
    while (tests-- > 0)
    {
        run_case();
    }

    return 0;
}
