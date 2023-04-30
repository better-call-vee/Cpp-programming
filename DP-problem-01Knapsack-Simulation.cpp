/*
Imagine that you are attempting a home robbery and you have a knapsack on your back with a maximum
carrying capacity of 13 kg. You have four items to rob, each with different weights and values. The
items are an almirah weighing 11 kg with a value of 250, a phone weighing 3 kg with a value of 200,
a laptop weighing 5 kg with a value of 100, and a big watch weighing 4 kg with a value of 80.

Your objective is to rob with the goal of obtaining the highest possible value within the carrying
capacity of the knapsack. However, you cannot split an item and must either take the entire item or
leave it behind. That's why this problem is known as the 01 knapsack problem(0 for leaving behind,
1 for taking)

While a greedy approach would be to take the maximum valued item, the almirah, doing so would prevent
you from taking any other items due to the knapsack's limited capacity. The optimal approach is to
take the phone, laptop, and big watch, which have a combined weight of 12 kg and a total value of
380, within the knapsack's maximum capacity.



Let's simulate with a brute force:

/-------\-------\--------\
| Object| Value | Weight |
|-------|-------|--------|
| 1     |  200  |    3   |
| 2     |  250  |   11   |
| 3     |  100  |    5   |
| 4     |   80  |    4   |
\-------/-------/--------/

we have to call with a function brute(n, cap).
Our capacity is 13. 
=> brute(4, 13).
It's a 01 knapsack problem. Either we will take the nth object or we won't.
        1YES(3, 9) If we take the 4th object then our capacity will reduce according to it's weight.
      ↗
(4,13)
      ↘
        0NO(3, 13) If we don't take the 4th object then our capacity won't be changed

This two options with n = 3 will also have 2 options for each. 
(3, 13) : YES => (2, 8)    NO => (2, 13)
(3, 9)  : YES => (2, 4)    NO => (2, 9)
The two options generated for each object in the knapsack problem will also have their own set of 
options. This recursive process will continue until all possible combinations have been evaluated.
At each step, we take the maximum value between the two options (either selecting the object or not
selecting it) to determine the best possible outcome.

The recursive process and the selection of the maximum value at each step are similar to a recurrence
relation, which is a mathematical function that defines a sequence of values based on previous values.
However, in the case of the knapsack problem, the recursive process is based on the evaluation of all
possible combinations, rather than a defined sequence of values.

A defined sequence of values is a mathematical sequence where the values are explicitly defined based
on a mathematical formula or rule. For example, the Fibonacci sequence is a defined sequence of values
where each number is the sum of the two preceding numbers. The sequence starts with 0 and 1, and the
next number is calculated by adding the previous two numbers (0+1=1, 1+1=2, 1+2=3, 2+3=5, and so on).
In contrast, the knapsack problem involves evaluating all possible combinations of objects, and the
order of evaluation is not predetermined by a mathematical formula or rule. The recursive process used
to solve the knapsack problem is based on the evaluation of each possible combination and the selection
of the maximum value at each step.


To solve the knapsack problem, the 3 steps:
1) Define the state: We define the state as knapsack(n, cap), which represents the maximum possible
profit considering objects 1 to n and a capacity of cap.

2) Define the recurrence relation: We define the recurrence relation as follows:
If we select the nth object, the maximum possible profit would be
value[n] + knapsack(n-1, cap - weight[n]).
If we do not select the nth object, the maximum possible profit would be 0 + knapsack(n-1, cap).
We take the maximum of these two values as the maximum possible profit at the current state.
knapsack(n, cap) = max(
                       value[n] + knapsack(n-1, cap - weight[n]),   # YES CASE
                       0 + knapsack(n-1, cap)                       # NO CASE
                      )
74th line => If we do not get any profit or do not select the object, we do not get any value for 
it, and the capacity amount does not get reduced.

3) Define the base case: When we reach n=0, we will return 0. Therefore, the base case will be
knapsack(0, any-cap or x) = 0.
when we have no items left to consider, the maximum profit that we can get is zero, hence we set this
base case.
or, there can be some additions.
if (n == 0) or (cap == 0): return 0
if (weight[n] > cap): return knapsack(n-1, cap)
like this.
Here, the base case checks whether the weight of the current item n is greater than the capacity of
the knapsack cap. If the weight of the current item exceeds the capacity, then we skip that item and
move on to the next item by calling knapsack(n-1, cap). This ensures that we do not consider the item
whose weight exceeds the capacity of the knapsack.

BUT, note that every state in the dynamic programming algorithm for the 0/1 knapsack
problem generates two new children, representing the two possible decisions of either taking or not
taking the current item. This creates a binary tree structure of states, with a total of 2^n possible
states.
As a result, the time complexity of the brute force approach to the knapsack problem is O(2^n), which
can be prohibitively large for large values of n.


If we use dynamic programming (DP) to solve the knapsack problem, we can avoid calculating a value
multiple times and only compute it once before storing it.
The function knapsack(n, w) can be solved with a time complexity of at most O(n*w), where n is the
number of objects and w is the maximum capacity of the knapsack.
We can use a two-dimensional array named dp[n][w] to store the computed values, which will result in
a space complexity of O(n*w).

*/