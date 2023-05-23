/*
Romeo and Juliet are a newly married couple. They went to Switzerland for their honeymoon.
They had a plan in mind: they would test their fortune by staying in different cities and seeing if
they could reunite in at most K steps. Switzerland has N cities numbered from 0 to N-1, with E
two-way roads connecting them.
Romeo is in city X, and Juliet is in city Y. In each step, they can cross one road and move from one
city to another. It is not mandatory for both of them to cross; one can choose to stay in the same
city if desired. However, the step will still be counted.
Can you tell if they can be reunited or not?
Input Format
First line will contain N and E; The number of city and number of roads respectively.
Next E lines will contain A and B which means there is a road between city A and B.
Last line will contain X,Y and K.
Constraints
2 <= N <= 100
0 <= E <= 1000
0 <= X, Y < N and X != Y
0 <= K <= 1000
Output Format
Output "YES" if they can be reunited otherwise output "NO".
Sample Input 0
8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
4 7 2
Sample Output 0
YES
       1-----3
      /     / \
     /     /   \
    0     2     6
     \   / \   / \
      \ /   \ /   \
       4     5     7

look, here Romeo is on node 4 and Juliet is on node 7. Our goal is to reach to the same node within
K steps. At step 1, Juliet can reach 6 from 7 and Romeo can reach either 0 or 2. He will decide which
is best for him to reach Juliet within K steps. Suppose, he chooses 2 here. The very next step,
Juliet chooses 5. And also Romeo can choose 5 because 2 and 5 are adjacent nodes.

Okay, it's quite a similar problem like BFS traversal. But there are some modifications we have to make.
The main point of this problem is we can't take the queue here just because the queue kinda solution
just takes one node at a time but we can't do that for the limitation of steps.
So what can we do?
We can take vector in lieu of queue. And here we have to take 2 different vectors and visited arrays for
the couple.
And the bfs function will be a bully(boolean) function+it will consist of 2 parameters for the
couple.
at first we simply make the visited index of the sources equivalent to 1. 
Then we push each source to it's owner vector. And then we take a new variable with a value of 1 to
track the count of steps.
Then we run the while loop with a condition of the variable's value being greater than K.
Then we take the size of the respective vector of each person and run a loop because for each step
we will consider every node of that level. 
look, when Romeo is on node 4, he can go to node 2 and node 0. If we take one node at a time, 0 can
be selected in lieu of 2 which will lead to an error because 2 is the optimal node for Romeo here.
Here's a trick: we select the vector and go from the last element to the first element. Unless we 
can't track it because everytime we have to erase an element right after exploring that node.
Yeah, we could do this with queue but that will not be convenient. So, we go with the vector.
Then when we start the loop of Juliet, we check if a certain node is visited for both of Romeo and
Juliet. If yes then we just return true and we end the function.
If we simply go out of the while loop that means they didn't meet during the steps. So, we simply 
return false. Done.
*/

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