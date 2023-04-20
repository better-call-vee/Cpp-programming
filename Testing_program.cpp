#include<bits/stdc++.h>
using namespace std;

const int n = 31;
int fibcheck[n];

int memofib(int nth)
{

    if(nth==0) return 0;
    if(nth<=2) return 1;

    if(fibcheck[nth] != -1) return fibcheck[nth];

    int ans = memofib(nth-1) + memofib(nth-2);
    fibcheck[nth] = ans;
    return ans;

}

int main ()
{

    int th_fib;
    cin >> th_fib;

    memset(fibcheck, -1, sizeof(fibcheck));

    fibcheck[0] = 0;
    fibcheck[1] = 1;
    fibcheck[2] = 1;

    for(int i=3; i<=n; i++)
    {
        fibcheck[i] = fibcheck[i-1] + fibcheck[i-2];
    }

    cout<<"Memorization Output => "<<memofib(th_fib)<<"\n";
    cout<<"Tabulation Output => "<<fibcheck[th_fib];

    return 0;
}
