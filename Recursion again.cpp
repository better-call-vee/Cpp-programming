/**
Suppose a movie ticket line. There are 7 people on the line. The last person in
the line wants to count the people present in the line.

     7        6        5        4        3        2        1
    /|\      /|\      /|\      /|\      /|\      /|\      /|\
   / | \    / | \    / | \    / | \    / | \    / | \    / | \    COUNTER
    / \      / \      / \      / \      / \      / \      / \
   /   \    /   \    /   \    /   \    /   \    /   \    /   \

Here, 7 wants to count the number of people in the counter. So, he's lazy. He can't
go and just count. He asked 6 about it. 6 is also like him. So, 6 asked 5. 5 asked
4, 4 asked 3, 3 asked 2, 2 asked 1. Now, 1 knows that there's no one in front of 1.
So, he said 2 that there's 0 people.
And now 2 knows that there're 0 people ahead of 1 and there's only 1 in front of him.
So, he told 3 that, there're 1 people ahead of him. now 3 will say 4 that there is
2 people ahead of him. 4 will tell 5 that there're 3 ahead of him. 5 will tell 6 that
there're 4 people ahead of him. 6 will say to 7 that yeah there's 5 people ahead of
him. So, now 7 will get that there're 6 people ahead of him including 6 & including
him there are 7 people in the line.

Bingo, recursion works just like that. Recursion is a lazy procedure led by the main
call(7th man in the line)
And here the base case is the 1st man.
**/

/**
Let's consider a problem, we want to calculate the sum of 1 to n numbers.

There are three steps to solve a problem related to recursion, STEPS:
1. Check if we can solve the smallest problem?
2. Check if we can solve the larger problem if the smaller problem is already
   solved?
3. Generalize the relation into a formula.

So, to calculate the sum of 1 to n numbers sum(n), first step will be to solve the
smaller problem sum(1). We can solve this & it's the base case.

now, consider the sum(n) = sum(n-1)+n. same goes for sum(1).
sum(1) = sum(1-0) + 1.
so, everytime we will call sum(n-1) it will do some mysteries we don't know but
eventually we will get our result. let's write the code then I'll describe the steps
with a short example
**/

#include<bits/stdc++.h>
using namespace std;

int resum(int n) {
    if(n==1) return 1;
    return resum(n-1)+n;
}
/**
suppose, n=4;
we call the function with n=4.It passes the base case and continues for recursion
we get to 51th line, and resum function is called again with n=3. then again,
n=2, momentarily, n=1. and here is the breakthrough. we get a return because we
couldn't pass the base case, bingo. and this function will return to n=2 call now.
which will return to n=3 call with a value of 1+2=3(1 was returned through base
case and +n where n was 2). so n=3 call gets 3 in return and it goes to n=4 call
with a return of 3+3=6. and finally the main call gets it's return 6, it adds n
with it. It's eventually 10, the answer!
**/
int main () {
    int n;
    cin>>n;
    cout<<resum(n);
    return 0;
}

/**
#include<bits/stdc++.h>
using namespace std;

int gotsum (vector<int>a, int n)
{
    if(n==1) return a[0];

    return a[n-1] + gotsum(a, n-1);
}

int main ()
{

    int n;
    cin >> n;
    vector<int>resum;

    for(int i=0; i<n; i++)
    {
        int inp;
        cin >> inp;
        resum.push_back(inp);
    }

    cout << gotsum(resum, n);
    return 0;
}
**/
