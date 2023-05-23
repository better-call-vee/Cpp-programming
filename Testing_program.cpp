#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> roads;
int K;
vector<int> visited1;
vector<int> visited2;
vector<int> children;
vector<int> children2;

bool RomJul(int source, int source2)
{
    visited1[source] = 1;
    visited2[source2] = 1;

    children.push_back(source);
    children2.push_back(source2);

    int z = 1;

    while (true)
    {
        if (z > K)
            break;

        int sz = children.size();

        for (int i = sz - 1; i >= 0; i--)
        {
            for (int child : roads[children[i]])
            {
                if (visited1[child] != 1)
                {
                    visited1[child] = 1;
                    children.push_back(child);
                }
            }
            children.erase(children.begin() + i);
        }

        int sz2 = children2.size();

        for (int i = sz2 - 1; i >= 0; i--)
        {
            for (int child : roads[children2[i]])
            {
                if (visited2[child] != 1)
                {
                    visited2[child] = 1;
                    if (visited1[child] == visited2[child])
                        return true;
                    children2.push_back(child);
                }
            }
            children2.erase(children2.begin() + i);
        }
        z++;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, X, Y;
    cin >> N >> E;

    visited1.resize(N + 1);
    visited2.resize(N + 1);
    roads.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int X, Y;
        cin >> X >> Y;
        roads[X].push_back(Y);
        roads[Y].push_back(X);
    }

    cin >> X >> Y >> K;

    if (RomJul(X, Y))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
