#include<bits/stdc++.h>
using namespace std;

bool penduVAR(string tapin, int gear, int stop)
{
    if(gear>=stop) return true;
    else if(tapin[gear]!=tapin[stop]) return false;
    else penduVAR(tapin, gear+1, stop-1);
}

int main ()
{
    string pendu;
    cin>>pendu;
    int n = pendu.size()-1;
    if(penduVAR(pendu, 0, n)) cout<<"YES";
    else cout<<"NO";
    return 0;
}

