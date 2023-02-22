//#include<bits/stdc++.h>
//using namespace std;
//int main ()
//{
//    int n, n2;
//    cin>>n;
//    int marr[n+1];
//
//    for(int i=1; i<n; i++)
//    {
//        cin>>n2;
//        marr[n2] = n2;
//    }
//
//    for(int i=1; i<=n; i++)
//    {
//        if(marr[i] != i)
//        {
//            cout<<i;
//            break;
//        }
//    }
//    return 0;
//}


#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n, n2;
    cin>>n;
    int sumall = (n*(n+1))/2;
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        cin>>n2;
        sum += n2;
    }
    cout<<sumall-sum;
    return 0;
}
