#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string input = "Hello, World!";
    reverse(input.begin(), input.end());
    cout << "Reversed string: " << input << endl;
    return 0;
}
