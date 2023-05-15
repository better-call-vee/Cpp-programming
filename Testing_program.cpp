#include <bits/stdc++.h>
using namespace std;
int n;
int x;

int BFS(int src)
{
    queue<long long> q;
    q.push(src);
    map<long long, int> m;
    m.insert({src, 0});
    int cnt = 0;
    while (!q.empty())
    {
        long long head = q.front();
        q.pop();
        string s = to_string(head);

        if (s.size() == n)
            return m[head];

        for (auto digit : s)
        {
            int x = digit - '0';

            if (x == '0')
                continue;

            long long newNumber = x * head;
            int f = 0;

            map<long long, int>::iterator it = m.begin();
            for (; it != m.end(); ++it)
            {
                if (it->first == newNumber)
                {
                    f = 1;
                    break;
                }
            }

            if (f == 0)
            {
                q.push(newNumber);
                m.insert({newNumber, cnt + 1});
                cnt = cnt + 1;
            }
            else
                f = 0;
        }
    }

    return -1;
}

int main()
{
    cin >> n >> x;
    cout << BFS(x);
    return 0;
}