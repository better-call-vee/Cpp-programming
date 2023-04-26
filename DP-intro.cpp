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


To create this type of recursive and base cases, we need to analyze the problem and identify the
repetitive subproblems that can be solved using recursion. We also need to identify the base cases,
which are the termination conditions of the recursion. We can understand this by breaking down the
problem into smaller subproblems and solving them recursively until we reach the base case.

Start by understanding the problem statement and the requirements for the solution. Try to identify
the main problem and any subproblems that may exist.

Break down the problem into smaller subproblems that can be solved recursively. Think about the
different ways you can approach the problem and try to identify any patterns or repetitions that
you can take advantage of.

Consider the input space of the problem and try to identify any common inputs or patterns that may
exist. For example, in the case of this problem, we know that we are trying to reach a target number
of 1, so we can consider how we can reduce the given number to 1 using the three operations provided.
(The problem is finding the minimum steps to reach 1 from any number)

Once you have identified the subproblems, think about how you can solve them recursively. Start with
the base cases and work your way up to the larger subproblems. Consider any edge cases that may need
to be handled separately.

Test your solution with different inputs and verify that it provides the correct output. If you
encounter any issues or errors, debug your solution and try to identify the source of the problem.