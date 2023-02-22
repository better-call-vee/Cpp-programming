#include<bits/stdc++.h>
using namespace std;

//will delete only the first occurance of the value.

void deleteValue(list<int> &l, int value)
{
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (*it == value)
        {
            l.erase(it);
            break;
        }
    }
}

int main()
{
    int n, value;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    list<int> l;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    cout << "Enter the value to delete: ";
    cin >> value;

    cout << "Before deletion: ";
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << "\n";

    deleteValue(l, value);

    cout << "After deletion: ";
    for (auto i : l)
    {
        cout << i << " ";
    }
    return 0;
}

