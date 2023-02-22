//#include<iostream>
//#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double l= 3.447444;
    //rounding double in c++
    cout<<setprecision(2)<<fixed<<l<<endl;

    ofstream of;
    of.open("1.txt");
    ofstream of2;
    of2.open("2.txt");
    of<<"hello world\n";
    of2<<"Hello OF2\n";

    ifstream ifs;
    ifs.open("0.txt");
    int x;
    double y, z;
    ifs>>x>>y>>z;
    cout<<x<<" "<<y<<" "<<z<<"\n";

    return 0;
}
