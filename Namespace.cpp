#include<bits/stdc++.h>
using namespace std;
int x=5, y, z;
int func(int a, int b)
{
    return a+b;
}
//in the namespace std, there is cout declared and many more. if we don't use the
//using namespace, then we have to write std::cout<<...<<
namespace info
{
int x=10;
int y=5;
int func(int a, int b)
{
    return a*b;
}
}
//using namespace Info; //here, it will give error, because x, y and func have been
//declared globally

namespace random
{
void fun()
{
    cout<<"I am random namespace"<<endl;
}
}

using namespace random;  //it can't be use on the upper side

int main ()
{
    int a = 4;
    int b = 5;
    int x = info::func(a, b);
    int y = func(a, b);
    cout<<"namespace version: "<<x<<endl<<"global variable version: "<<y<<"\n";
    fun();
    return 0;
}

//namespace creates a scope for the global variables
