#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(9);
    dq.push_back(4);
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}
