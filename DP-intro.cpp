main concept is recursion most of the time(core)
                    fib(n)  Bigger problem
                  ↙       ↘
              fib(n-1)   fib(n-2)  Smaller Sub-problems

There are more subproblems here. fib(n-3), fib(n-4) and going on.
But see one think, this fibonacci function didn't need more than two sub-problems to be written in the
function{(n-1) & (n-2)};

if we do a think like tribonacci! lol! 
1  1  1  3  5  9  17
then the recusrsive case would have been tri(n) = tri(n-1) + tri(n-2) + tri(n-3)        

The main concept of dynamic programming is breaking down a problem into smaller subproblems, solving
each subproblem once, and storing the solutions in a table to avoid redundant work

If we see in a problem that solving smaller problems bigger problems can be solved, then we can 
decide that we'll solve this with DP.

To solve a DP problem:
i) Define State 
ii) Identify the recursive equation from the smaller subproblems
iii) Define base cases


i) what is state? look fib(n), here n is the state. fun(a, b, c) -> here a, b & c are the 
state. 
fib(n) will calculate the nth fibonacci number(this is state definition). This is 
mandatory. Otherwise we won't be able to find our targetted value

ii) fib(n) = fib(n-1) + fib(n-2)

iii)fib(1) = 1, fib(2) = 2. 
base case is the case where we don't need any smaller subproblem to solve it!

State definition is the hardest part
There are two techniques:
1) Memorization/Recursive/Top-Down
2) Tabulation/Iterative/Bottom-Up

Memorization/Recursion is the most used method.
