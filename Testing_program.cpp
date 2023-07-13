#include <iostream>
using namespace std;

bool canMakePalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            // Check if deleting a character results in a palindrome
            if (s[start] == s[end - 1])
                end -= 2;
            else if (s[start + 1] == s[end])
                start += 2;
            else if (s[start + 1] == s[end - 1])
                start += 2;
            else
                return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        if (canMakePalindrome(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
