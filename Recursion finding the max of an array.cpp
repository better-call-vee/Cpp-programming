#include<bits/stdc++.h>
using namespace std;

///O(nlogn) time complexity. efficient for big array input
int maxDUDE(vector<int>&a, int gear, int stop)
{
    if(gear==stop) return a[gear];
    int mid = (gear+stop)/2;
    int leftDUDE = maxDUDE(a, gear, mid);
    int rightDUDE = maxDUDE(a, mid+1, stop);
    return max(leftDUDE, rightDUDE);
}

int main ()
{
    int n;
    cin>>n;
    vector<int>THEDUDES(n);
    for(int i=0; i<n; i++)
    {
        cin>>THEDUDES[i];
    }
    cout<<maxDUDE(THEDUDES, 0, n-1);
    return 0;
}


///O(n) linear time complexity, efficient for small array input
//int maxDUDE(vector<int>&a, int n, int max)
//{
//    if(n<=0) return max;
//    if(a[n-1]>max) max = a[n-1];
//    return maxDUDE(a, n-1, max);
//}


///Some important explanation of the O(nlogn) one
//After the function reaches the base case of gear == stop and returns the value
//at that index, it goes back up the call stack to the previous level of
//recursion where it was called.
//
//For example, in the case of the array [5, 2, 7], the function would first call
//itself with the left half of the array [5] and the right half [2, 7]. The left
//half would reach the base case and return the value 5. The right half would
//also call itself recursively with the left half [2] and the right half [7],
//and again the base case would be reached and the values 2 and 7 would be
//returned.
//
//Once the base case is reached and the values are returned, the function at the
//previous level of recursion compares the returned values and returns the
//maximum of the two. In this case, it would return 7.
//
//This process continues all the way up the call stack until the function reaches
//the original call and returns the maximum value of the entire array.
//
//It's worth noting that this recursive approach has the time complexity of
//O(nlogn) which is more efficient than O(n).

//In the example provided, the function maxDUDE, first calls the helper functions
//leftDUDE and rightDUDE to find the maximum value in the left and right half of
//the array respectively.
//It then compares the values returned by these helper functions and returns the
//maximum of the two.
//The helper functions themselves also use a similar recursive approach to find
//the maximum value in their respective halves of the array. They call themselves
//recursively with smaller parts of the array, and when the base case is reached,
//the value at that index is returned.
//The returned value then gets compared by the calling function and the maximum
//gets returned to the next level of recursion.
