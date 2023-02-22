#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    vector<int>THEDUDE(n);
    for(int i=0; i<n; i++)
    {
        cin>>THEDUDE[i];
    }
    sort(THEDUDE.begin(), THEDUDE.end());
    THEDUDE.erase(unique(THEDUDE.begin(), THEDUDE.end()), THEDUDE.end());
    for(int i=0; i<THEDUDE.size(); i++)
    {
        cout<<THEDUDE[i]<<" ";
    }
    return 0;
}
