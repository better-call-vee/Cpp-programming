/*
Determine if a given string is:
Not a palindrome.
A regular palindrome (reads the same forwards and backwards).
A mirrored string (reads the same forwards and backwards when each character is replaced by 
its mirrored counterpart).
A mirrored palindrome (both a regular palindrome and a mirrored string).
Valid characters and their mirrored counterparts are provided 
(e.g., 'A' is mirrored by 'A', '3' is mirrored by 'E', etc. follow the map).

NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
3AE
JOLLY
12321
1S2E3
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp;
    map<char, char> mirror;
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['3'] = 'E';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['2'] = 'S';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['5'] = 'Z';
    mirror['1'] = '1';
    mirror['8'] = '8';

    while (cin >> inp)
    {
        string rev = inp;
        reverse(rev.begin(), rev.end());

        bool palindrome = (rev == inp);

        bool revstr = true;
        for (int i = 0; i < inp.size(); i++)
        {
            if (mirror.find(inp[i]) == mirror.end() || mirror[inp[i]] != rev[i])
            {
                revstr = false;
                break;
            }
        }

        cout << inp;
        if (palindrome && revstr)
            cout << " -- is a mirrored palindrome.\n";
        else if (palindrome)
            cout << " -- is a regular palindrome.\n";
        else if (revstr)
            cout << " -- is a mirrored string.\n";
        else
            cout << " -- is not a palindrome.\n";

        cout << "\n";
    }

    return 0;
}
/*
mirror.find(inp[i]) == mirror.end() checks if inp[i] is not a key in the mirror map. The method find
returns an iterator to the found element if it exists, or to mirror.end() if it doesn't. If the
character is not in the map, it means the character does not have a mirrored counterpart or is not
valid for a mirrored string. In this case, the string cannot be a mirrored string.

mirror[inp[i]] != rev[i] checks if the mirrored counterpart of inp[i] (which is mirror[inp[i]]) does not match
the corresponding character in the reversed string (rev[i]). If they don't match, then the string is
not a mirrored string.
*/