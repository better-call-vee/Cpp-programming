#include <bits/stdc++.h>
using namespace std;

string toLowercase(const string &word) {
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    return lowerWord;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    set<string> uniqueWords;
    string line, word;

    while(getline(cin, line)) {
        stringstream lineStream(line);
        while(lineStream >> word) {
            string filteredWord;
            for(char ch : word)
                if(isalpha(ch)) filteredWord += tolower(ch);

            if(!filteredWord.empty()) uniqueWords.insert(filteredWord);
        }
    }

    for(const string &word : uniqueWords) cout << word << "\n";

    return 0;
}


//this program takes a paragraph as input and outputs all the distinct words in lower
//case.