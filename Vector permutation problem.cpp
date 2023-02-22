//You have to print from 1 to n but in such an order, where two adjacent numbers
//won't have the difference of 1.
#include <bits/stdc++.h>
using namespace std;

// Function to find the permutation
// which satisfies the given condition
vector<int> permutation(int n)
{
    vector<int> ans;
    if (n <= 3)
    {
        if (n==1) ans.push_back(1);
        else ans.push_back(-1);
    }
    else if (n==4)
    {
        for(int i=2; i<=4; i+=2)
        {
            ans.push_back(i);
        }
        for(int i=1; i<=3; i+=2)
        {
            ans.push_back(i);
        }
    }

    // If n is even
    else if (n % 2 == 0)
    {
        for (int i = n; i >= 2; i -= 2)
        {
            ans.push_back(i);
        }
        for (int i = n-1; i >= 1; i -= 2)
        {
            ans.push_back(i);
        }
    }

    // If n is odd
    else
    {
        for (int i = n-1; i >= 2; i -= 2)
        {
            ans.push_back(i);
        }
        for (int j = n; j >= 1; j -= 2)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

// Driver Code
int main()
{
    int N;
    cin>>N;
    vector<int> ans = permutation(N);
    vector<int> a = {-1};
    if(ans==a) cout<<"NO SOLUTION";
    else for (int x : ans)
            cout << x << " ";
    return 0;
}

