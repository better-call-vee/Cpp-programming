/**
You'll be given two strings and you have to print the longest common subsequence
between them
EXAMPLES:
abracadabra
avadakedavra
=> aaadara

aa
xayaz
=> aa

axyb
abyxb
=> axb
**/
/*
// BOTTOM UP APPROACH(with recursion)
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int path[1005][1005]; // Array to store the path

string a, b;

int lcs(int x, int y)
{
    if (x == a.length() || y == b.length())
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (a[x] == b[y])
    {
        dp[x][y] = 1 + lcs(x + 1, y + 1);
        path[x][y] = 0; // Choose the diagonal path
    }
    else
    {
        int len1 = lcs(x + 1, y);
        int len2 = lcs(x, y + 1);

        if (len1 > len2)
        {
            dp[x][y] = len1;
            path[x][y] = 1; // Choose the path down
        }
        else
        {
            dp[x][y] = len2;
            path[x][y] = 2; // Choose the path right
        }
    }

    return dp[x][y];
}

string reconstructLCS()
{
    int x = 0, y = 0;
    string result = "";

    while (x < a.length() && y < b.length())
    {
        if (path[x][y] == 0)
        {
            result += a[x];
            x++;
            y++;
        }
        else if (path[x][y] == 1)
            x++;
        else
            y++;
    }

    return result;
}

int main()
{
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    memset(path, -1, sizeof(path));

    int ret = lcs(0, 0);
    string lcsString = reconstructLCS();

    cout << "Length of LCS: " << ret << endl;
    cout << "LCS: " << lcsString << endl;

    return 0;
}*/

// TOP DOWN APPROACH (TABULATION)
/**
 Now I'll discuss the problem intuitively.
 Let's take two strings.
 a = abcdaf
 b = acbcf
 Let's draw the table for the dp
     0   a   b   c   d   a   f
   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╗     if, string a[i] == b[j], then we take the diagonal index's value
 0 ║ 0 ║ 0 ║ 0 ║ 0 ║ 0 ║ 0 ║ 0 ║     and add '1' with it. Suppose, here i=1, j=1 and a[i]=a, b[j]=a .
   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣     a[i]==b[j], so we add 1 with dp[i-1][j-1]'s value which is 0.
 a ║ 0 ║ 1 ║ 1 ║ 1 ║ 1 ║ 1 ║ 1 ║     So, now dp[i][j](where i,j=1) = 1.
   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣     If they don't match, we will take the max of upper and left cell.
 c ║ 0 ║ 1 ║ 1 ║ 2 ║ 2 ║ 2 ║ 2 ║     Look at the i=5, j=3 cell. where a[i]=f, b[j]=c. They didn't
   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣     match. Thus, we took the max of (i-1, j) cell and (i, j-1) cell
 b ║ 0 ║ 1 ║ 2 ║ 2 ║ 2 ║ 2 ║ 2 ║     which is 3.
   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣     We continue doing this.
 c ║ 0 ║ 1 ║ 2 ║ 3 ║ 3 ║ 3 ║ 3 ║
   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╣
 f ║ 0 ║ 1 ║ 2 ║ 3 ║ 3 ║ 3 ║ 4 ║
   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╝
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> dp;
    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    dp.resize(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // we need to print the subsequence. for that we will only take those cells which we increased
    // by 1(which has a match of row and column) eg:i=1, j=1 here
    int x = n;
    int y = m;
    string ans = "";
    while (x > 0 && y > 0)
    {
        if (a[x - 1] == b[y - 1])
        {
            ans += a[x - 1]; // for the very first loop when x = n and y = m. a[x-1] means a[5] = f
            // b[y-1] means b[4] = f. so we take it. and we move our pointer to the diagonal cell
            // by decreasing x and y by 1.
            x--;
            y--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j]) // or if we don't find a match, we take the max
                // of upper or left value. here, if the left value is greater, we move to left. or else
                // we move up(174th line)
                y--;
            else
                x--;
        }
    }

    // finally we print the string.
    cout << ans;
    return 0;
}