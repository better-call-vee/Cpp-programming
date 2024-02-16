#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// MB means mega bytes, Mb means mega bits. 1 byte = 8 bit.
const unsigned int MAX_VAL = (1u << 31);
// u for unsigned. for safety, not compulsory
// bool exists[MAX_VAL]; // Memory: O(MAX_VAL / (10^6)) MB (Per element memory:
// 1 byte = 8 bit)
// vector<bool> exists(MAX_VAL, false); // Memory: O(MAX_VAL / (8 * 10^6)) MB
// (Per element memory: 1 bit)
bitset<MAXI> exists;
// Memory: O(MAX_VAL / (8 * 10^6)) MB (Per element memory: 1 bit)
// 1 MB = 10^6 bits.
#include <bits/stdc++.h>
using namespace std;
const unsigned int MAX_VAL = (1u << 31);
// bool exists[MAX_VAL]; // Memory: O(MAX_VAL / (10^6)) MB (Per element memory:
// 1 byte = 8 bit) vector<bool> exists(MAX_VAL, false); // Memory: O(MAX_VAL /
// (8 * 10^6)) MB (Per element memory: 1 bit)
bitset<MAX_VAL>
    exists; // Memory: O(MAX_VAL / (8 * 10^6)) MB (Per element memory: 1 bit)
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    unsigned int s, a, b;
    cin >> q >> s >> a >> b;
    set<unsigned int> se;
    long long sum = 0;
    while(q--) {
        if(s & 1) {
            unsigned int x = s / 2;
            // add x to the set (if this number is NOT already present in the
            // set) x < 2^31 if (se.find(x) == se.end()) {
            //   se.insert(x);
            // }
            if(!exists[x]) {
                exists[x] = true;
                sum += x;
            }
        } else {
            unsigned int x = s / 2;
            // erase x from the set (if this number exists in the set)
            // x < 2^31
            // if (se.find(x) != se.end()) {
            //   se.erase(x);
            // }
            if(exists[x]) {
                exists[x] = false;
                sum -= x;
            }
        }
        s = a * s + b; // overflow BUT in modulo 2^32 (lol)
    }

    // for (unsigned int x: se) {
    //   sum += x;
    // }
    // for (int i = 0; i < MAX_VAL; i++) {
    //   if (exists[i]) {
    //     sum += i;
    //   }
    // }
    cout << sum << '\n';
    return 0;
}
/*
We will be given an s, and then if it's odd we have to insert the value s
into the set or if it's even, we have delete that value from set, if the value
is present.
then we have to print the sum;
*/