/*
--------------------
| Common Multiples:|
--------------------
Given two integers x and y, and a range from 1 to n:

    Calculating Multiples of x and y:
        The total number of multiples of x within the range is ⌊nx⌋⌊xn​⌋.
        The total number of multiples of y within the range is ⌊ny⌋⌊yn​⌋.

    Identifying Common Multiples of x and y:
        The common multiples of x and y within a given range are the multiples of their Least Common Multiple (LCM).
        The formula for LCM of two numbers aa and bb is:
        LCM(a,b)=a×b/GCD(a,b)

        Here, GCD stands for the Greatest Common Divisor.
        The count of common multiples of x and y in the range is ⌊nLCM(x,y)⌋⌊LCM(x,y)n​⌋.

    Adjustment for Common Multiples:
        Subtract the count of common multiples from the multiples of x and y to get the adjusted counts.
    #include <bits/stdc++.h>
using namespace std;

// Compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Compute LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Adjust the count of multiples of x and y in the range 1 to n, considering common multiples
void adjust_multiples(int n, int x, int y, int &x_div, int &y_div) {
    x_div = n / x;
    y_div = n / y;

    // Deduct common multiples (those divisible by LCM of x and y)
    int common_multiples = n / lcm(x, y);
    x_div -= common_multiples;
    y_div -= common_multiples;
}

int main() {
    int n = 24, x = 4, y = 6;
    int x_div, y_div;
    adjust_multiples(n, x, y, x_div, y_div);
    cout << "Adjusted count of multiples of " << x << ": " << x_div << endl;
    cout << "Adjusted count of multiples of " << y << ": " << y_div << endl;
    return 0;
}

*/

/*
-----------------------------------------------------------------
Calculating the Sum of the Last m Largest Numbers in a Sequence:|
-----------------------------------------------------------------

Given a sequence from 1 to N:

To find the sum of the last m largest numbers, we first need to identify these numbers.

The last m largest numbers in the sequence from 1 to N would be:
N−1,N−2,…,N−m+1

Now, let's use the arithmetic sequence sum formula to determine the sum of these numbers.

The formula to find the sum of an arithmetic sequence is:
Sum=n/2×(first term+last term)

For our sequence:

    First term = N−m+1
    Last term = N
    Number of terms (n) = m

Plugging in these values:
Sum=m / 2 × (N − m + 1 + N)
Sum=m / 2 × (2N − m + 1)
highSum = (k * (2 * n - k + 1)) / 2;
*/

/*
--------------------------------------------------------------------------------
Minimum LCM of two numbers from 1 to N and their sum has to be equivalent to N |
--------------------------------------------------------------------------------
int n, ans = 1;
cin >> n;

for (int i = 2; i * i <= n; i++)
     if (n % i == 0)
        ans = max(ans, n / i);

cout << ans << " " << n - ans << "\n";
*/

/*
------------
CO - PRIME |
------------
If two numbers' GCD is 1, then they are "CO-PRIME"
*/

/*
-------------------
GCD - OVERLAPPING |
-------------------
https://github.com/tanvee009/Cpp-programming/blob/main/GCD_overlapping.cpp

*/



/*
--------------------------
| DIGIT COUNT TECHNIQUE: |
--------------------------

to get the digit count of any number, we can simply use
log10(n) + 1.
it will give us the digit count.

*/




/*
--------------------------
|   COMBINATORICS(NCR)   |
--------------------------
BINOMIAL EFFICIENT:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ncr(int n, int r) {
    if(n < r) return 0; // if n becomes smaller than r, we can't fulfill r.so, 0 combination
    if(r == 0 || r == n) return 1; //if r is equivalent to 0 or r == n then there is only 1 combination. think about it.
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R;
    cin >> N >> R;

    cout << ncr(N, R);

    return 0;
}

Let C(n, r) = number of ways to select r elements from n elements
Then C(n, r) = C(n - 1, r) + C(n - 1, r - 1)
Do you know the proof of this?
Here is an easy proof:
Let the elements be 1, 2, 3, ...., n
We want to select r elements from this n elements. How many ways can we do this?

Consider the first element 1.
- If we do not select it, then we will have to select the r elements from
  the rest of the n - 1 elements: 2, 3, 4, .., n.
  How many ways for this? Yes, C(n - 1, r)

- If we select 1, then then we will have to select the r - 1 elements from
  the rest of the n - 1 elements.
  How many ways for this? Yes, C(n - 1, r - 1)

So total ways = C(n, r) = C(n - 1, r) + C(n - 1, r - 1)

*/


