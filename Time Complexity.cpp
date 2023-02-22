
//Time and memory complexity both order 1, O(1)
//#include<bits/stdc++.h>
//using namespace std;
//
//int main () {
//    int a, b, c;
//    cin>>a>>b>>c;
//    int maxi = max({a, b, c});
//    int mini = min({a, b, c});
//    int sum = a+b+c;
//    int mul = a*b*c;
//
//    cout<<maxi<<"\n";
//    cout<<mini<<"\n";
//    cout<<sum<<"\n";
//    cout<<mul<<"\n";
//
//    return 0;
//}



//time complexity = O(n+1+n+1) = O(2*n+1) = O(2*n) = O(c*n) = O(n)
//this 1 can be removed from (2*n+1). because, if n=1000, it doesn't
//matter the other 1 operation. here 2*n is dominating. so, we are keeping
//this. next we can ignore constant.so, O(n).
//so, memory complexity is also O(n).
//O(1*3) would be O(1). only n can dominate O(1).
#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; //O(1) memory complexity
    cin>>n;
    vector<int>a(n); //O(n) memory complexity
    for(int i=0; i<n; i++) { //O(n) time complexity for this loop
        cin>>a[i]; //depended on n;
    }

    int maxi = a[0]; //this 3 operations are constant. so for TC, O(1)
    int mini = a[0];
    int sum = 0;

    for(int i=0; i<n; i++) {  //TC, O(n)
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
        sum = sum + a[i];
    }
    cout<<maxi<<"\n";
    cout<<mini<<"\n";
    cout<<sum<<"\n"; //TC, O(1). answer printing constant operation

    return 0;
}
