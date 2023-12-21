// https://cses.fi/problemset/task/1619
//more problems: https://github.com/tanvee009/XPSC_ARCHIEVE/tree/main/WEEK%209/Day_1
/*
There will be times when customers will be going in the restaurant at time of 'arrival' and they
will be living the restaurant at time of 'leaving'. We have to output the most number of
customers present in the restaurant at any moment. Which means I have to print the maximum
number of customers present in the restaurant throughout the moments;


here, suppose the test case:
4
1 7
2 4
3 5
8 9
0  1  2  3  4  5  6  7  8  9  10  11  the index numbers
the first customer detail => 1 arrival, 7 depart.
so we will add 1 to the index 1 of the map(we will actually use these 8 indices in the map)
and we will subtract 1 from the index 8 because at that moment that customer won't be there.

after doing all these, finally we do the sum of all the possible customers present at any moment.
and we take the max of them
suppose for this case here, let's simulate:
           🥴  🥴
      🥴  😐   😐  🥴     
  🥴  😐  😉  😉  😉   🥴  🥴   😈   😈   0     0
0  1   2   3    4    5    6    7    8    9    10    11..........10^9
the answer will be 3. 🥴😐😉 were present at the same time 2 times(3, 4)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int t;
    cin >> t;
    map<ll, ll> diff;

    for (int i = 0; i < t; i++)
    {
        int arrival, leaving;
        cin >> arrival >> leaving;

        diff[arrival]++;
        diff[leaving + 1]--;
    }

    ll sum = 0, ans = 0;
    //diff don't represent the actual number of customers in the restaurant at a given time; 
    //instead, they represent the changes in the number of customers from one moment to the next.
    //and here, sum represents the actual number of customers in the restaurant at a given time.
    for (auto go : diff)
    {
        sum += go.second;
        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}