#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    set<int> s1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.insert(x);
    }

    cin >> m;
    set<int> s2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        s2.insert(x);
    }

    set<int> union_set;
    for (int x : s1)
    {
        union_set.insert(x);
    }
    for (int x : s2)
    {
        if (union_set.find(x) == union_set.end())//if the element is distinct or not
        {
            union_set.insert(x);
        }
    }

    for (int x : union_set)
    {
        cout << x << " ";
    }

    return 0;
}

