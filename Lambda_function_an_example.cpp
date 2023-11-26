#include<bits/stdc++.h>
using namespace std;

// this code takes a 2D array as input
// flattens it to an 1D array and prints it in one line
int main() {
    int n, m; cin >> n >> m;
    auto get_id = [&](int i, int j) { // get id for cell (i, j)
        return i * m + j;
    };
    int f[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            f[get_id(i, j)] = x;
        }
    }
    for (int i = 0; i < n * m; i++) {
        cout << f[i] << ' ';
    }
    return 0;
}

/*
I use lambda functions while using custom comparators in C++ (see above) or when I need to write 
a quick function that uses lots of local variables and I don't want to pass these variables as 
parameters and don't wanna write them as global variables either.
*/