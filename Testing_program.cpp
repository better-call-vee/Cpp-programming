#include <bits/stdc++.h>
using namespace std;

long long powpow (int num, int pw)
{
    if(pw==1) return num;
    int pro = num*powpow(num, pw-1);
    return pro;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout<<powpow(n,p);
    return 0;
}
