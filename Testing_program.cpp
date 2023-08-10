/*
   +----------------------+
  /                        \
 /    *   TANVEE009   *     \
 \  **  I CAN, I WILL  **   /
  \  +-----------------+   /
   +----------------------+
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define line cout << '\n';
const string nln = "\n";

int main()
{
    fast;
    int n, k;
    cin >> n >> k;

    int score, kth_score = 0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> score;

        if (i <= k)
            kth_score = score;

        if (score >= kth_score && score > 0)
            count++;
    }
    cout << count << nln;
    
    return 0;
}
