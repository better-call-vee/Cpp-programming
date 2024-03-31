#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "I am eating rice.";
    string s2 = "I am also eating beef.";

    cout << "String s's size -> " << s.size() << "\n"; // s variable's size

    cout << s[0] << "\n";
    cout << s[1] << s[2] << "\n";
    string s3 = s + s2;
    cout << s3 << endl;

    s.pop_back();
    cout << "deleting the string 's' last character : " << s << endl;

    string s9;
    getline(cin, s9); // taking string input with space
    //    string s10;
    //    cin>>s10; //without space
    s9.erase(s9.begin() + 1);
    s9.erase(s9.begin() + s9.size() - 1); // s9.erase(--s9.end());
    cout << "After erasing second and last character ->" << s9 << endl;
    return 0;
}


//String insert
#include <iostream>
#include <string>
using namespace std;

int main() {
    string originalString = "game";
    char charToInsert = 'b';
    int position = 1; // Position starts at 0, so 1 means the second position

    // Inserting the character
    originalString.insert(position, 1, charToInsert);

    cout << originalString << endl; // This will print "gbame"

    return 0;
}


//String taking with only one character:
#include <iostream>
#include <string>

int main() {
    // Initialize a string with 12 repetitions of 'R'
    std::string str(12, 'R');
    
    // Now, if you want to insert 'b' at the first index (which is index 0)
    char charToInsert = 'b';
    int position = 0; // Choose the position where to insert 'b'
    
    // Inserting the character 'b' at the specified position
    str.insert(position, 1, charToInsert);

    std::cout << str << std::endl; // This will print "bRRRRRRRRRRR"

    return 0;
}
