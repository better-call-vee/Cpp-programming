/**
Here, for the palindrome, we need to have a equal value for the first and the last
character of a string and it's substrings.
Well, let's follow the steps.
So, here the smaller problem is an empty string or a string containing only one
character. if one character, it will be an automatic palindrome.
and every time, we will eradicate two elements. one from the front, other from
back and check if the front and back is equal or not!
**/

#include<bits/stdc++.h>
using namespace std;

bool ispal(string str) {
    if(str == "" || str.size()==1) { //checking the base case. if the string
    //contains a letter only or the string is empty, will return true then.
        return true;
    }
    int n = str.size();
    string smallstr = str.substr(1, n-2); //here, the first and the last element
    //of the string is being eradicated and getting a substring to launch the
    //recursion
    return ispal(smallstr) && (str[0] == str.back()); //everytime checking if the
    //front and back are equal or not
}

int main () {
    string inp;
    cin>>inp;
    if(ispal(inp)) cout<<"YES IT'S A PALINDROME";
    else cout<<"AH-HA, crap";
    return 0;
}
/**
example:
level
passes the base case. small string will be eve. we call again ispal and give input
eve. ispal(eve). we get to call again ispal(v). this time it can't pass the base
case haha, bingo. we get true in return to the call ispal(eve) and eve's front and
back are also equal, so we return to ispal(level) call with a true return.
in the end, we get true, that's what we want mofo!


abcbd
for this, the small substrings will return true, but in the end, it will false
just because a!=d.
**/
