/*
//another problem on rotation:
https://codeforces.com/contest/1896/problem/C(solution to be checked on
submissions)

The problem is we need to exchange the shoes of the students but someone's shoe
can only be exchanged if there are shoes greater or equal sized than that
person. And the sizes will be given ascendingly. we have to print the sequence
of the exchanged shoes.

2
5
1 1 1 1 1
6
3 6 8 13 15 21
output:
5 1 2 3 4 or, 2 3 4 5 1 or others
-1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        int n, start = 0;
        cin >> n;

        vector<int> shoes(n);
        for(int i = 0; i < n; i++) cin >> shoes[i];

        vector<int> exchange(n);
        iota(exchange.begin(), exchange.end(), 0);
        // suppose, n is 7. it will be 0 1 2 3 4 5 6
        // suppose we may write iota(....., 1) it will be 1 2 3 4 5 6 7
        // iota(....., 3)? => 3 4 5 6 7 8 9
        bool hobena = false;
        while(start < n) {
            int end = start;
            while(end < n && shoes[start] == shoes[end]) end++;

            if(end - start == 1) {
                hobena = true;
                break;
            }

            rotate(exchange.begin() + start, exchange.begin() + start + 1,
                   exchange.begin() + end);
            // rotate the vector from the 2nd place to the last.
            // suppose 1 2 3 4 5. start = 0. middle parameter = 4. then => 2 3 4
            // 5 1. rotated left 4 times suppose 2 2 3 3 3 4 4 4 4. start = 5,
            // end = 8. then 6 7 8 5. the middle parameter is for choosing from
            // which place we want to rotate. if it were 2, we would do 7 8 5 6.
            start = end;
        }
/*
                  The rotate Function
Purpose: std::rotate rearranges the elements in a range [first, last) such that
the element at middle becomes the first element. 
Syntax: rotate(Iterator first, Iterator middle, Iterator last)
*/

        if(!hobena)
            for(int i = 0; i < n; i++)
                cout << exchange[i] + 1 << " \n"[i == n - 1];
        else
            cout << -1 << "\n";
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.emplace_back(x, i + 1);
    }
    rotate(a.begin(), a.begin() + 5, a.end());
    for(int i = 0; i < n; i++) cout << a[i].first << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << a[i].second << " ";

    return 0;
}

run this to understand better about vector rotate.
9
2 2 3 3 3 4 4 4 4

output will be:
4 4 4 4 2 2 3 3 3
6 7 8 9 1 2 3 4 5

if you write the end pointer a.begin() + 8;
it will be
4 2 2 3 3 3 4 4 4 
9 1 2 3 4 5 6 7 8
*/