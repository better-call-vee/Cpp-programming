#include<bits/stdc++.h>
using namespace std;

int main ()
{

    int n;
    cin>>n;
    vector<int>a(n); //we are keeping a vector sized n.
    //so, memory complexity is O(n).
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    //time complexity --> O(((n-1)*n)/2) --> O(n^2)
    for(int pass=0; pass<n; pass++)
    {
        int last = n-1-pass; //for every pass one index gets sorted.
        bool sorted = true;
        for(int j=0; j<last; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                sorted = false;
            }
        }
        if (sorted) break; //that means, it hasn't swapped for even once. so sorted
        //is true. it's used because sometimes extra passes are executed with the
        //sorted array
        //but decreasing sized array can take it to the worst case
        cout<<"After pass "<<pass<<": ";
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"After sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
