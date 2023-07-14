#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/problems/ALTTAB
typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;
    /*
    here in this problem, look at the bold words/phrase first. why do we use alt+tab? to restore recently
    closed items. Here I have to print output just like that. The last opened item first, then goes on.
    But I have to avoid once printed item.
    */
    int n;
    cin >> n;
    stack<string> items;

    while (n--)
    {
        string s;
        cin >> s;
        items.push(s);
    }

    map<string, bool> dupli;

    while (!items.empty())
    {
        if (!dupli[items.top()])
        {
            cout << items.top().substr(items.top().size() - 2); 
            dupli[items.top()] = true;
        }
        items.pop();
    }

    return 0;
}

/*
items.top().size() - 2 calculates the index of the second-to-last character in the string items.top().
The substr function is then used to extract the substring starting from that index until the end of 
the string.

generally substr has two parameters. starting and length(suppose, sonnet. I want nn. start = 2, length = 2)
string word = sonnet;
stirng printsub = word.substr(2, 2);
=> nn;
*/