/*
NPK = N! / (N-K)!
suppose, 1,2,3 => here  {1,2} will be a combination, as well {2, 1} will be counted
*/


/*
--------------------------
|       NOTATIONS        |
--------------------------
i=4
 ∏  i => 1×2×3×4=24   this is pie notation.
i=1

i=4
 ∑  i^2 => 1+4+9+16=30    this is sigma notation.
i=1
*/


/*
-----------------------------------------
|       Divisiblity of a big num        |
-----------------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isDivisible(string a, ll b) {
    ll mod = 0;
    for(int i = 0; i < a.size(); i++) {
        mod = (mod * 10 + (a[i] - '0')) % b;
    }
    return mod == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        string a;
        cin >> a;

        ll b;
        cin >> b;

        (isDivisible(a, b))
            ? cout << "YES, " << a << " is divisible by " << b << "\n"
            : cout << "NO, " << a << " is not divisible by " << b << "\n";
    }

    return 0;
}

*/




/*
╔═══════════╗
║ Log & Exp ║
╚═══════════╝
1) log(a×b)=log(a)+log(b)
2) e^(log(a))=a     => e eliminates log

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    double a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    double log_a = log(a);
    double log_b = log(b);
    double sum_log = log_a + log_b;

    // Property 1: log(a * b) = log(a) + log(b)
    cout << "Property 1: log(a * b) = log(a) + log(b)" << endl;
    cout << "log(" << a << " * " << b << ") = " << log(a * b) << endl;
    cout << "log(" << a << ") + log(" << b << ") = " << sum_log << endl << endl;

    // Property 2: e^(log(a) + log(b)) = a * b
    cout << "Property 2: e^(log(a) + log(b)) = a * b" << endl;
    cout << "e^(" << log_a << " + " << log_b << ") = " << exp(sum_log) << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    return 0;
}

---------------------------------------------
𝐥𝐨𝐠ₐ𝑏 = logc(b) / logc(a)  or 𝐥𝐨𝐠ₑ𝑏 / 𝐥𝐨𝐠ₑ𝑎; |
---------------------------------------------

Intuition:
Imagine you have a ladder of height b and you're measuring it using a 
ruler of length a. The logarithm log⁡abloga​b essentially asks: "How many rulers 
of length a do we need to measure the ladder of height b?"

But what if our ruler is of a different length, say c? The right-hand side of 
the formula measures the ladder in two steps using the new ruler:

    log⁡c(b): How many c-length rulers are needed to measure the ladder of height b?
    log⁡c(a): How many c-length rulers to measure the original a-length ruler?

Dividing these (log⁡c(b)/log⁡c(a)​) gives us the equivalent measure of the ladder height
b but in terms of the original ruler a, essentially converting our measurement system
back to rulers of length a.

Visual:
Place two ladders side by side, one of height b and the other of height a. Measure both 
using rulers of length c. The ratio of these two measurements (counts of rulers) gives
you a conversion factor to understand how many a-length rulers would be needed to
measure the ladder of height b.

*/





/*
╔═════════════════╗
║ Harmonic Series ║
╚═════════════════╝
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 1000000;
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i) 
            sum += j;
    cout << sum;
    return 0;
}

This is a proper example of harmonic series. The time complexity is O(nlogn).
It might seem like it's O(n^2), but it's O(nlogn).
The sum of harmonic series is logn.

1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8... 1/n;
here => 1/7 will have the value less than 1/8 and greater than 1/4. So, we will take the
last 2's power for all this.
1 + 1/2 + 1/2 + 1/4 + 1/4 + 1/4 + 1/4 + 1/8... 1/log2(n)
1 +     1              + 1            + 1.... and it's eventually log2(n);
*/

