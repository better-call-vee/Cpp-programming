#include<bits/stdc++.h>

void print(int **x) {
    **x = 2500;
}
using namespace std;
int main () {
    int a=10;
    int *p = &a;
    int **q = &p;
    print(q);
    cout<<a<<endl;
    return 0;
}
