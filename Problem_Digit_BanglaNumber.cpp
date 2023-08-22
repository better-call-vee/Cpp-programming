/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1042
*/

#include <bits/stdc++.h>
using namespace std;

void banglaNumber(long long X)
{
    if (X > 9999999)
    {
        cout << " " << X / 10000000 << " kuti";
        X %= 10000000;
    }
    if (X > 99999)
    {
        cout << " " << X / 100000 << " lakh";
        X %= 100000;
    }
    if (X > 999)
    {
        cout << " " << X / 1000 << " hajar";
        X %= 1000;
    }
    if (X > 99)
    {
        cout << " " << X / 100 << " shata";
        X %= 100;
    }
    if (X < 100 && X > 0)
        cout << " " << X;
}

int main()
{
    long long N;
    int i = 0;

    while (cin >> N)
    {
        cout << setw(4) << ++i << ".";

        if (N == 0)
        {
            cout << " 0" << endl;
            continue;
        }

        if (N > 9999999) //if the number is bigger than 1 99 lakh 99 hajar 9 shata 99,
        //then we have to count for kuti.
        {
            banglaNumber(N / 10000000); //suppose, 45897458973958. banglaNumber(4589745).
            cout << " kuti";
            N %= 10000000;
        }
        banglaNumber(N); //and the modded part will be the part from lakh to last.(8973958)
        cout << endl;
    }

    return 0;
}

/*
setw is a  manipulator in C++ that sets the field width for the next output operation.
When you use cout << setw(4) << ++i << ".";, it ensures that the integer i will be printed in a
field width of 4 characters. If i is less than 4 characters wide, it will be right-justified,
with the spaces on the left. This is particularly useful for formatting output in a tabular
form or when you want to align numbers correctly.
84832
   1. 84 hajar 8 shata 32
2332
   2. 2 hajar 3 shata 32
323
   3. 3 shata 23
453
   4. 4 shata 53
2423
   5. 2 hajar 4 shata 23
23233
   6. 23 hajar 2 shata 33
323232
   7. 3 lakh 23 hajar 2 shata 32
23232323
   8. 2 kuti 32 lakh 32 hajar 3 shata 23
23244355
   9. 2 kuti 32 lakh 44 hajar 3 shata 55
334242312
  10. 33 kuti 42 lakh 42 hajar 3 shata 12
22324425
  11. 2 kuti 23 lakh 24 hajar 4 shata 25
*/