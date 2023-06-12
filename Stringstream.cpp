#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> reverseWords(const string &input)
{
    stringstream ss(input);
    string word;
    vector<string> reversedWords;

    while (ss >> word)
    {
        reverse(word.begin(), word.end());
        reversedWords.push_back(word);
    }

    /*
    Within the while loop, the ss >> word statement extracts a word from the stringstream ss and
    assigns it to the word variable. The extraction operator (>>) reads characters from the
    stringstream until it encounters whitespace, storing the extracted word in the word variable.

For example, if the input sentence is "I love you", during the first iteration of the loop, the
word variable will contain the string "I". In the second iteration, it will contain "love", and
in the third iteration, it will contain "you".
    */

    return reversedWords;
}

int main()
{
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    vector<string> reversed = reverseWords(input);
    cout << "Output: ";

    for (const auto &word : reversed)
        cout << word << " ";

    cout << endl;

    return 0;
}