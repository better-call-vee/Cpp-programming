//missing number*

//O(n)
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;
    long long a[n-1];
    for(int i=0; i<n-1; i++)
    {
        cin>>a[i];
    }
    long long sum = (n * (n+1)) / 2;
    for(int i=0; i<n-1; i++)
    {
        sum -= a[i];
    }
    cout<<sum;

    return 0;
}

//O(n^2)
//#include<bits/stdc++.h>
//using namespace std;
//int main ()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int n;
//    cin>>n;
//    int a[n-1];
//    int count = 0;
//    for(int i=0; i<n-1; i++)
//    {
//        cin>>a[i];
//    }
//    for(int i=1; i<=n; i++)
//    {
//        count = 0;
//        for(int j=0; j<n-1; j++)
//        {
//            if(i!=a[j]) count++;
//        }
//        if(count==(n-1))
//        {
//            cout<<i;
//            return 0;
//        }
//    }
//
//    return 0;
//}
