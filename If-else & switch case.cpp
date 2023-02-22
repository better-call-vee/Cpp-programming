#include<bits/stdc++.h>
using namespace std;
int main ()
{
    bool x = true;
    bool y = false;
    if(y || x) cout <<"True"<<endl;
    else cout<<"False\n";
    if(y && x) cout <<"True for and logic"<<endl;
    else cout<<"False for and logic"<<endl;
    //rest are same as the C syntax


    int day;
    cin>>day;
    //switchcase
    //multiple choices but you have to select one
    switch(day) //switch(expression)
    {
    case 3:
        cout<<"Day 3\n";
        break;
    case 5:
        cout<<"Day 5\n";
        break;
    default:
        cout<<"Default\n";
        break;
    }
    return 0;
}
