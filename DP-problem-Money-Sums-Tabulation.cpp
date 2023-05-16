/**
I will be given a number of coins. I have print the output of the money sums I can create using 
those coins.
Suppose, I have been given 3 coins.
3
5 2 1
The output will be:
7
1 2 3 5 6 7 8
Here, we can't take any coin twice. We have to make distinct combinations.
Here the seven combinations are:
Taking only one coin => 1, 2 and 5
Taking two coins => 5+2=7, 2+1=3, 5+1=6
Taking all three coins => 5+2+1=8.          #These are the total 7 sums.

Sample Input:
4
4 2 5 2
Output:
9
2 4 5 6 7 8 9 11 13

Okay, now let's go through the code and discuss.
At first we take the inputs(n and the coins with a 0 indexed vector)
Then we take a variable named MAX_SUM and we predict a very large value. According to the problem 
statement our constraints are n can't be larger than 100 and the value of a coin can't be more than 
1000. Thus we take the MAX_SUM = 100*1000+1.
Next, we take a boolean vector with the size of the MAX_SUM named 'possible'

Now is the main part of this code. We set the possible[0] = true. This is for initializing the process.
Let me explain =>
If we see the next few lines of code we will get that. We need to make true all the indices of this
'possible' boolean vector which are our possible sums. 
At first we set the possible[0] to true. Setting possible[0] to true initially ensures that a sum of
0 is always possible. This is because if we don't include any coins, the sum will be 0. By setting
possible[0] to true, the algorithm accounts for the case when no coins are selected and ensures that
the sum 0 is considered as one of the distinct sums.

Next up is the nested loop. 
The condition if (possible[j - coins[i]]) checks if it is possible to form the sum j - coins[i] using
the previously considered coins.
If possible[j - coins[i]] is true, it means that the sum j - coins[i] can be achieved by selecting
some combination of the previous coins.
In that case, we set possible[j] to true, indicating that the sum j is also possible by considering
the current coin coins[i] in addition to the previously selected coins.
Suppose, the coins are 2, 3 and 5.
First Iteration: coin = 2
For the first coin (2), the inner loop starts from j = MAX_SUM - 1 = 100001 and goes down to j = 2.
For each value of j, we check if possible[j - coins[i]] is true, which means we check if 
possible[j - 2] is true.
When j = 2, j - coins[i] becomes 2 - 2 = 0. Since possible[0] is true (initialized earlier), the 
condition if (possible[j - coins[i]]) evaluates to true.
Therefore, we update possible[j] to true, so possible[2] becomes true.
Second Iteration: coin = 3
The inner loop starts from j = MAX_SUM - 1 = 100001 and goes down to j = 3.
For each value of j, we check if possible[j - coins[i]] is true, which means we check if 
possible[j - 3] is true.
When j = 3, j - coins[i] becomes 3 - 3 = 0. Since possible[0] is true, the condition if 
(possible[j - coins[i]]) evaluates to true.
Therefore, we update possible[j] to true, so possible[3] becomes true.

And, thus we go on. Actually we use the previous sums to find the next sums. 
**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    const int MAX_SUM = 100 * 1000 + 1;
    vector<bool> possible(MAX_SUM);
    possible[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = MAX_SUM - 1; j >= coins[i]; j--)
        {
            if (possible[j - coins[i]])
                possible[j] = true;
        }
    }

    int distinctSums = 0;

    for (int i = 1; i < MAX_SUM; i++)
    {
        if (possible[i])
            distinctSums++;
    }

    cout << distinctSums << "\n";

    for (int i = 1; i < MAX_SUM; i++)
    {
        if (possible[i])
            cout << i << " ";
    }

    return 0;
}

