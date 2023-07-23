/*
Bit related problems: https://github.com/tanvee009/XPSC_ARCHIEVE/tree/main/WEEK%207/Day_1
//
Bitwise operator:

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
Thus, we get the outcome 0. Thus, we know that same numbers' XOR operation eliminates that
number.
Suppose, we are given an array of integers. There are pairs of numbers but a number is peerless.
6 4 5 5 9 4 9 6 2
if we approach it with brute force, it will take many grueling operations. but if we do this with
XOR, we can do it easily.
6 ^ 4 ^ 5 ^ 5 ^ 9 ^ 4 ^ 9 ^ 6 ^ 2.
we may think that we are doing XOR with random numbers. How can we find the number like this??
It's easy. suppose, 5 ^ 6 ^ 5
   first => 1 0 1
            1 1 0
            -----
            0 1 1
 second =>  1 0 1
            -----
            1 1 0, which is 6.
So, what do we understand from this. Eventually the same numbers will be cut off by XOR operations(even
numbered pairs)
suppose, we have four 5, three 3, six 8, one 2.
eventually we will have only one 3 and a 2. got it?


Trick:
& for even odd.
suppose n = 9.
if we do & of 9 and 1. it will be 1. which will determine 9 as odd.
 how?
    1 0 0 1
          1
    -------
          1

   every even number, if we convert it to binary, the last I meant MSB will be 0. if we
   & it , either 1 or 0 will be the output. 0 means even, 1 means odd.
   we might think that we are doing & with only a bit(1). but no. int contains 32 bit, thus
   this 1 have 31 more zeroes in front of it. and the number here(9), has 28 more zeroes in front of
   it.


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

we can count the set bits here by left shift, right shift and & operation with 1.
at first , we do & 1 with 1 0 1. we get 1. count++.
left shift make a number multiple of 2. <<
right shift make a number half. >>

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

/*
//Change number of bits to convert a to b

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
Let's take an example of an odd number, say 5 (binary representation: 0101). If we XOR it with 1 
(binary representation: 0001), we get the result: 0101 XOR 0001 = 0100 (binary representation of 4).
The motive behind this is that when we XOR an odd number with 1, it essentially "flips" the rightmost 
bit from 1 to 0. This is because odd numbers always have their least significant bit set to 1.
 When you XOR it with 1, the least significant bit changes from 1 to 0, resulting in the next lower 
 even number.

XOR of an even number with 1:
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