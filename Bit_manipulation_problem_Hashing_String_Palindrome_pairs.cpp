#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; string s; ll ans = 0;
    cin >> n;
    vector<int> masks(n);
    for(int i = 0; i < n; i++) {
        cin >> s;
        vector<int> freq(26, 0);
        for(auto c : s) freq[c - 'a']++;
        for(int k = 0; k < 26; k++)
            if(freq[k] & 1) masks[i] += (1 << k);
    }
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        ans += cnt[masks[i]];
        for(int j = 0; j < 26; j++) ans += cnt[masks[i] ^ (1 << j)];
        cnt[masks[i]]++;
    }
    cout << ans;
    return 0;
}
/*
We will be given some strings and we have to show output of the possible pairs of 
strings which will make palindrome(no matter how we organize them). Moreover, if (jth, ith)
is counted, (ith, jth) won't be counted.

We set the bitmasking while we get an odd count of number of a character in a string.
suppose, 
5
aab
abcac
dffe
aa
edd
here, for aab, we will get 10. for dffe, we will get 1100.
now, we take a map and we store the mask everytime we go ahead. 
if the same bitmasks are appeared, we simply add the previous occurances with the answer,
because the current one will make palindrome pairs with them. same bitmasked values meaning,
same character's odd counted occurances are present in those strings. thus they will add up 
as even.
now finally, we check for adding odd occurance which will be palindrome. suppose, the string
here dffe, we get the bitmask 1100. now for d, when(line 19) reaches j = 3, we get the XOR as
1000. now the 5th string "edd" has bitmask value 1000. and both of them concatenated makes a
palindrome pair. How is this?? look, the 'd' and 'e' are odd numbered in the "dffe" string. 
if we find another string which has odd numbers of e and even numbers of d, it will still make a
palindrome, we are looking for those combinations.

Suppose, dffegf and fgedd. they will make it. 
*/