#include<bits/stdc++.h>
using namespace std;
int main () {
    string s = "I am eating rice.";
    string s2 = "I am also eating beef.";

    cout<<"String s's size -> "<<s.size()<<"\n"; //s variable's size

    cout<<s[0]<<"\n";
    cout<<s[1]<<s[2]<<"\n";
    string s3 = s + s2;
    cout<<s3<<endl;

    s.pop_back();
    cout<<"deleting the string 's' last character : "<<s<<endl;

    string s9;
    getline(cin, s9); //taking string input with space
//    string s10;
//    cin>>s10; //without space
    s9.erase(s9.begin()+1);
    s9.erase(s9.begin()+s9.size()-1); //s9.erase(--s9.end());
    cout<<"After erasing second and last character ->"<<s9<<endl;
    return 0;
}
