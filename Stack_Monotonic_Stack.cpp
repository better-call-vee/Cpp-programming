/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
created: 21th September, 2023 02:21:57 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{
    fast;

    int n, inp;
    cin >> n;

    stack<pair<int, int>> frst_less;
    for (int i = 1; i <= n; i++)
    {
        cin >> inp;
        if (i == 1)
        {
            frst_less.push({inp, i});

            cout << 0 << " ";
            continue;
        }

        while (!frst_less.empty() and frst_less.top().first >= inp)
            frst_less.pop();

        if (frst_less.empty())
            cout << "0 ";
        else
            cout << frst_less.top().second << " ";
        frst_less.push({inp, i});
    }

    return 0;
}

/*
-----------------------------------
| Monotonic Stack: A Quick Glance |
-----------------------------------
What is it?
A monotonic stack is a stack that preserves order (either strictly
increasing or strictly decreasing)
of its elements. In the context of our code, we're using a decreasing
monotonic stack.

Why use it?
To efficiently find the "nearest" element of interest. For our problem: the
nearest smaller element's index to the left of every number in an array.

How it works in our code?
    Stack Structure:
        Each entry in our stack is a pair: {value, index}.
        value represents the number from the array.
        index is its position.

    Traversing the Array:
        For each number:
        a. If it's the first element, there's nothing to its left. Push it to the
         stack and continue.
        b. Compare it to the top of the stack (i.e., the last number we
        were interested in).
        c. If the current number is smaller or equal, pop the stack.
        Continue this until we find a smaller number or the stack is empty.
        d. The top of the stack, if it exists after the popping, holds the nearest
        smaller element's index.

    Result:
        If the stack is empty after popping, there's no smaller element to the left. Print 0.
        Otherwise, print the index of the top element in the stack.

    Preserving Monotonic Nature:
        Regardless of the result, push the current {value, index} onto the stack.

Why is it efficient?
Each element is pushed onto and popped from the stack at most once.
 This ensures a linear time complexity: O(n)

In Essence:
Imagine walking through the numbers with a backpack (our stack).
As you walk, you only keep numbers that might be "useful" in the future (the larger ones).
Every time you see a new number, you check if it's smaller than the last one you stored.
If it is, discard the ones in the backpack until you find one that's smaller.
The position of that number is our result!
*/