//all the loops are same for both c and c++
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int i=5;
    do
    {
        cout<<i<<endl; //for do while loop, condition gets applied in the end.
    }while (i<5);

    for(int j=0; j<5; j++)
    {
        cout<<"Hello\n";
        if(j==3) continue; //continue ignores the specific i
        cout<<j<<endl;
    }
    return 0;
}
