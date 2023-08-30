/*
https://lightoj.com/problem/discovering-permutations
   +----------------------+
  /                        \
 /    *   TANVEE009   *     \
 \  **  I CAN, I WILL  **   /
  \  +-----------------+   /
   +----------------------+
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

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int N, K;
        cin >> N >> K;

        cout << "Case " << i << ":\n";

        vector<char> chars(N);
        for (int i = 0; i < N; i++)
            chars[i] = char(65 + i);

        for (char org : chars)
            cout << org;
        cout << "\n";

        for (int i = 1; i < K && next_permutation(chars.begin(), chars.end()); ++i)
        {
            for (char perm : chars)
                cout << perm;
            cout << "\n";
        }
    }

    return 0;
}

/*
the elements must have to be sorted before using next_permutation.
next_permutation function is used to generate the next lexicographically greater permutation of a
given sequence.
suppose, it's given 1 2 3 4.
we start and generate the permutations from here. first it compares 4 and 3 and swaps. 1 2 4 3.
and it goes on until we get the greatest lexicographical permutation => 4 3 2 1(descendingly
sorted)
thus do {} while () is used so that it can print the 4 3 2 1 (descended) permutation first and
then break the loop;
So,
It starts from the end of the sequence and searches for the first pair of adjacent elements, where
the left element is smaller than the right.
It then swaps this left element (pivot) with the smallest element found to its right that's
greater than the pivot.
Finally, it reverses the portion of the sequence after the pivot's original position to achieve
the next permutation
True: If the sequence has a next permutation, the function modifies the sequence in-place and returns
true.
False: If the sequence is already in its lexicographically greatest permutation (sorted in descending
 order), the function resets it to the smallest permutation (ascending order) and returns false

 #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> sequence = {1, 2, 3, 4};

    // Sort the sequence if not already sorted.
    sort(sequence.begin(), sequence.end());

    do {
        // Print current permutation
        for(int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";

    } while(next_permutation(sequence.begin(), sequence.end()));

    return 0;
}
*/