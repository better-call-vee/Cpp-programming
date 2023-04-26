#include <bits/stdc++.h>
using namespace std;

long long countarr[100007], n;
long long dparr[100007];

long long boredom(int i)
{
    if (i < 0)
        return 0;

    if (dparr[i] != -1)
        return dparr[i];

    long long ans = max(boredom(i - 1), boredom(i - 2) + i * countarr[i]);

    dparr[i] = ans;
    return ans;
}

int main()
{

    memset(dparr, -1, sizeof(dparr));
    cin >> n;

    long long maxo = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        countarr[j]++;
        maxo = max(maxo, (long long)j);
    }

    dparr[0] = 0;
    dparr[1] = countarr[1];

    cout << boredom(maxo);

    return 0;
}
