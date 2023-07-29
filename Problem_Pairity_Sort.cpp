// https://codeforces.com/contest/1851/problem/B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> ps(n);

        for (int i = 0; i < n; i++)
        {
            cin >> ps[i];
        }

        vector<int> evenElements, oddElements;

        for (int i = 0; i < n; i++)
        {
            if (ps[i] % 2 == 0)
                evenElements.push_back(ps[i]);

            else
                oddElements.push_back(ps[i]);
        }

        sort(evenElements.begin(), evenElements.end());
        sort(oddElements.begin(), oddElements.end());

        int evenIndex = 0;
        int oddIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (ps[i] % 2 == 0)
            {
                ps[i] = evenElements[evenIndex];
                evenIndex++;
            }
            else
            {
                ps[i] = oddElements[oddIndex];
                oddIndex++;
            }
        }

        bool no = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (ps[i] > ps[i + 1])
            {
                no = true;
                break;
            }
        }

        if (!no)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
