//3! = 2!*3
#include<bits/stdc++.h>
using namespace std;

int factorial (int n)
{
    if(n==0) return 1;
    return factorial(n-1)*n; //suppose, n=3.
    //first call => (3-1)=2. so here, first call will wait for the return of 2.
    //but as, 2 doesn't equal to 0. it will be called again. it will be 1 and will
    //wait for the return.
    //1 is also not 0. then it will be 0 and wait for the return. now, the return
    //will be 1 because of reaching the base case on the 6th line.
    //now 1 got it's return, 1 will return 1(n=1) to 2's call. 2 got the return
    //1 and then n=2, 2*1 will be 2. now this 2 will be returned to the very first
    //call. here we go, we got the main return which is 2, now it will be multiplied
    //by main n=3, answer will be 6.
}

int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}
