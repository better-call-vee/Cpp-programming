/*
  __builtin_clz(x):
      Stands for "Count Leading Zeros".
      Returns the number of leading zeros in the binary representation of the 32-bit integer x.
      For x = 0, the result is undefined.
      Essentially, it gives the highest bit position set in x as 32 - __builtin_clz(x).

  __builtin_ctz(x):
      Stands for "Count Trailing Zeros".
      Returns the number of trailing zeros in the binary representation of the 32-bit integer x.
      For x = 0, the result is undefined.
      It gives the position of the least significant bit set in x (0-based index).

 */

#include <iostream>
using namespace std;

int main()
{
    int x = 18; // Binary: 10010

    // Using __builtin_clz
    int leading_zeros = __builtin_clz(x);
    cout << "Number of leading zeros in " << x << " is: " << leading_zeros << endl;
    cout << "Position of most significant set bit (0-based) is: " << 31 - leading_zeros << endl;

    // Using __builtin_ctz
    int trailing_zeros = __builtin_ctz(x);
    cout << "Number of trailing zeros in " << x << " is: " << trailing_zeros << endl;
    cout << "Position of least significant set bit (0-based) is: " << trailing_zeros << endl;

    return 0;
}
