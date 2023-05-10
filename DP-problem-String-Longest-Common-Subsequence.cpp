/*
It's a problem to find the longest common subsequence among given strings.
suppose, two strings have been given to you.
axyb
abyxb
here, the longest common subsequence are axb/ayb=3
we can't take axyb. look y is present both in axyb and abyxb.
BUT, we can't take the y from the 2nd string. Once we choose x/b, we can't take y by going behind
We have to maintain the sequence.

ahgu
abyhoggui
output will be 4(ahgu)

Brute Force Simulation:
                ⬇     -
⬇           ⬇    c  ↗ by(stop)
ayc   +1    yc↗ by  ↘ c   -       c          (s string)
    ----->            y ↗ y  and  -(stop)
aby         by↘ yc                           (t string)
⬆           ⬆    y ++1-> c
                 ⬆       - (stop)
here, at first the pointers are at the first character of the strings. Now we will check if they
are equivalent or not. If yes, then we will omit them both and move forward else we will divide them
into two new parts(first part will be got by only moving the upper pointer and the second part will
be got by only moving the lower pointer)
We will stop if any of the two stirngs becomes empty

Let's write the pseudocode:
LCS(i, j) {
    if(i==s.size() or j==t.size()) return 0   #when we will reach to end of the string with the pointers
    if(s[i] == t[j]) return 1+LCS(i+1, j+1)   #when the pointed characters are equivalent
    else{
        return max of{LCS(i+1, j), LCS(i, j+1)} #when the pointed characters are not equivalent
    }
}

Now let's simulate a different pair of strings:
    0   1   2           0   1   2
  ╔═══╦═══╦═══╗       ╔═══╦═══╦═══╗          We will call with LCS(0,0)
 s║ a ║ b ║ y ║      t║ b ║ x ║ y ║
  ╚═══╩═══╩═══╝       ╚═══╩═══╩═══╝
                                    (0, 0) = 2
          __________________________|     ↘
          ⬇                              (0, 1) =  1
     {2}(1, 0)                           ↙   ↘
          ⬇+1                       (1,1)      (0,2)--(1,2) (look it was previously calculated)
        (2, 1)=1                    ↙   ↘          ↘
       ↙     ↘                 (2,1)     (1,2)      (0,3)=0
  0=(3,1)    (2,2)=1           ↙   ↘      ↙   ↘
               ⬇+1           (3,1) (2,2) (1,3) (2,2)
           0=(3,3)                   ⬇           ⬇
                                   (3,3)        (3,3)

Here, we will see that we've done many redundant works(2,1), (1,2) !
We can avoid doing these if we follow DP method. Otherwise the time complexity will be O(2^n).
With DP we can make it O(i*j)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int n, m;
string s, t;

int LCS(int i, int j)
{
    if (i == n or j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        int ans = 1 + LCS(i + 1, j + 1);
        dp[i][j] = ans;
        return ans;
    }
    else
    {
        int ans1 = LCS(i + 1, j);
        int ans2 = LCS(i, j + 1);
        int ans = max(ans1, ans2);
        dp[i][j] = ans;
        return ans;
    }
}

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    dp.resize(n, vector<int>(m, -1));

    int result = LCS(0, 0);
    cout << "THE LONGEST COMMON SUBSEQUENCE BETWEEN THESE TWO STRINGS = " << result;

    return 0;
}