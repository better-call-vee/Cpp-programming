/*
STATEMENT:
Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games. One long winter
evening he came up with this game and decided to play it.

you will be given n number of integers.
3                                    9
1  2  3                              1  2  1  3  2  2  2  2  3
like this. 

The first line contains integer n (1 ≤ n ≤ 10^5) that shows how many numbers are in the sequence.
The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^5).
you can take steps and every step will give you point. suppose every integer value here is 'a'. 
For each step, the 'a' and all the values that are equivalent to a-1 and a+1 will be deleted and
you will get 'a' points. 
You need to find the maximum points Alex can gain from a case.


we have to solve this with bottom-top apporoach
9
1  2  1  3  2  2  2  2  3

0         2          5          1       countarr.     
0         1          2          3
here, if we select 1, we will get max 2 for deleting. 
If we select 2, we can't select 1 and we will get 2*5=10 for deleting.
If we select 3, we can't select 3 and we will get 3*1 + 2 = 5. here we can't select 2 but can select 1.
So, if we select i, we will take the max of i*count[i] + dp[i-2] (i is 3, i-2 will be 1) and dp[i-1]
(if we don't select 3 and if we select 2).
Here, dp[i-1] is greater so we will select 2 and thus we will get our answer 10.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 7;

vector<int> countarr(MAX_N, 0);
vector<long long> dparr(MAX_N, -1);

long long boredom(const int i) /* the value of the parameter i is not changed within the function.The i
 parameter is only used to compute the result of the function by recursively calling itself with i-1
 and i-2. Declaring i as a const int parameter helps to ensure that the value of i is not accidentally
 modified within the function. It also improves readability and conveys the fact that i is not intended
 to be modified.*/
{
    if (i <= 0)
        return 0;

    if (dparr[i] != -1)
        return dparr[i];

    long long ans = max(boredom(i - 1), boredom(i - 2) + (long long)i * countarr[i]);
    //in max function, you need compare among same type variables

    dparr[i] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int maxo = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        countarr[j]++;
        maxo = max(maxo, j);
    }

    dparr[0] = 0;
    dparr[1] = countarr[1];

    cout << boredom(maxo);

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

long long countarr[100007], n;
long long dparr[100007];

int main()
{
    memset(countarr, 0, sizeof(countarr));

    cin >> n;
    int maxo = 0;

    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        countarr[j]++;
        maxo = max(maxo, j);
    }

    dparr[0] = 0;
    dparr[1] = countarr[1];

    for (int i = 2; i <= maxo; i++)
    {
        dparr[i] = max(dparr[i - 1], dparr[i - 2] + i * countarr[i]);
    }

    cout << dparr[maxo];

    return 0;
}
*/