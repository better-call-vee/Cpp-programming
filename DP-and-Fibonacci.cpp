/*
nth Fibonacci number

1 1 2 3 5 8 13 21 34
*/

/*
#include<bits/stdc++.h>
using namespace std;

int fib (int n) {

    if(n<=2) return 1;
    return fib(n-1) + fib(n-2);

}

int main () {

    cout<<fib(3)<<"\n";
    cout<<fib(5)<<"\n";
    cout<<fib(50)<<"\n";

    //here it will quickly and rightly give the answer for the 5th and 3rd fibonacci number.
    //but when we will seek for a bigger output like 50th or more, it will crash/take long
    //time. that's where the dynamic programming shows up!
    return 0;
}
*/

/*

Let's simulate:

int fun (int n) {                                    int fib (int n) {
    if(n <= 1) return 1;                                 if(n <= 2) return 1;
    return fun(n-1);                                     return fib(n-1) + fib(n-2);
}                                                    }

fun(4)                                               fib(4)
we are calling with 4                                  4       level 1 = 1 node -> 2^0
4 calling 3                                         ↙    ↘
3 calling 2                                       3        2   level 2 = 2 nodes -> 2^1
2 calling 1                                     ↙    ↘
1 returning 1 to 2.                           2        1       level 3 = 2 nodes. but 2^2 for the level
2 returning 2 to 3.                                  leaf nodes are the base case of recursion.
3 returning 3 to 4.                                  here, 2 and 1 are the leaf nodes and as well
here fun is called total 4 times.                    as base case.
so, fun(n) will be called n times.                   to complete the tree, we need 2^(n-1) nodes for
Complexity - {O(n)}                                  each level.
space complexity:                                    2^0+2^1+2^2+....2^n-1
when a function is called,                           =2^n - 1
it enters call stack.                                so, there will be function call total 2^n times!!!
                                                     And, fibonacci's complexity will be O(2^n)!!
The call stack:                                      here we are calculating the nodes which are not
1                                                    even present but they are not so many in numbers
2      2                                             and negligible.
3      3      3
4      4      4       4
and it will pop like this.
look, the pile is n length long.
so, space complexity
will be O(n) as well here

SO, we don't want to calculate fibonacci in 2^n-1 complexity. What can we do?? let's see.

OPTIMIZATION:
Let's look at another tree for optimization.
fib(6)
                      6
         (n-1)     ↙     ↘     (n-2)
                5           4
              ↙  ↘        ↙  ↘
            4      3     3     2
           ↙ ↘   ↙  ↘  ↙ ↘
          3   2  2   1 2   1
         ↙ ↘
        2   1

    look, here 1<--3-->2 is a repeated pair all over the graph.
    not only this, the following total subtree is repeated in the graph
         4
      ↙    ↘       do we need to call this twice? If we know the value of call 4 once, do we need
    3        2     to call that again? no, we don't because everytime it gives the same return.
  ↙   ↘            So, we will store the value and if we get the value once we will never calculate
2       1          again and it will be marked saved.

we have to store in the memory.                                                MEMORY
okay let's simulate the thing.                                                 store[3] = 2
first call -> fib(6). stored? no. Then we move forward                         store[4] = 3
second call -> fib(5). stored? no. Then we move forward                        store[5] = 5
third call -> fib(4). stored? no. Then we move forward
fourth call -> fib(3). stored? no. Then we move forward
fifth call -> fib(2). stored? no. Then we return 1. we move forward.
sixth call -> fib(1). stored? no. Then we return 1. we move backward.
We don't need to store fib(2) & fib(1)'s memory because it's a
O(1) statement(base case)

fib(3) gets it's return = 1+1 = 2. we store it in the array
fib(4) gets it's return = fib(3)+fib(2) = 2+1 = 3. we store in the array
now, to the right of fib(4), there is fib(3) (5's child). will we call for it?
ABSOLUTELY NOT. Because it's already stored!
fib(5) gets fib(4)+fib(3) = 5. saved and stored
fib(5) is 6's left child. we have a right child.
fib(4). haha, this big sub-tree
was already stored! so we don't need to calculate this!
fib(6) gets it's value fib(5) + fib(4) = 8.

The new time complexity is O(n).
                    6         4 + 4 (left+right) . which is
                  ↙   ↘      (n-2) x (n-2)
                5       4     =O(2n-2) = O(n)
              ↙  ↘
            4      3
           ↙ ↘
          3   2               we are here from O(2^n) to O(n). do fib(7) simulation by yourself for
         ↙ ↘                  intuition.
        2   1
*/

#include <bits/stdc++.h>
using namespace std;

long long arr[101];

long long fib(int n)
{
    if (n <= 2)
        return 1;

    if (arr[n] != 0)
        return arr[n]; // if that position is calculated already.

    arr[n] = fib(n - 1) + fib(n - 2);
    return arr[n];
}

int main()
{

    cout << fib(8) << "\n";
    cout << fib(50) << "\n";
    cout << fib(100) << "\n";

    return 0;
}

/*
The main concept of dynamic programming is breaking down a problem into smaller subproblems, solving
each subproblem once, and storing the solutions in a table to avoid redundant work
*/