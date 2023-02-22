#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x, y;
    cin >> x >> y; //>>, this is extraction operator, it is used to take input
    cout << x << " " <<y<<"\n"; //we can use endl instead of "\n".
    //<<, this is insertion, used for output. It means inserting the output in
    //the screen
    char ch;
    float f;
    double d = 10.45635343;
    cin>>ch>>f;
    cout<<ch<<" "<<f<<" "<<fixed<<setprecision(5)<<d<<endl;

//
//    char ary[50]; //getting a string even with space.
//    cin.getline(ary, 50);
//    cout<<ary<<endl;

    string s = "I love Bangladesh ";
    string s2 = "too much";
    s = s+s2; //string concatenation in c++, too easy
    cout<<s<<endl;

    int a = 5;
    float b = static_cast<float>(a);

    int num;
    s = "5";
    stringstream(s) >> num;
    cout<<b<<" "<<num;
    return 0;
}
