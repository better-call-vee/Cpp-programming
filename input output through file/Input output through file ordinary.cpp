#include<iostream>
using namespace std;
int main () {
    freopen("input.txt", "r", stdin); //take input in the text file
    freopen("output.txt", "w", stdout);
    string s;
    getline(cin, s); //because, after space line will be broken. this function fix
    //this.
    cout<<s<<endl;
    return 0;
}
