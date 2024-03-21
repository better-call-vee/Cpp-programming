#include <bits/stdc++.h>
void print(int **x) { **x = 2500; }
using namespace std;
int main() {
    int a = 10;  // a random value.
    int *p = &a; // p got a's address.
    cout << *p << endl;
    // this is how pointer prints value. the pointer pointing to a.
    int **q = &p;
    // q got p's address which is pointing to a. so, pointer's pointer.
    print(q);
    // here we are actually changing a's value, q is pointing a actually.
    cout << a << endl;
    return 0;
}
