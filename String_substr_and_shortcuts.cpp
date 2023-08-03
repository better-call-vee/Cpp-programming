#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int t, n, i, check;
string inp;

int main()
{
    fast;

    for (cin >> t; t--; cout << (check ? "YES\n" : "NO\n")) // here we use it for test case.
    // if check is true, then we print yes, else no.
    {
        cin >> n >> inp;
        for (int i = check = 0; i < 5; i++) // running a loop till 4. because 2020 is 4 lengthed.
            if (inp.substr(0, i) + inp.substr(n - 4 + i, 4 - i) == "2020")
                check = 1;
        /*
        everytime, we check if we can make 2020 by performing only one deletion or less than that.
        Input: 20192020
        i varies from 0 to 4 in the loop. The substrings at each iteration and their concatenation are
        as follows:
        i	s.substr(0, i)	 s.substr(n - 4 + i, 4 - i)	  Combined
        0	   ""	                  "2020"	           "2020"
        1	   "2"	                  "020"	               "2020"
        2	  "20"	                  "20"	               "2020"
        3	  "201"                   "0"	               "2010"
        4	  "2019"	              ""	               "2019"
        */
    }

    return 0;
}

/*
I will be given a string as input and I have to output YES or NO based on:
1) if 2020 is present in the string,
2) or if it's possible to make it 2020 by only perfoming one deletion step of a substring.

suppose, 20193020. here it's possible to make 2020 by deleting 0193 or, 1930.
*/