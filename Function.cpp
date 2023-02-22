#include<bits/stdc++.h>

using namespace std;

string erase_first_last(string s) {
    s.erase(s.begin());
    s.pop_back();

    return s; //here, you can return the whole string
}

//void function's mechanism is same buttt...

void erase_first_last2(string &s) {
    s.erase(s.begin()); //this ampersand s will not only copy but also change the s.
    s.pop_back();   //for void function
    cout<<"In function s="<<s<<"\n";
}

int main () {
    string s;
    cin>>s;
    string ans = erase_first_last(s);
    cout<<s<<endl;
    cout<<ans<<endl;
    erase_first_last2(s);
    cout<<"for second function, in main function, s = "<<s<<endl;
    return 0;
}
