/*
☞ Better.Call.Vee ☜
created: 06th October, 2023 01:40:23 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void print_pyramid(int star, int space) {
    if(star >= n) return;

    cout << string(space, ' ');
    cout << string(star * 2 + 1, '*'); //creating emergency string with size and character.
    cout << "\n"[star == n - 1];

    print_pyramid(star + 1, space - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    print_pyramid(0, n - 1);

    return 0;
}