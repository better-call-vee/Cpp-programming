#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)  //memory complexity O(n)
    {
        cin>>a[i];
    }

    //10^5 --> 1e5. 10^9 --> 1e9

    //Time complexity O(n^2)
    //while will run i times. 0+1+2+3+...+n-1.
    for(int i=1; i<n; i++)
    {
//3, 4, 1, 2, 7, 6, 1. here, i=0 --> 3. which is already sorted. we can't insert
//here. so starting from 4, i=1
//here, we are taking at first two elements, then 3.. then go on....
        int idx = i;
        while(idx >= 1)
        {
            if(a[idx-1] > a[idx])   //if previous index is greater than current's
            {
                //then it's not sorted
                swap(a[idx-1], a[idx]);
                idx--;
            }
            else break;
        }
        cout<<"Considering till index "<<i<<": ";
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"After Sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

//bubble and insertion are not good sorting method. they take more time
