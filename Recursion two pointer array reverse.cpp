#include<bits/stdc++.h>
using namespace std;

void reversearray (int arr[], int gear, int stop)
{
    if(gear<stop)
    {
        swap(arr[gear], arr[stop]);
        reversearray(arr, gear+1, stop-1);
    }
}

int main ()
{
    int n;
    cin>>n;
    int garr[n];
    for(int i=0; i<n; i++)
    {
        cin>>garr[i];
    }
    reversearray(garr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<garr[i]<<" ";
    }
}

