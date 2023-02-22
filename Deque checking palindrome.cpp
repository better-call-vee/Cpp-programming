
#include<bits/stdc++.h>
using namespace std;
int main () {
    string pendu;
    cin>>pendu;
    deque<char>VAR;
    for(int i=0; i<pendu.size(); i++) {
        VAR.push_back(pendu[i]);
    }
    for(int i=0; i<pendu.size()/2; i++) {
    //For strings with odd length, the middle element does not affect the result
    //of the palindrome check.
        if(VAR.front()!=VAR.back()) {
            cout<<"No";
            return 0;
        }
        VAR.pop_front();
        VAR.pop_back();
    }
    cout<<"Yes";
    return 0;
}
