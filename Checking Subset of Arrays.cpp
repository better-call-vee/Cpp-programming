#include<bits/stdc++.h>
using namespace std;

bool checkSUBarr(int a[], int b[], int m, int n)
{
    sort(a, a+m); //sorting the array 1
    sort(b, b+n); //sorting the array 2
    int i = 0, j = 0;
    while (i < m && j < n) //checking until the last element of the 2 arrays
    {
        if (a[i] == b[j]) i++; //suppose, the first array which is being checked
//as a subset is [5, 2]. and the array b is [7, 5, 3]
//sorted => a[2, 5]. b[3, 5, 7]
//a[0] with b[0] checking 2!=3. so j++. now, a[0] with b[1]: 2!=5. so, j++;
//again, a[0] with b[2] but 2!=7. it will be false for (i==m) and return false.
        else j++;
    }
    return (i == m);
}

int main()
{
    int m, n;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    if (checkSUBarr(a, b, m, n))
    {
        cout <<"YES";
    }
    else
    {
        cout <<"NO";
    }
    return 0;
}

