/*
In this problem, I will be given a sentence and I have to just make a specific word/phrase censored.
Suppose, a sentence is "Do it now, sometimes later becomes never" and I have been asked to make 'never'
censored. The output will be: Do it now, sometimes later becomes *****
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void censorWord(string &sentence, const string &word) // receiving the strings for our operations. But
// we are taking the string 'word' as constant because it can't be changed.
{
    string censoredWord(word.length(), '*'); // we are taking a new string with the same length of
    // the passed 'word' string which is the targetted word/phrase to censor and the string contains
    // only one distinct character that's '*'.

    // Look, the targetted censored word can be present in the main string with capital letters/
    // mixture of capital/small letters. Therefore, we will take a new string which will be the
    // same as the main string but we will convert it to a all small letters string.
    string lowercaseSentence = sentence;
    transform(lowercaseSentence.begin(), lowercaseSentence.end(), lowercaseSentence.begin(), ::tolower);
    // here is the syntax to convert it to a all lower characters string.

    size_t pos = 0; // The size_t type is guaranteed to be able to represent the size of any object in
    // memory.

    // next we are assigning the pos to the result of 'lowercaseSentence.find(word)', which searches
    // for the occurence of 'word' within the string. If 'word' is found, 'find' returns the
    // index(position) of the first occurence. If 'word' is not found, it returns a special value
    //'string::npos' (which is typically defined as -1 or a maximum value). We are running the while
    // loop until the pos is not becoming 'string::npos'
    while ((pos = lowercaseSentence.find(word, pos)) != string::npos)
    {
        // if we find the position, we just replace the phrase/word with the length of 'word'
        // with the randomly taken '*' consisting string.
        sentence.replace(pos, word.length(), censoredWord);

        // Next we move the position to the end of the replaced word because there can be same
        // word present in the string. So, we search again.
        pos += censoredWord.length();
    }
}

int main()
{
    string sentence, censor;

    cout << "Enter a sentence: ";
    getline(cin, sentence); // taking the inputs with getline because the sentence can contain
    // spaces.

    cout << "Enter the censored word: ";
    getline(cin, censor);

    censorWord(sentence, censor); // passing the parameters to the function.3

    cout << "\n\nCensored sentence: " << sentence << endl;

    return 0;
}
