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
        LCM(a, b)= a × b / GCD(a, b)

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
╔═══════════╗
║ FORMULAS: ║
╚═══════════╝

We can find the sum of squares of the first n natural numbers using the formula, 
SUM = 1^2 + 2^2 + 3^2 + ... + n^2 = [n(n+1)(2n+1)] / 6
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
------------------------------------------
|       NOTATIONS and PROGRESSION        |
------------------------------------------
i=4
 ∏  i => 1×2×3×4=24   this is pie notation.
i=1

i=4
 ∑  i^2 => 1+4+9+16=30    this is sigma notation.
i=1

i=n-1
 ∑  r^i => r^n - 1 / r - 1 . suppose, r = 2. and i will go till n. then => 2^(n+1) - 1/ 2 - 1.
i=0
this is geometric progression
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





/*
╔════════════════════╗
║ Modular Arithmetic ║
╚════════════════════╝

Modulo World => suppose n mod 6, in this world 5, 11, 17, 23... belong to the same family. and so on like this.


1) a≡b (mod m) means that a and b have the same remainder when divided by m. that is a mod m = b mod m.
and for that (a-b) mod m = 0. 1 % 6 => 1 and 7 % 6 => 1. 7 - 1 = 6 mod 6 => 0.

2) (a + b) ≡ (a mod m + b mod m) (mod m);
3) (a - b) ≡ (a mod m - b mod m) (mod m);
4) (a x b) = (a mod m x b mod m) (mod m);
5) a^b ≡ (a mod m)^b (mod m);
6) a-b if negative ≡ ((a mod m - b mod m) % m + m) % m;

these don't work with a/b.
#include<bits/stdc++.h>
using namespace std;

int main() {
  int a = 7;
  int b = 6;
  int m = 5;

  // Property: (a + b) mod m = ((a mod m) + (b mod m)) mod m
  int result1 = (a + b) % m;
  int result2 = ((a % m) + (b % m)) % m;
  cout << "(a + b) mod m = " << result1 << endl;
  cout << "((a mod m) + (b mod m)) mod m = " << result2 << endl;

  // Property: (a - b) mod m = ((a mod m) - (b mod m) + m) mod m
  int result3 = (a - b) % m;
  int result4 = ((a % m) - (b % m) + m) % m;
  cout << "(a - b) mod m = " << result3 << endl;
  cout << "((a mod m) - (b mod m) + m) mod m = " << result4 << endl;

  // Property: (a * b) mod m = ((a mod m) * (b mod m)) mod m
  int result5 = (a * b) % m;
  int result6 = ((a % m) * (b % m)) % m;
  cout << "(a * b) mod m = " << result5 << endl;
  cout << "((a mod m) * (b mod m)) mod m = " << result6 << endl;

  int c, d;
  // a * b * c * d mod m = (((a * b) mod m) * c mod m) * d mod m
  a = 1e9 - 3; b = 1e9 - 1; c = 1e9 - 2; d = 1e9 - 3; m = 1e9 + 7;
  int result7 = (a * b * c * d) % m; // overflow
  int result8 = (((a * b) % m) * c % m) * d % m; // still overflow
  int result9 = (((1LL * a * b) % m) * c % m) * d % m; // no overflow
  cout << "(a * b * c * d) mod m = " << result7 << ' ' << result8 << ' ' << result9 << endl;

  // a - 3 * b mod m = (a mod m - (3 * b) mod m + m) mod m
  cout << "(a - 3 * b) mod m = " << (a - 3LL * b % m + m) % m << endl;

  // find n! mod m
  int n = 100;
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (1LL * fact * i) % m;
  }
  cout << n << "! mod m = " << fact << endl;

  // find a^b mod m
  b = 100;
  int power = 1;
  for (int i = 1; i <= b; i++) {
    power = (1LL * power * a) % m;
  }
  cout << a << "^" << b << " mod m = " << power << endl;
  return 0;
}
*/





