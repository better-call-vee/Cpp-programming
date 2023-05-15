/*
You'll be given two integer numbers => n and x. Suppose x has 2 digits. And n is 3.
You have to multiply x with such a value that the product has the same digit number as n
and the value has to be one of x's digit but not 0. You have to show the output of the minimum
operations needed to do this.
suppose, n=5 and x=430. Currently, x has 3 digits. We have to make it 5. So, multiplication
starts. We can't take 0 because of the condition.
Taking 3 => 1290 => 1290 x 9 => 11610 (2 operations)
Taking 4 => 1720 => 1720 x 2 => 3440 => 3440 x 4 => 13760 (3 operations)
We will take the minimum one.

The problem is a mixture of BFS concept + dynamic programming.
suppose, n=3 and x=2
            2
            ⬇
            4
            ⬇
           1 6
        ↙      ↘
       16(1)    96(6)
      ↙ ↘     ↙  ↘
  (1)16  96  864  576       #we got our answer.
        (6)  (9)   (6)
Look, it's looking like a tree and if we take the left options, we will have to continue this
and the total operations would be 5. But by following the right section, we can do it in 4
operations. It's like the BFS method, level by level and all the digits of a number are it's
children(actually the products we get multiplying with the digits).

Let's learn it with the code.
At first we take the inputs. Then we take a queue of long long datatype because we will store the
products which can have a large value.
Then we take a map which will work for memorization named ops.
We set the ops[x] = 0 because later we check a condition that if a string named 'digits' has the equivalent
size of n. If yes, then we print the operations needed for child => ops[child](child is the front of the
queue).
Suppose, x is 2 and n is 1. So think, for the very first time after entering the while loop(which has a
condition that it will run until the queue is empty), 2 will be converted into a string 'digits' which
has a size of 1 because 2 has only one digit.
Now it will check the condition where we will find that digits.size() == n == 1.
We print the ops[child] where child is set to 2 right now and in the map ops[2] was set to 0 before
entering the while loop. So finally result will be printed and that is 2.

Obviously after taking the front from the queue, we will pop an element from the queue.
I have described the next few steps.
If the condition is not met, we go on exploring.
We take every digit from the 'digits' string. We check if it's 0 or not. If yes, we simply continue. Then
we take a new variable named 'ydecimal'. We store the product here. Remember the 'child' variable we
took? We just simply multiply the taken digit with 'child'. Then finally we check if the map has already
the address of 'ydecimal'.
Look at the tree I drew => Here 16 can be seen twice. So, according to our code, the map 'ops' will
only contain the number of operations for 16 is 2, not 3. That's how BFS works actually, taking the
shortest path(level by level).
So, if the ydecimal isn't found in the map, we just go on setting it's ops to 1+it's parent's ops.
ops[ydecimal] = ops[child] + 1(which is a BFS concept)
finally, we push the ydecimal value to the queue so that hereafter we can explore the children of ydecimal.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    scanf("%d", &n);
    long long x;
    scanf("%lli", &x);

    queue<long long> q;
    map<long long, int> ops;

    ops[x] = 0;
    q.push(x);

    while (!q.empty())
    {
        long long child = q.front();
        q.pop();
        string digits = to_string(child); // to_string convert the integer value into string

        if (digits.size() == n)
        {
            printf("%d", ops[child]);
            return 0;
        }

        for (auto digit : digits)
        {
            if (digit == '0')
                continue;

            long long ydecimal = child * (digit - '0');

            if (!ops.count(ydecimal)) // checking if the address ydecimal is in the map or not
            {
                ops[ydecimal] = ops[child] + 1;
                q.push(ydecimal);
            }
        }
    }

    printf("-1");

    return 0;
}