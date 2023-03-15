#include <iostream>
#include <vector>
using namespace std;

int n;

int fibonacci(int n,vector<int> &memo)
{
    if(n<=1) return n; //if n=0, will return 0. if n=1, will return 1.
    //look, the smallest problem is this base case.

    if (memo[n] != 0) return memo[n]; // Check if the value has already been
    //calculated

    memo[n] = fibonacci(n-1,memo) + fibonacci(n-2,memo);
    // Calculate the value and store it in the memo array
    return memo[n];
}

int main()
{
    cin>>n;
    vector<int>memo(n);

    for(int i=0; i<n; i++)
    {
        cout<<fibonacci(i,memo)<<" "; //everytime it's giving input of n, first
        //0, then 1, then 2, then 3....and the values are set to the memo
        //vector for memorization.
    }
    cout<<endl;
    cout<<"The "<<n<<"th Fibonacci number is: "<<fibonacci(n-1, memo);
    return 0;
}

//for calculating nth number, we don't need to use the memorization method.
//we can just go on with the base case and 15th line, n = instead of memo[n]
//return n;  fibonacci(n-1)+fibonacci(n-2)

//fibonacci(4)
//
//1. The function is called with the argument 4.
//2. Since 4 is not one of the base cases (n == 0 or n == 1), the function checks
//if memo[4] has a value. Since it's the first time the function is called with
//the argument 4, memo[4] is 0.
//3. The function calls itself twice: fibonacci(3) and fibonacci(2)
//4. fibonacci(3) calls fibonacci(2) and fibonacci(1), which return 1 and 0
//respectively.
//5. fibonacci(2) calls fibonacci(1) and fibonacci(0), which return 1 and 0
//respectively.
//6. The function fibonacci(3) returns 1+0 = 1 and memo[3]=1
//7. The function fibonacci(2) returns 1+0 = 1 and memo[2]=1
//8. The function fibonacci(4) returns memo[3] + memo[2] = 1+1 = 2
//so the output will be 2


//As you can see in the above example, the function is called multiple times with
//the same argument, but the values are stored in the memo array, so it doesn't
//need to recalculate them, and it can return the stored value. This improves the
//performance of the function and makes it run much faster, especially for large
//values of n.
