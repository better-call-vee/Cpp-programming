#include<bits\stdc++.h>
using namespace std;
int main () {
//    int *x = new int;
//    *x = 10;
//    cout<<x<<endl;
//    cout<<*x<<"\n";
//    delete x;
    int n;
    cin>>n;
    int *x = new int[n];
    for(int i=0; i<n; i++) {
        cin>>x[i];
        //int *x --> *x = 10, x
        //x[i] --> x --> x[i]
    }
    cout<<"Memory address/value of x: "<<x<<endl;
    for(int i=0; i<n; i++) {
        cout<<x[i]<<endl; //int type data, so for every index, the address will be increased by 4
    }
    delete[] x; //we have taken a new data, so we should delete it later.
    return 0;
}


//heap is for dynamic memory allocation. it can give the asked memory during
//runtime. stack is for static
