/*
an important concept: If I multiply with -1 each and every element of a priority queue while pushing
and popping, it will be a min heap eventually.
suppose, pq -> [30, 20, 10].
it's a maxheap(priority queue). I want to make it a minheap. while pushing I will make it
[-10, -20, -30]. but it's still a priority queue. while we will pop, at first -10 will be
popped, then -20, then -30. Everytime we will multiply -1 with the popped element.
We will eventually get 10, then 20, then 30. Gotcha(minheap)

there is a syntax to do this.
priority_queue<int
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(9);
    pq.push(2);

    while (pq.size() != 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout<<"\n";
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(5);
    pq2.push(3);
    pq2.push(8);
    pq2.push(9);
    pq2.push(2);

    while (pq2.size() != 0)
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }

/*
pair of priority queue:
priority_queue<pair<int, int>>ppq;
[{10,20}, {20,15}, {10,25}, {10,15}, {5,50}]
here, if I pop, the first popped element will be {20, 15}.
Then {10, 25} and so on
for pair priority queue, at first the first part of the pair is checked. eg: in the above example, 
{5,50} will be popped in the end of all.
If the first parts of the pairs have the same value, then the second parts are checked.
*/

    return 0;
}
