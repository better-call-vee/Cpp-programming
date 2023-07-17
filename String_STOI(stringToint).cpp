//https://www.codechef.com/problems/DDMMORMMDD

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string date, f2, s2;
        cin >> date;

        f2 = date.substr(0, 2); //taking a substring of specific length.
        s2 = date.substr(3, 2);

        int f2n = stoi(f2); //converting the string into integer.
        int s2n = stoi(s2);

        if (f2n > 12 && s2n <= 12)
            cout << "DD/MM/YYYY\n";
        else if (f2n <= 12 && s2n > 12)
            cout << "MM/DD/YYYY\n";
        else if (f2n <= 12 && s2n <= 12)
            cout << "BOTH\n";
    }

    return 0;
}