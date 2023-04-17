/*

# Tabulation-Method (iterative)

main() {
    //1. handle base case
    //2. loop through the states 
        2.1. Calculate the answer from smaller subproblems
}

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
long long dp[N];
int main () {

    int n;
    cin >> n;

    dp[1] = 1;     //base case
    dp[2] = 1;     //base case

    //loop through the states
    for(int i=3; i<=n; i++) {
        //Calculate the answer from smaller subproblems
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<"\n";

    return 0;
}