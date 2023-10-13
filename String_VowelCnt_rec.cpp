/*
☞ Better.Call.Vee ☜
created: 06th October, 2023 01:58:29 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n;

bool vowel_chk(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int count_vowels(int go) {
    if(go >= n) return 0;
    return (vowel_chk(s[go]) ? 1 : 0) + count_vowels(go + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, s);
    n = s.size();
    cout << count_vowels(0);

    return 0;
}