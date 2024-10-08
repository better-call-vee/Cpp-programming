/*
Bit related problems:
https://github.com/tanvee009/XPSC_ARCHIEVE/tree/main/WEEK%207/Day_1
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%207/Day_3/Bitwise_equation.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%208/Day_1/Order_by_XOR.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2011/Day_2/Array_elimination.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2011/Day_3/Stone_Pile.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2012/Day_4/DivisorChain.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2012/Day_5/Valerii_against_Everyone.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2015/Day_2/Candy_party.cpp
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2015/Day_5/Friendly_arrays.cpp


Bitwise operator: | ~ &

1)OR(1 is called the set bit)
   if there is at least a 1, the answer is 1.

2)AND(all of the bits have to be 1 to be 1)
     0 & 0 = 0
     0 & 1 = 0
     1 & 1 = 1

3)XOR(if both are same, it's 0. if different 1)
     0 ^ 0 = 0
     0 ^ 1 = 1
     1 ^ 1 = 0

XOR has tricks for problem solving.
If you XOR two same numbers we get 0.
suppose,
5  =>    1 0 1
       ^ 1 0 1
         -----
         0 0 0
Thus, we get the outcome 0. Thus, we know that same numbers' XOR operation
eliminates that number. Suppose, we are given an array of integers. There are
pairs of numbers but a number is peerless. 6 4 5 5 9 4 9 6 2 if we approach it
with brute force, it will take many grueling operations. but if we do this with
XOR, we can do it easily.
6 ^ 4 ^ 5 ^ 5 ^ 9 ^ 4 ^ 9 ^ 6 ^ 2.
we may think that we are doing XOR with random numbers. How can we find the
number like this?? It's easy. suppose, 5 ^ 6 ^ 5 first => 1 0 1 1 1 0
            -----
            0 1 1
 second =>  1 0 1
            -----
            1 1 0, which is 6.
So, what do we understand from this. Eventually the same numbers will be cut off
by XOR operations(even numbered pairs) suppose, we have four 5, three 3, six 8,
one 2. eventually we will have only one 3 and a 2. got it?


Trick:
& for even odd.
suppose n = 9.
if we do & of 9 and 1. it will be 1. which will determine 9 as odd.
 how?
    1 0 0 1
          1
    -------
          1

   every even number, if we convert it to binary, the last I meant MSB will be
0. if we & it , either 1 or 0 will be the output. 0 means even, 1 means odd. we
might think that we are doing & with only a bit(1). but no. int contains 32 bit,
thus this 1 have 31 more zeroes in front of it. and the number here(9), has 28
more zeroes in front of it.


Trick:
how many bits do I need to change to convert 10 to 15.

10 =>     1   0   1   0
15 =>     1   1   1   1   XOR
------------------------
              1   0   1 => we need to change two bits



Trick: Count number of set bits(1)
10 =>    1   0   1   0
15 =>    1   1   1   1
-----------------------
             1   0   1

we can count the set bits here by left shift, right shift and & operation
with 1. at first , we do & 1 with 1 0 1. we get 1. count++. left shift make a
number multiple of 2. << right shift make a number half. >>

5-> 1  0  1
right shift >> 0 1 0 (first time)
right shift >> 0 0 1 (second time) (right shift removes the right most bit)

we will do this until the number becomes fully zero.
*/

/*
//count number of set bits:

#include<bits/stdc++.h>
using namespace std;

int main () {
   int n;
   cin >> n;

   int count = 0;
   while(n != 0) {//or we can write while(n)
      if((n&1) == 1) count ++; //or if(n&1)
      n = n>>1;
   }

   cout<<count<<"\n";
   return 0;
}

*/
-- -- -- -- -- -- -SET k - th bit | == == == == == == -int x = 4, k = 1;
x | (1 << k);

---------------
UNSET k-th bit|
==============-
x & (~(1 << k))
 Shift 1 by k positions to the left: (1<<k)
This will create a number that has all bits set to 0 except the kth bit, which will be set to 1.
For example, if k=3, then (1<<k) will result in the binary representation 1000.

Take the bitwise NOT of the above result: ∼(1<<k)
This will flip all the bits of the result from step 1. That means all bits will be set
to 1 except the kth bit, which will be set to 0. For the example above, the result will be 0111.

Take the bitwise AND of x with the result from step 2: x&∼(1<<k)
        This will keep all the bits of xx unchanged except for the kthkth bit. 
        Since the kth bit in our mask (from step 2) is 0, the resulting kth
         bit in the final result will also be 0 (because anything ANDed with 0 is 0).

