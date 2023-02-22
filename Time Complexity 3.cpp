//Polynomial complexities -> n^2, n^3
//Exponential time complexities -> 2^n, c^n


//time complexity -> O(2^n)
//Memory complexity -> O(n) . stack is containing n sized memories while returning
#include<bits/stdc++.h>
using namespace std;

int called = 0;
int save[100];
//if answer is saved then, time complexity -> O(n). because every f(n) value will
//be calculated only once.
//memory complexity is also O(n)
int fib(int n)
{
    if(n==0) return 0; //base case
    if(n==1) return 1; //base case
    if(save[n]!=0) return save [n];
    int x = fib(n-1);
    called++;
    int y = fib(n-2);
    called++;
    save[n] = x+y;
    return x+y;
}


int main ()
{

    int n;
    cin>>n;
    cout<<"Fib = "<<fib(n)<<"\n";
    cout<<"Called = "<<called<<"\n";

    return 0;
}

//n-th fibonacci number
//F[0] = 0
//F[1] = 1
//F[2] = F[1] + F[0] = 1+0 = 1
//F[3] = F[2] + F[1] + F[0] = 2+1+0 = 3
//F[i] = F[i-1] + F[i-2]
