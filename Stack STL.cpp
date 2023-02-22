#include<bits/stdc++.h>
using namespace std;
int main () {
    stack<int>st;
    st.push(2);
    st.push(7);
    st.push(8);
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top();
    return 0;
}
