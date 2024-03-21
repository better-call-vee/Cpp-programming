#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, World!";

    // Using substr with both starting position and length
    string sub1 = str.substr(7, 5); // Extracts "World"

    // Using substr with only the starting position
    string sub2 = str.substr(7); // Extracts "World!"

    cout << "sub1: " << sub1 << endl;
    cout << "sub2: " << sub2 << endl;

    return 0;
}
