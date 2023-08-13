#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;                 //>>, this is extraction operator, it is used to take input
    cout << x << " " << y << "\n"; // we can use endl instead of "\n".
    //<<, this is insertion, used for output. It means inserting the output in
    // the screen
    char ch;
    float f;
    double d = 10.45635343;
    cin >> ch >> f;
    cout << ch << " " << f << " " << fixed << setprecision(5) << d << endl;
    // fixed is use for fixing the 5 values after point no matter if the number is a full number
    // or not.
    //
    //     char ary[50]; //getting a string even with space.
    //     cin.getline(ary, 50);
    //     cout<<ary<<endl;

    string s = "I love Bangladesh ";
    string s2 = "too much";
    s = s + s2; // string concatenation in c++, too easy
    cout << s << endl;

    int a = 5;
    float b = static_cast<float>(a);

    int num;
    s = "5";
    stringstream(s) >> num;
    cout << b << " " << num;
    return 0;
}

/*
Set precision

#include <iostream>
#include <iomanip> // for setprecision

using namespace std;

int main() {
    double value = 3.14159265358979323846;

    // Without precision
    cout << "Without precision: " << value << endl;

    // With precision of 3 decimal places
    cout << "With precision of 3: " << setprecision(3) << value << endl;

    // With precision of 5 decimal places
    cout << "With precision of 5: " << setprecision(5) << value << endl;

    return 0;
}

*/