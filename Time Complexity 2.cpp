#include<bits/stdc++.h>
using namespace std;

//Time complexity -> O(n^2/2) = O(n^2). Only dominator will stay
//Memory complexity -> O(n)
int main () {
    int n;
    cin>>n;
    vector<int>a(n); //O(n)
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    //i=0 --> 1--n-1 -> n-1
    //i=1 --> 2--n-1 -> n-2
    //i=2 --> 3--n-1 -> n-3
    //i=n-1 --> 0
    //(n-1) + (n-2) + (n-3) + 2 + 1 + 0
    //n*(n-1)/2
    //(n^2-n)/2 --> complexity for this for nested loop

    for(int i=0; i<n; i++) {
        string ans = "NO\n"; //O(1) there's remaining only one string at a time
        for(int j=i+1; j<n; j++) {
            if(i==j) {
                continue;
            }
            if(a[i]==a[j]) {
                ans = "YES\n";
            }
        }
        cout<<"i = "<<i<<" "<<ans;
    }

    return 0;
}
