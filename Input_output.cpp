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

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double value = 3.14159265358979323846;

    // With maximum precision
    cout << "With maximum precision: " << setprecision(17) << value << endl;

    // With precision of 3 decimal places
    cout << "With precision of 3: " << setprecision(3) << value << endl;

    // With precision of 5 decimal places
    cout << "With precision of 5: " << setprecision(5) << value << endl;

    return 0;
}
With maximum precision: 3.1415926535897931
With precision of 3: 3.14
With precision of 5: 3.1416

*/

/*
Don't use pow() unless you are bound to use this because sometimes the answer won't be exactly what
 you are expecting, and there will be slight precision errors. For example, it's clear that
 log2(1 << 30) is 30
. But sometimes it may consider it as 29.9999999999999
 and when converting it to int, it will return 29.

Similar to this, as pow() takes double as arguments, pow(5, 2) should return 52=25.00
, but sometimes it may consider it as 24.9999999999999
 and when converting it to int, it will return 24
. You may use round(pow(5, 2)) in this particular case to avoid the precision issue or just brute force.
*/

/*
While comparing two floating point numbers, instead of if (a == b), use if (abs(a - b) < eps) where
 eps = 1e-9 or something similar to avoid precision issues
*/

/*
For ceiling, use (a + b - 1) / b
instead of ceil(a/b)
*/