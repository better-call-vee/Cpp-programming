//https://www.hackerrank.com/contests/phitron-monthly-contestmarch-2023batch-02/challenges/multiplication-between-l-to-r
/*
Problem Statement
You are given an array of N integers.The next line will contain Q queries.In each query you are given
two intgers L and R. Now find the multiplication between L to R.
Input Format
The first line contains a single positive integer N (size of the array).
The second line will contain N integers A1,A2,A3,A4…..An (values of the array).
The third will contain a Q . The next lines will contain Q queries. In each line of the query will
contain two values L and R
Constraints
2 ≤ N ≤ 1000000
1 ≤ Q ≤ 7000000
0 ≤ A[i] ≤ 1 (Where 1 <= i <= N)
1 <= L,R <= 1000000 (Where L < R)
Output Format
Print the multiplication between L to R. Don't forget to print a new line after each query.
Sample Input 0
9
1 0 1 0 1 1 1 1 1 
3
4 7
4 8
5 7
Sample Output 0
0
0
1
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q,L,R,val;
    cin>>N;
    vector<int> A;
    for(int i=0; i<N; i++)
    {
        cin>>val;
        A.push_back(val);
    }
    int prefix[N+1]; //here, we will store the values for the sum of the indices of main array.
// 9
// 1 0 1 0 1 1 1 1 1
// 0 1 1 2 2 3 4 5 6 7  prefix sum
    prefix[0] = 0; 
//the first element of the prefix sum array is 0, as there are no elements before index 0 in the
//original array.

    for(int i=1; i<N+1; i++) //here the system will be difficult if we start from index 0.
    {
        prefix[i] = prefix[i-1] + A[i-1]; //prefix sum means we will add the current index's value with
        //the last sum of the array and store the added value again in the prefix sum array
    }
    for(int i=0; i<N+1; i++) {
        cout<<prefix[i]<<" ";
    }
    cout<<"\n";
    cin>>Q;
    while(Q--)
    {
        cin>>L>>R;    //as the input is only 0 & 1.
        int match = (R-L)+1; //This is because the indices are 0-based, so the actual length of the 
        // subarray would be R-L, but we need to add 1 to get the total number of elements.

        int match2 = prefix[R]-prefix[L-1];
        if(match==match2) cout<<"1\n";
        else cout<<"0\n";

        // If we want to count the number of 1s in the subarray between indices 3 and 7, we need to 
        // compute prefix[7] - prefix[2]. This is because prefix[7] gives the sum of elements from 
        // index 0 to 6 (which includes all the elements up to index 6, but not including index 7), 
        // and prefix[2] gives the sum of elements from index 0 to 1 (which includes all the elements 
        // up to index 1, but not including index 2). So, subtracting prefix[2] from prefix[7] gives 
        // the sum of elements from index 2 to 6 (which includes all the elements from index 3 to 7, 
        // because indices are 0-based), which is the number of 1s in the subarray.

    }
    return 0;
}
