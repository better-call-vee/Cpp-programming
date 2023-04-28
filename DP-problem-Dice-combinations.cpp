/*
You will be given an integer number(n) and you have a dice of 6 sides.
You can make combinations to make the given integer number.
Suppose, you are given an integer number '3'
the combinations will be:
1+1+1
2+1
1+2
3
there are 4 combinations.
like this.

okay, now n=2.
            2
          /   \
        1       2
      (1)        (0) (if we select 1, we need 1 to reach the given number. if we select 2, we need 0)
     /
   (0) (then we are selecting 1 again, we need 0 now for this case)

now, n=3
                               3
                           /   |   \
                          1    2    3
                        (2)   (1)   (0)
                       /       |             here, we can find 4 combinations.
                      1        1
                    (1)       (0)
                    /
                   1
                  (0)
for(1-->6)
1=>1
2=>2
3=>4               the pattern is 2^(n-1)
4=>8
5=>16
6=>32

for 3 => if we just calculate combination(2) + combination(1) + 1, we will get the result which is 4.
for 4 => combination(3)+c(2)+c(1)+1 => 4+2+1+1 => 8
for 5 => c(4)+c(3)+c(2)+c(1)+1 => 8+4+2+1+1 => 16

Each time while throwing the dice, we have 6 options from 1 to 6.
suppose the case is n=8.
                     8 (n)
            _________|_________
           /   /   |   |   \   \
          1   2    3   4    5   6    (i)
        (7)  (6)  (5) (4)  (3)  (2)   look here, for each possibility we have n-i options left.
                                      now these (i)s will be the (n)s and we will get again the
                                      options. It will be continued until we get 0(previously shown)
*/

// Memorization
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[N];

int solve(int n)
{

    // if (n == 0)
    //     return 1;     this is the base case. We can only write this instead of writing 90-91th lines

    if (dp[n] != 0)
        return dp[n];

    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        { // suppose the n is 2, we won't get the options for possibilities
            // more than 2. if n=2, we can't take dice possibilities 3->6.
            dp[n] += solve(n - i);
            dp[n] %= mod; // they asked to Print the number of ways modulo 10^9+7(cses)
        }
    }
    return dp[n];
}

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= 6; i++)
        dp[i] = pow(2, i - 1);

    cout << solve(n) << "\n";

    return 0;
}

/* Tabulation
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

vector<int> dp(N, 0);

int main()
{
    int n;
    cin >> n;

    dp[0] = 1; // base case
    // there is one way to obtain a sum of 0 using the given dice, which is to use no dice at all.
    // This corresponds to an "empty" combination and is counted as a valid combination.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && j <= i; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
*/