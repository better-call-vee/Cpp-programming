#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
int ask(int i, int j) {
    cout << "? " << i << " " << j << " " << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void print(int i, int j) {
    cout << "! " << i << " " << j << endl;
    cout.flush();
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int one = ask(1, 1);
        if(!one) { print(1, 1); continue; }
        int i = min(one + 1, n), j = one - i + 2, l = min(one + 1, m),
            k = one - l + 2, two = ask(i, j), tri = ask(k, l);
        if(!two) { print(i, j); continue; }
        if(!tri) { print(k, l); continue; }
        int tms = (tri + 1) / 2, tms2 = (two + 1) / 2;
        int f2 = l - tms, f1 = k + tms, s1 = i - tms2, s2 = j + tms2, lstchk = ask(f1, f2);
        if(f1 > n) f1 += n; if(f2 < 0) f2 += m; if(s1 < 0) s1 += n; if(s2 > m) s2 -= m;
        if(lstchk) print(s1, s2);
        else print(f1, f2);
    }
    return 0;
}

/*
https://codeforces.com/contest/1934/problem/C

We will simply ask 1, 1.
They will give the distance from a mine which is in the least distance and give it 
to me. 
Now this least distanced mine will be in a diagonal for sure, observe the 
question you will see. first pic(3, 3, 3, 3);

So, our task is now to determine this diagonal's top most cell and bottom most cell.
Now we will query with those cells.
NOW is the most important part,
see, for example, from the bottom most cell, if we calculate the manhattan distances 
of the diagonal:
0, 2, 4, 6... and so on.
also from the top most cell.
NOW:
From the second and third query, we got two manhattan distances, and we generate those
two cells. We follow the 0,2,4,6.. thing and take the divided by 2 output to get that
diagonal's cell.
either one of them will be the answer.
And they can go out of bound, so the 30th line is executed.
*/