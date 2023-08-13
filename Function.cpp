#include <bits/stdc++.h>

using namespace std;

string erase_first_last(string s)
{
    s.erase(s.begin());
    s.pop_back();

    return s; // here, you can return the whole string
}

// void function's mechanism is same buttt...

void erase_first_last2(string &s)
{
    s.erase(s.begin()); // this ampersand s will not only copy but also change the s.
    s.pop_back();       // for void function
    cout << "In function s=" << s << "\n";
}

int main()
{
    string s;
    cin >> s;
    string ans = erase_first_last(s);
    cout << s << endl;
    cout << ans << endl;
    erase_first_last2(s);
    cout << "for second function, in main function, s = " << s << endl;
    return 0;
}

/*
#include <iostream>

void foo(int x) {
    std::cout << "Integer version called with " << x << '\n';
}

void foo(double x) {
    std::cout << "Double version called with " << x << '\n';
}

int main() {
    foo(42);   // Calls the integer version
    foo(3.14); // Calls the double version
}

 function in C++ can be overloaded, meaning that multiple functions with the same name can be 
 defined, as long as they have different parameter types or numbers of parameters. This allows
the same function name to be used for different operations that are conceptually similar.

When you call an overloaded function, the compiler looks at the types and numbers of arguments you've
passed and chooses the version of the function that matches those arguments. If there's no match,
you'll get a compilation error.
*/