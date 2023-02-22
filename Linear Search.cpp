//Linear search time complexity O(n).
//we can say upper bound O(n^2). it's okay but technically/theoritically, not practically
//but we will only give the tight upper bound

#include<bits/stdc++.h>
using namespace std;
int main () {
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        if(a[i] == k) {
            cout<<"YES\n";
            cout<<a[i]<<"\n";
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i] == k) {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
