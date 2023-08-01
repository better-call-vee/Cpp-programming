#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    string inp;
    getline(cin, inp);

    stringstream RU(inp);

    string word;
    vector<string> out;

    while (RU >> word)
    {
        for (char &c : word)
            c = toupper(c);
        out.push_back(word);
    }

    reverse(out.begin(), out.end());
    for (auto str : out)
        cout << str << " ";

    return 0;
}

// this program converts a given string into a reversed capital lettered string.

/*
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;

    int x = 10;
    double y = 3.14;
    std::string name = "Alice";

    ss << "x = " << x << ", y = " << y << ", name = " << name;

    std::string result = ss.str(); // Extract the content of stringstream as a string
    std::cout << result << std::endl;

    return 0;
}


here, stringstream is being constructed as first by 49th line. and then result is being set by
ss.str(). and finally it is being printed as a whole string.
*/