/*
╔═══════════════════════╗
║ Some Builtin Function ║
╚═══════════════════════╝
#include<bits/stdc++.h>
using namespace std;

int main() {
  // abs
  int num_1 = -10;
  int abs_result = abs(num_1);
  cout << "Absolute value of " << num_1 << " is: " << abs_result << '\n';

  // ceil, floor, round, llround
  double num_2 = 3.7;
  double ceil_result = ceil(num_2);
  double floor_result = floor(num_2);
  double round_result = round(num_2);
  long long llround_result = llround(num_2);
  cout << "Ceil value of " << num_2 << " is: " << ceil_result << '\n';
  cout << "Floor value of " << num_2 << " is: " << floor_result << '\n';
  cout << "Round value of " << num_2 << " is: " << round_result << '\n';
  cout << "Long long rounded value of " << num_2 << " is: " << llround_result << '\n';

  // log, log2, log10
  double num_3 = 1000.0;
  double log_result = log(num_3);
  double log2_result = log2(num_3);
  double log10_result = log10(num_3);
  cout << "Natural logarithm of " << num_3 << " is: " << log_result << '\n';
  cout << "Base-2 logarithm of " << num_3 << " is: " << log2_result << '\n';
  cout << "Base-10 logarithm of " << num_3 << " is: " << log10_result << '\n';

  // sqrt, cbrt, pow
  double num_4 = 16.0;
  double sqrt_result = sqrt(num_4);
  double cbrt_result = cbrt(num_4);
  double pow_result = pow(num_4, 2);
  cout << "Square root of " << num_4 << " is: " << sqrt_result << '\n';
  cout << "Cube root of " << num_4 << " is: " << cbrt_result << '\n';
  cout << num_4 << " raised to the power of 2 is: " << pow_result << '\n';

  // stoi, stoll, to_string
  char s[] = "12345";
  int stoi_result = stoi(s);
  long long stoll_result = stoll(s);
  cout << "String to integer conversion: " << stoi_result << '\n';
  cout << "String to long long conversion: " << stoll_result << '\n';
  cout << "Integer to string conversion: " << to_string(stoi_result) << '\n';

  // cerr, cout
  cerr << "This is an error message" << '\n';
  cout << "This is a regular output" << '\n';

  // isalpha, isdigit, islower, isupper, tolower, toupper
  char ch = 'A';
  bool is_alpha_result = isalpha(ch);
  bool is_digit_result = isdigit(ch);
  bool is_lower_result = islower(ch);
  bool is_upper_result = isupper(ch);
  char to_lower_result = tolower(ch);
  char to_upper_result = toupper(ch);
  cout << "Is " << ch << " an alphabet? " << is_alpha_result << '\n';
  cout << "Is " << ch << " a digit? " << is_digit_result << '\n';
  cout << "Is " << ch << " in lowercase? " << is_lower_result << '\n';
  cout << "Is " << ch << " in uppercase? " << is_upper_result << '\n';
  cout << "Lowercase conversion of " << ch << " is: " << to_lower_result << '\n';
  cout << "Uppercase conversion of " << ch << " is: " << to_upper_result << '\n';

  // swap
  int num_5 = 10;
  int num_6 = 20;
  cout << "Before swapping: num_5 = " << num_5 << ", num_6 = " << num_6 << '\n';
  swap(num_5, num_6);
  cout << "After swapping: num_5 = " << num_5 << ", num_6 = " << num_6 << '\n';

  // gcd
  int num_7 = 36;
  int num_8 = 48;
  int gcd_result = __gcd(num_7, num_8);
  cout << "GCD of " << num_7 << " and " << num_8 << " is: " << gcd_result << '\n';

  // rand
  srand(time(0)); // Seed the random number generator
  int random_num = rand();
  cout << "Random number: " << random_num << '\n';

  // reverse
  char reverse_str[] = "Hello, World!";
  int len = strlen(reverse_str);
  reverse(reverse_str, reverse_str + len);
  cout << "Reversed string: " << reverse_str << '\n';

  // sort, is_sorted
  int a[] = {5, 2, 3, 1, 9};
  int n = 5;
  sort(a, a + n);
  bool is_array_sorted = is_sorted(a, a + n);
  cout << "Sorted numbers: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  cout << "Is the array sorted? " << is_array_sorted << '\n';
  return 0;
}
*/