//Pair keeps two values together.
//<___ , ___>
//<string , int> like this.
#include<bits/stdc++.h>
using namespace std;

int main () {
    pair<string, int>a;
    a.first = "tanvee";
    a.second = 9;

    cout<<"Pair a = "<<a.first<<", "<<a.second<<"\n";

    pair<int, int>b;
    b.first = 69;
    b.second = 96;

    cout<<"Pair a = "<<b.first<<", "<<b.second<<"\n";
    return 0;
}

///Why do we need pair?
//=> Suppose, we need to sort a vector with keeping index informations.
//{3,4,1,2,6} => {3,0}, {4,1}, {1,2}, {2,3}, {6,4}
//we will only work on the first part and sort the vector.
