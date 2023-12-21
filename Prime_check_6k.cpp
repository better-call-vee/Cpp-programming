// https://www.codechef.com/problems/PRIMEFACT

#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;

    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int X, Y;
        cin >> X >> Y;

        int count = 0;
        while(X < Y) {
            if(X % 2 == 0) {
                int chk = Y - X;
                if(chk % 2 == 0)
                    count += chk / 2;
                else
                    count += chk / 2 + 1;

                break;
            } else if(isPrime(X))
                X += X;
            else if(X % 2 != 0) {
                if(X % 3 == 0)
                    X += 3;
                else if(X % 5 == 0)
                    X += 5;
                else if(X % 7 == 0)
                    X += 7;
            }

            count++;
        }
        cout << count << "\n";
    }

    return 0;
}

/*
        map<int, int> prime_factors;

        while(n % 2 == 0) n /= 2, prime_factors[2]++;
        while(n % 3 == 0) n /= 3, prime_factors[3]++;

        for(int i = 5; i * i <= n; i += 6) {
            while(n % i == 0) prime_factors[i]++, n /= i;
            while(n % (i + 2) == 0) prime_factors[i + 2]++, n /= (i + 2);
        }
        if(n > 3) prime_factors[n]++; // remaining prime after factorization

prime factors storing.
*/