#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if(!(cin>>n) || n<=0) {
        cout<<"Invalid input"<<endl;
        return 0;
    }
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int ans = 1;
    for(int i=0 ; i<n-1 ; i++)
        if(a[i]!=a[i+1])
            ans++;
    cout<<ans;
    return 0;
}

