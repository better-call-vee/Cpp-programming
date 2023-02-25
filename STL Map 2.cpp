//Here is a problem related to Map STL.

/**
You are given a list of strings. You need to output for each string the previous
index where it appeared. If it didn’t occur previously then output -1. Use STL
Map for this problem.
Input
10
apple          -1
banana         -1
abcd           -1
apple           0
abcd            2
top            -1
abcd            4
abcd            6
apple           3
banana          1
**/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> prev_idx;
    vector<int> indices(n, -1); //initializing all the elements of the vector with -1
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        auto it = prev_idx.find(s); //map function find only works for keys
        if (it != prev_idx.end())
        {
            indices[i] = it->second; //setting the index value to the vector
            //if the string matches any previous key.
        }
        prev_idx[s] = i; //updating that key string's value(indexno.) with i bcz
        //keys can't be duplicate.
    }
    for (int i = 0; i < n; i++)
    {
        cout << indices[i] << "\n";
    }
    return 0;
}

