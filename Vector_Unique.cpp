//https://www.codechef.com/problems/LARGESECOND

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

    while (t--)
    {
        int N;
        cin >> N;

        vector<int> A(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];

        sort(A.begin(), A.end(), greater<>());

        auto Duplis = unique(A.begin(), A.end());
        /*
        After sorting the array, we apply the unique function to remove duplicates. The
        unique function works by rearranging the elements so that all unique elements appear first
        in the range, and then it returns an iterator pointing to the element one past the last unique
        element.
        I mean it generally moves back the unique elements to the front and then a pointer (here the
        Duplis) is from where the duplicates are stored.
        */
        A.erase(Duplis, A.end()); // finally we delete all the duplicates though it isn't
        //necessary here, because we need only the sum of max 2 numbers.

        cout << A[0] + A[1] << "\n";
    }

    return 0;
}