//decimal to binary
//1  ->  1
//2  ->  10
//3  ->  11
//4  ->  100
//5  ->  101
//6  ->  110
//7  ->  111

//suppose a queue, q. pushing 1. q[1], decimal's 1 and binary's 1 are the same.
//we will pop out 1 and print. then we will push the same element's
//two versions but with adding 0 and adding 1 with the element.
//now we will push 10 and 11. then when 10 will be popped and printed, we will
//push 100 and 101. and we will continue like this.

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    queue<string>q;
    q.push("1"); //q's front is i's binary representation. so, we need to
    //set the front to 1 before entering the loop where i will be 1.
    for(int i=1; i<=n; i++)
    {
        cout<<"BINARY REPRESENTATION OF "<<i<<": "<<q.front()<<"\n";
        string tmp = q.front();
        q.pop();
        q.push(tmp+"0");
        q.push(tmp+"1"); //we need string for these
    }
    return 0;
}

//A byte is made up of 8 binary digits, also known as bits. These 8 bits can
//represent an integer value ranging from 0 to 255 in decimal representation, or
//from 00000000 to 11111111 in binary representation.
