#include<bits/stdc++.h>
using namespace std;

vector<int> sortTHEDUDE(vector<int>&a, int n)
{
    if(n<=1) return a;
    int mid = n/2;
    vector<int>rightDUDE;
    vector<int>leftDUDE;
    for(int i=0; i<mid; i++)
    {
        rightDUDE.push_back(a[i]);
    }
    for(int i=mid; i<n; i++)
    {
        leftDUDE.push_back(a[i]);
    }
    int rs = rightDUDE.size();
    int ls = leftDUDE.size();
    vector<int>b = sortTHEDUDE(rightDUDE, rs);
    vector<int>c = sortTHEDUDE(leftDUDE, ls);

    vector<int>sortedDUDE;
    int bix = 0;
    int cix = 0;

    for(int i=0; i<n; i++)
    {
        if(bix==b.size())
        {
            sortedDUDE.push_back(c[cix]);
            cix++;
        }
        else if(cix==c.size())
        {
            sortedDUDE.push_back(b[bix]);
            bix++;
        }
        else if(b[bix]>=c[cix])
        {
            sortedDUDE.push_back(c[cix]);
            cix++;
        }
        else
        {
            sortedDUDE.push_back(b[bix]);
            bix++;
        }
    }

    for(int i=1; i<n; i++)
    {
        if(sortedDUDE[i]==sortedDUDE[i-1])
        {
            sortedDUDE.erase(sortedDUDE.begin()+i);
            i--;
            n--;
        }
    }

    return sortedDUDE;
}

int main ()
{
    int n;
    cin>>n;
    vector<int>THEDUDE(n);
    for(int i=0; i<n; i++)
    {
        cin>>THEDUDE[i];
    }
    vector<int>sdDUDE = sortTHEDUDE(THEDUDE, n);

    for(int i=0; i<sdDUDE.size(); i++)
    {
        cout<<sdDUDE[i]<<" ";
    }
    return 0;
}

//When you are removing elements from an array using the erase function, it shifts
//the elements after the removed element to fill the gap. This causes the index of
//the next element to change, and if you don't decrease the value of i and n, the
//next element will be skipped.
//
//For example, let's say you have an array of [1, 2, 2, 3, 4, 4, 5] and you want
//to remove the duplicate elements. You start by iterating through the array,
//and you find a duplicate element at index 1. You remove it using the erase
//function, which shifts all elements after it to the left by one position. Now
//the array becomes [1, 2, 3, 4, 4, 5]. If you don't decrease the value of i and n,
//the next iteration will start from index 2 and will skip the element at index
//1. So, decreasing the value of i and n ensures that the next iteration starts
//from the correct position and does not skip any elements.

