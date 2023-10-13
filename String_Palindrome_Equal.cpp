#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp;
    cin >> inp;
    int n = inp.size();

    if (equal(inp.begin(), inp.begin() + inp.size() / 2, inp.rbegin()))
    {
        cout << "Palindrome\n";
        return 0;
    }

    cout << "Not Palindrome\n";
}