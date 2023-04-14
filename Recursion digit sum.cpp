#include<bits/stdc++.h>
using namespace std;

int digitsum(int n)
{
    if(n < 10) return n;
    return n % 10 + digitsum(n/10);
}

int main ()
{
    int n;
    cin >> n;
    cout << digitsum(n);
    return 0;
}

