#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Modular exponentiation (to avoid large integer overflows)
ll expmod(ll x, ll y, ll p)
{
    ll result = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

// Miller-Rabin primality test
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    ll d = n - 1;
    int r = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    int iterations = 5; // Number of iterations (witnesses)
    for (int i = 0; i < iterations; i++)
    {
        ll a = 2 + rand() % (n - 3);
        ll x = expmod(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        bool isComposite = true;
        for (int j = 1; j < r; j++)
        {
            x = expmod(x, 2, n);
            if (x == n - 1)
            {
                isComposite = false;
                break;
            }
        }

        if (isComposite)
            return false;
    }

    return true;
}

int main()
{
    ll number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    return 0;
}
