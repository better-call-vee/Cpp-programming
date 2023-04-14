/**
You are given a string s  of small letters. You can reorder or rearrange the
characters of that string in any order or any way. You have to determine whether
you can build any valid palindrome from that string.Print “YES” if you can
otherwise print “NO”.

Note - A palindrome is a number or string that reads the same backwards as
forwards

Write a C++ program to solve this problem.
Sample Input 1 -								Sample Output 1-

babdakkiikkii	  								YES

Sample Input 2 -								Sample Output 2-

abbfkbifkppkplab							    NO

**/

/**
#include<bits/stdc++.h>
using namespace std;

int main ()
{

    string input;
    cin >> input;

    bool penduVAR = true;
    char check = '\0';

    int sz = input.size();


    for(int i=0; i<input.size(); i++)
    {
        char l = input[i];
        for(int j=i+1; j<input.size(); j++)
        {
            if(l == input[j])
            {
                input.erase(i, 1);
                input.erase(j-1, 1);
                break;
            }
            if(l!=input[j] && j==input.size()-1)
            {
                if(sz%2==0)
                {
                    penduVAR = false;
                    break;
                }
                else if(sz%2!=0)
                {
                    if(check == '\0')
                    {
                        check = l;
                        break;
                    }
                    else
                    {
                        penduVAR = false;
                        break;
                    }

                }

            }
        }
        if(!penduVAR) break;
    }

    if(penduVAR) cout << "YES";
    else cout << "NO";

    return 0;
}
**/

//if a string contains more than one oddcount, it can't be a palindrome ever.

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string input;
    cin >> input;

    int freq[26] = {0};
    int oddCount = 0;

    for(int i=0; i<input.size(); i++)
    {
        freq[input[i]-'a']++;
    }

    for(int i=0; i<26; i++)
    {
        if(freq[i]%2!=0)
        {
            oddCount++;
        }
    }

    if(oddCount>1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}

