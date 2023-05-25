#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                char t = st.top();
                if (c == t)
                {
                    st.pop();
                }
                else if ((c == 'R' && t == 'B') || (c == 'B' && t == 'R'))
                {
                    st.pop();
                    if(st.size()>=1 && st.top()=='P') st.pop();
                    else st.push('P');
                }
                else if ((c == 'R' && t == 'G') || (c == 'G' && t == 'R'))
                {
                    st.pop();
                    if(st.size()>=1 && st.top()=='Y') st.pop();
                    else st.push('Y');
                }
                else if ((c == 'B' && t == 'G') || (c == 'G' && t == 'B'))
                {
                    st.pop();
                    if(st.size()>=1 && st.top()=='C') st.pop();
                    else st.push('C');
                }
                else
                {
                    st.push(c);
                }
            }
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}

/**
Problem Statement

Arif, the magician is putting some magic colors in a box serially. But he is not providing any divider between the colors. So, the color may be mix up instantly.

There are three types of colors- Red, Green and Blue. How they could mix up is given below -

Red+Blue = Purple
Red+Green = Yellow
Blue+Green = Cyan
And there are some other problems. If two same type of colors mix up, they will vanish each other. For example if two Purple colors get together, both of them will be vanished.

Can you help the magician to get the final colors that will be in the box?

Input Format

First line will contain T, the number of test cases.
Next line will contain N, number of colors in the box.
Next line will contain N characters (R,G,B only) , first capital letter of the color.
Constraints

0 < T <= 100
0 < N <= 100
Output Format

Output the first capital letter of the colors that are saved finally.
Sample Input 0

2
3
RBG
4
RGBB 
Sample Output 0

PG
Y
Sample Input 1

5
6
RGGRRG
6
RGRGRG
4
RGGR
5
RGGGR
4
RGGB
Sample Output 1

Y
Y

YR
YC
**/
