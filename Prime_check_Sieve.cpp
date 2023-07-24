// SIEVE OF ERATOSTHENES

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    // Create a boolean vector "prime[0..n]" and initialize
    // all entries as true. A value in prime[i] will finally
    // be false if i is not a prime, else true.
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false; // here it marks all the multiples of
            // p to false because they won't be prime. It starts from 'p * p' instead of 'p'
            //  because all multiples of 'p' less than 'p * p' would have already been marked as
            //  non-prime by smaller prime numbers. look at 3. we start from 3*3 = 9.
            // and before that 2 already marked 4, 6, 8 all the non-prime numbers. so we start
            // from p*p.
        }
    }

    // Return true if n is a prime number
    return prime[n];
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    return 0;
}
