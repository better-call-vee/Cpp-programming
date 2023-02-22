
//array memory allocation concept:
//*a = a[]                   00 04 08 12 16 20 24 28
//suppose a stack of memory.  _  _  _  _  _  _  _  _
//if we declare an array a[5], it will take any 5 sequential space from here.
//let's take 04 to 20. and the other spaces either contain garbage value or owned
//by others and will show error if owned by others.

#include<bits/stdc++.h>
using namespace std;
int main () {
    int a[5] = {1, 2, 4, 5, 6};
    cout<<a<<"\n"; //starting position.
    cout<<(a+1)<<"\n";
    cout<<(a+2)<<"\n"; //these will print the memory locations
    cout<<(a+3)<<"\n";
    cout<<(a+4)<<"\n";

    cout<<(a+5)<<"\n"; //this memory is accessed as garbage value
    cout<<a[5]<<"\n";
    //memory is printed in hexadecimal format

    return 0;
}