Let's look at a quick example for better understanding:

Suppose x=13 (binary representation 1101) and you want to unset the 2nd bit
(0-based indexing). Here's how the operation works:

    1<<2 = 0100
    ∼(1<<2) = 1011
    x&∼(1<<2)= 1101 (which is x) AND 1011 = 1001 (which is 9 in decimal).
/*
//Change number of bits to convert a to b
=========================================

#include<bits/stdc++.h>
using namespace std;

int main() {

   int a, b;
   cin >> a >> b;

   int dif = a^b; //XOR
   int count = 0;
   while(dif) {
      if(dif&1) count++;
      dif = dif>>1;
   }

   cout<<count<<endl;

   return 0;
}

*/

// 1<<n means 2^n.

// odd numbered pair won't eliminate the numbers by XOR operation.
// 3 ^ 3 ^ 3 = 3.

// to get the exact opposite binary representation
// for example:
// 1 0 1 1 => 0 1 0 0. we use NOT (~)
// int num = 11;
// int rev = ~num;

/*
XOR stands for Exclusive OR, and it is a logical bitwise operation. The XOR operation takes two
binary inputs and returns 1 in each bit position where the two inputs have different values, and it
returns 0 in each bit position where the two inputs have the same value.

To understand XOR's properties and its motives, let's look at some key properties of the XOR operation:

XOR of a number with itself is 0: For any binary number x, x XOR x = 0. This property arises from the
definition of XOR, where it returns 0 for bits that have the same value in both inputs.

XOR of a number with 0 is the number itself: For any binary number x, x XOR 0 = x. This property
arises because XOR returns the value of the non-zero bits in the first input.

Now, let's examine why XOR with 1 has the specific effect you mentioned:

XOR of an odd number with 1:
=============================
Let's take an example of an odd number, say 5 (binary representation: 0101). If we XOR it with 1
(binary representation: 0001), we get the result: 0101 XOR 0001 = 0100 (binary representation of 4).
The motive behind this is that when we XOR an odd number with 1, it essentially "flips" the rightmost
bit from 1 to 0. This is because odd numbers always have their least significant bit set to 1.
 When you XOR it with 1, the least significant bit changes from 1 to 0, resulting in the next lower
 even number.

XOR of an even number with 1:
=============================
Let's take an example of an even number, say 6 (binary representation: 0110). If we XOR it with
1 (binary representation: 0001), we get the result: 0110 XOR 0001 = 0111 (binary representation of 7).
The motive behind this is that when we XOR an even number with 1, it essentially "flips" the rightmost
 bit from 0 to 1. This is because even numbers always have their least significant bit set to 0.
 When you XOR it with 1, the least significant bit changes from 0 to 1, resulting in the next higher
  odd number.

In summary, XOR operations with 1 can be used as a quick way to obtain the next higher odd number
from an even number and the next lower even number from an odd number, taking advantage of the
specific bit-flipping behavior of XOR on the least significant bit.
*/

/*
||| UNIQUE NUMBER THROUGH XOR |||
---------------------------------

If you have three elements, where two of them are the same and one is different, and you want to
identify the unique one, you can use the XOR operation. This approach is efficient, especially
when dealing with integers.

int a, b, c;
// ... (initialize or input a, b, and c)
int unique = a ^ b ^ c;
*/

/*
+----------------------+
|   Twos_power check:  |
+----------------------+
To check if a number is a power of 2 in an efficient manner, you can leverage bitwise operations.
A number that's a power of 2 will have only one '1' bit when represented in binary. If we subtract
1 from this number, all bits following (and including) the '1' bit will be set to 1.
For Instance:
For n = 8 (in binary: 1000)
n - 1 = 7 (in binary: 0111)
A bitwise AND between n and n - 1 will yield 0 if n is a power of 2.
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

*/

+----------------------------------------------+
|     Two's Complement & RightMost Set Bit     |
+----------------------------------------------+
Two's Complement Representation:

For positive numbers or non-negative numbers, the two's complement representation is the same as 
the regular binary representation.

To get the two's complement of a negative number:

Write out the binary representation of its positive counterpart.
Invert all the bits (change 0s to 1s and 1s to 0s).
Add 1 to the result.
The advantage of two's complement is that the usual binary addition and subtraction operations
work without modification for negative numbers. There's no need for separate subtraction logic;
you can use addition logic to subtract by adding the two's complement representation of a number.

