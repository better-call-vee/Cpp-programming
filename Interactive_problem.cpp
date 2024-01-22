/*
https://codeforces.com/problemset/gymProblem/101021/1 (search guess the number
codeforces) we have to guess the number and we will be given instructions
everytime.
>= means we have to go right or we have got the answer. The thing is, we dunno
what maybe our answer. So, we immidiately set the answer to that mid when mid is
>=.

In interactive programming problems, your program communicates with a judge
program during execution. This means that your program sends output to the judge
and waits for the judge's input based on that output.
But when using only new line, it will be stored in buffer, so judge won't be
able to find the interaction in the output file every time, and thus we need
buffer.

Buffering Issue: Normally, output using cout in C++ is buffered. This means that
when you output something, it's stored in a buffer and isn't immediately sent to
the output stream (like the console or, in interactive problems, the judge
program).

Solving Buffering with endl and flush():
Using endl: This not only adds a newline character (like "\n") but also flushes
the buffer. However, it can be slower due to frequent flushing. Using
cout.flush(): This command forces the buffer to flush without adding any extra
characters. It ensures that all your output is immediately sent to the judge
program.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int l = 1, r = 1000000, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if(s == "<") {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush() return 0;
}

// https://codeforces.com/contest/1867/problem/C
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while(t--) {
//         int n;
//         cin >> n;
//         vector<int> nums(n);

//         int mex = n;
//         bool paisi = false;
//         for(int i = 0; i < n; i++) {
//             cin >> nums[i];
//             if(nums[i] != i && !paisi) {
//                 mex = i;
//                 paisi = true;
//             }
//         }

//         cout << mex << "\n";
//         cout.flush();

//         int bob;
//         cin >> bob;
//         while(bob != -1) {
//             if(bob == -2) {
//                 cout << "Wrong Answer\n";
//                 cout.flush();
//                 exit(0);
//             } else {
//                 cout << bob << "\n";
//                 cout.flush();
//             }
//             cin >> bob;
//         }
//     }

//     return 0;
// }

/*
https://codeforces.com/problemset/problem/679/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool query(int x) {
    cout << x << '\n';
    cout.flush();
    string s; cin >> s;
    return s == "yes";
}
bool prime(int n) {
    if(n <= 3) return true;
    if(n % 2 == 0 or n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6)
        if(n % i == 0 or n % (i + 2) == 0) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    // the hidden number ranges from [2, 100]. We gotta handle the corner
    // case. when a number has only one prime divisor, it's a square number.
    // that will surely be a composite number.
    if(query(2 * 2) or query(3 * 3) or query(5 * 5) or query(7 * 7)) {
        cout << "composite";
        return 0;
    }
    int divs = 0;
    for(int i = 2; i <= 50; i++)
        if(prime(i)) divs += (query(i));
    cout << ((divs <= 1) ? "prime" : "composite");
    // we skipped prime divisors over 50 because, prime divisors over 50 will
    // not make it in the range of 100, we can take less than 50.
    // As we took 2 >= i <= 50, we need to also check now if the div is 0. else
    // we would only check if div is 1.
    return 0;
}
*/

/*
//IMPORTANT ONE
//https://toph.co/p/a-new-tough-game
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int diff(string x) {
    cout << "? " << x << endl;
    int d; cin >> d;
    return d;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a, ans;
    for(int i = 0; i < n; i++) a += 'a';
    int lower_diff = diff(a);
    for(int i = 0; i < n; i++) {
        a[i] = 'z';
        int upper_diff = diff(a);
        for(char c = 'a'; c <= 'z'; c++) {
            if(('z' - c) + ('a' - c) == (upper_diff - lower_diff)) {
                ans += c;
                break;
            }
        }
        a[i] = 'a';
    }

    cout << "! " << ans << endl;
    return 0;
}
*/