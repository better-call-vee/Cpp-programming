#include<bits/stdc++.h>

int main() {
  int x = 6;  // binary 110
  int count = __builtin_popcount(x);
  std::cout << "The number of set bits in " << x << " is " << count << std::endl;
  return 0;
}


//int x = 6;  // binary 110
//x = x & (x - 1);  // binary 100
//x = x & (x - 1);  // binary 000
//In the first operation, x is 6 (binary 110) and x - 1 is 5 (binary 101).
//The bitwise AND operation sets the result to 4 (binary 100), which has the least
//significant set bit cleared.
//
//In the second operation, x is 4 (binary 100) and x - 1 is 3 (binary 011).
//The bitwise AND operation sets the result to 0 (binary 000), which has no set bits.
//
//This is how the popcount function is able to count the number of set bits in the
//input x. It repeatedly performs a bitwise AND operation on x and x - 1 until x
//becomes 0, and the number of iterations is equal to the number of set bits in x.
//AND --> 1 & 1 = 1, 0 & 1 = 0, 0 & 0 = 0