For example, for -5:
Binary representation of +5: 0101
Invert all bits: 1010
Add 1: 1010 + 1 = 1011
So, the two's complement representation of -5 is 1011.

To find the rightmost set bit using two's complement for a number n, the expression 
n & (-n) will give the rightmost set bit.

The reason this works is because, when taking the two's complement of n, you're inverting all bits 
up to and including the rightmost set bit, then adding 1. Adding 1 effectively resets all bits to 
the right of the rightmost set bit and leaves the rightmost set bit unchanged. So, when performing 
a bitwise AND between n and its two's complement, all bits are cleared out except the rightmost set 
bit.

For example, for the number 1100:
n = 1100
Two's complement of n: Invert 1100 to get 0011, then add 1 to get 0100. n & (-n) results in 0100.
The rightmost set bit of 1100 is 0100.

This method is efficient for finding the rightmost set bit because it involves just a few bitwise
operations.
'
#include <iostream>
using namespace std;

// Check if n is a power of 2 using two's complement
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }

// Get the rightmost set bit of n using two's complement
int rightmostSetBit(int n) { return n & (-n); }

int main() {
    int n = 12; // Example: 1100 in binary
    cout << "Is " << n << " a power of two? "
         << (isPowerOfTwo(n) ? "Yes" : "No") << endl;
    cout << "Rightmost set bit of " << n << " is: " << rightmostSetBit(n)
         << endl;
    return 0;
}

