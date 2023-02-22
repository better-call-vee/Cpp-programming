#include<bits/stdc++.h>
using namespace std;
void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
}

//if we give parameter n=2, then, first it will go into the function because 2>0.
//then it will be printed.then first function(line 8) will be called. that means
//1 will be passed. now 1>0, so 1 will be printed. now again the 8th line fun will
//be called but this time n=0 and it will be now returned to 9th line fun and n=1.
//again it will be 0 and will be returned to 9th line fun but n=2. here, 1 will be
//printed and again 1 will be called for 8th line fun but will be terminated because
//1-1=0.
//so, eventually 2 1 1 will be printed

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    fun(n);
    return 0;
}
