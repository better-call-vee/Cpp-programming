#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 4, b = 5;
    cout<<"Before swapping, a = "<<a<<", b = "<<b<<endl;
    swap(a,b);
    cout<<"After swapping, a = "<<a<<", b = "<<b<<"\n";

    int mini = min(a,b);
    cout<<"\v\vMinimum of them: "<<mini<<endl;

    int maxi = max(a, b);
    cout<<"Maximum of them: "<<maxi<<endl;

    int c = 8, d = 9;
    mini = min ({2, 0, c, d}); //more than 2 numbers
    cout<<"\vFor more than 2 numbers: "<<mini<<"\n";
    //same goes for maximum

    vector<int>la = {3,2,1,4,5};
    cout<<"\v\vBefore sorting: "<<endl;
    for(int i=0; i<la.size(); i++)
    {
        cout<<la[i]<<" ";
    }
    cout<<"\vAfter sorting: "<<endl;
    sort(la.begin(), la.end());
    for(int i=0; i<la.size(); i++)
    {
        cout<<la[i]<<" ";
    }

    vector<int>lb = {2,9,3,1,4};
    cout<<"\v\vNow sorting from index 1 and 2: "<<endl;
    sort(lb.begin()+1, lb.begin()+2+1);// for sorting, sort function needs the second
    //parameter to be added by 1.
    //in fact, la.end() = la.begin() + la.size();
    for(int i=0; i<lb.size(); i++)
    {
        cout<<lb[i]<<" ";
    }
    cout<<endl<<endl;

    vector<int> v= {2,5,1,9,7};
    reverse(v.begin(),v.end());

    cout<<"After reversing 'v' vector: "<<endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << '\n';
    return 0;

}