See,
for 5 = 0101 (we took 4 bits, so it remains in bound! 3 bits give -4 lowest, we need -5)
   -5 = 1011 (two's complement)
-------------
    0= 10000 (here, first 1 + 1 = 10, we take 0, now we have 1 in hand, again, 1 + 1 = 10, and so on);
We discard the out of bound fifth bit as we were working with 4 bits only. Thus, we get +5 + (-5) = 0 
in Binary. Which isn't possible with one's complement.
0101 = 1010 (one's complement)
1010 + 1 = 1011 (two's complement)'

+---------------------------------+
|          log2 and MSB           |
+---------------------------------+

When we discuss the function log2(x) in the context of computer science and binary numbers, 
it's helpful to understand the relationship between powers of 2 and binary representation.

Consider the powers of 2:

2^0 = 1 (binary: 0001)
2^1 = 2 (binary: 0010)
2^2 = 4 (binary: 0100)
2^3 = 8 (binary: 1000)

Observe the binary representation of each power of 2. Each power of 2 has a single '1' bit in its
binary representation, and the position of that '1' bit corresponds to the exponent. Each position
in a binary number represents a power of 2, starting from 2^0 at the rightmost position and
increasing to the left.

When we take the base-2 logarithm of a power of 2, we get the position (or exponent) of that single 
'1' bit:
log2(1) = 0
log2(2) = 1
log2(4) = 2
log2(8) = 3

For integer values that are powers of 2, log2(x) gives the position of the most significant set bit
(MSSB). For integers that aren't powers of 2, log2(x) returns a value corresponding to the highest
power of 2 less than x. While the logarithm result for numbers that aren't exact powers of 2 isn't
an integer, in the context of binary numbers and bit positions, the floating-point result of
log2 gets truncated to an integer, providing the MSSB position.

log2(32) => log 2 based 32 will be 5. it means 2^5 is 32.

@@@There's an alternative => __lg(n). It works on O(1);


+---------------------------------+
|          Flip a Bit             |
+---------------------------------+
We can Flip a bit by XORing it with 1.
0 ^ 1 = 1   and   1 ^ 1 = 0.



+---------------------------------+
|             BIT SET             |
+---------------------------------+

A bitset is a container that stores individual bits as boolean values (either 0 or 1). 
It's a very useful tool when you need to handle binary data or manipulate bits directly.
Key Points for bitset:

    Fixed Size: A bitset is of fixed size, determined at compile time.
    Direct Access: You can access and modify individual bits using an array-like syntax.
    Bit Operations: You can perform bitwise operations directly on bitset objects.
    String Representation: You can convert a bitset to a string of 0s and 1s.

Conversion to unsigned long (ulong)
The bitset class provides a method called to_ulong() that converts the binary
representation stored in the bitset into an unsigned long integer. This is
particularly useful when you need the integer representation of a binary sequence.
Key Points for to_ulong():

    Order Matters: The leftmost bit in the bitset is the most significant bit 
    when converting to an unsigned long.
    Throws Exception: If the binary number represented by the bitset cannot fit 
    into an unsigned long, the method throws an overflow_error exception.
    Useful for Results: After performing bit manipulations using bitset, you can 
    easily convert the result back to a numerical value using to_ulong().

An intuitive code:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        bitset<32> inv(N); // convert the integer into a binary and stores

        string helper = inv.to_string();
        reverse(helper.begin(), helper.end());

        bitset<32> rev(helper); // takes the string directly as binary number.
        cout << rev.to_ullong();
        cout << "\n";
    }
    return 0;
}
it will print a number with reverse bits.

------------------------
@ Traversing a bitset @
------------------------
 int n, k;
 cin >> n >> k;
 bitset<32> binary(n);
 for(int K = 0; K < k; K++) binary[K] = 0;
 cout << binary.to_ulong();


+---------------------------------+
|        NOT AND FLIP BITS        |
+---------------------------------+
        unsigned int n;
        cin >> n;
        n = ~n; // it will change all the 0 bits to 1, and all the 1 bits to 0
        cout << n << "\n";

int main() {
    int n;
    cin >> n;
    while(n--) {
        unsigned int x;
        cin >> x;
        unsigned int ans = 0;
        for(int k = 0; k < 32; k++) {
            if((x >> k) & 1) { // bit is 1
                               // flip to 0
            } else {           // bit is 0
                // flip to 1
                ans += 1 << k; // it works like ans |= 1 << k;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}



+---------------------------------+
|        RELATION OF AND          |
+---------------------------------+
Suppose, [1, 2, 3, 4, 5, 6].
The more we will AND elements, the more the value will be lessened
And the less, the less the value.
For OR, this is different.



+---------------------------------+
|    CHECK k-th bit SET or NOT    |
+---------------------------------+
#include <iostream>
bool isKthBitSet(int n, int k) {
    // Right shift n by k and bitwise AND with 1
    return (n >> k) & 1;

    // or,
    // // Shift 1 k-1 times to create a mask
    // int mask = 1 << (k - 1);

    // // Use bitwise AND to check if the k-th bit is set
    // return (n & mask) != 0;
}
int main() {
    int number = 5; // Example number (binary: 101)
    int k = 2;      // Bit position to check (0-indexed)
    if(isKthBitSet(number, k))
        std::cout << "The " << k + 1 << "-th bit is set.\n";
    else
        std::cout << "The " << k + 1 << "-th bit is not set.\n";
    return 0;
}


+--------------------------------------+
|   numeric_limits<int / ll>::max()    | Gives the 2^31 - 1 and 2^63 - 1 values.
+--------------------------------------+


+------------------------------------------+
|   Takes the ceiling msb and it's value   | 
+------------------------------------------+
int pw = (n & (n - 1) == 0 ? __lg(n) : __lg(n) + 1);
 pw = (1 << pw);


+------------------------------------------+
|      subtraction of bits: property '     | 
+------------------------------------------+

#include <bitset>
#include <iostream>

int main() {
    unsigned int n;
    unsigned int k;

    std::cout << "Enter the number (n): ";
    std::cin >> n;
    std::cout << "Enter the number of bits to unset (k): ";
    std::cin >> k;

    // Create the mask
    unsigned int mask = (1u << 31) - (1u << k);
    unsigned int result = n & mask;

    // Display the binary representation of the inputs and the result
    std::cout << "Original number (n): " << n
              << " (binary: " << std::bitset<32>(n) << ")" << std::endl;
    std::cout << "Mask: " << mask << " (binary: " << std::bitset<32>(mask)
              << ")" << std::endl;

    std::cout << "Modified number: " << result
              << " (binary: " << std::bitset<32>(result) << ")" << std::endl;

    return 0;
}

if we do (1 << i) - (1 << j) = (1 << i) will have one less set bit from the left and 0 to j - 1 bits will be
unset 
Suppose, 10000 = 16, 10 = 2, 16 - 2 = 14 = 1110. 



+------------------------------------------+
|       count of setbits in a number       | 
+------------------------------------------+
#include <iostream>
using namespace std;

int main() {
    int x = 29; // Binary: 11101, has 4 set bits (1-bits)
    int count = __builtin_popcount(x);
    cout << "Number of 1-bits in " << x << " is: " << count << endl;
    return 0;
}
