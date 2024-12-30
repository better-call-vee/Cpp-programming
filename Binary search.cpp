/*some binary search related problems:
https://github.com/tanvee009/XPSC_ARCHIEVE/tree/main/WEEK%2010/Day_1
https://github.com/tanvee009/XPSC_ARCHIEVE/blob/main/WEEK%2014/Day_7/Very_Easy_task.cpp
https://github.com/better-call-vee/SELF_JOURNEY/blob/main/GREAT%20ALGOS/Binary_search_kth_sum_pair.cpp
https://github.com/better-call-vee/SELF_JOURNEY/blob/main/MATH/Binary_Search_Isosceles_triangle_And_Trapezium.cpp
https://github.com/better-call-vee/SELF_JOURNEY/blob/main/GREAT%20ALGOS/Binary_search_doubles.cpp
*/

//A complete codeforces course: https://codeforces.com/edu/course/2/lesson/6

// left and right end point
/*
         lep      mid          rep
    here, 1 3 5 7 (9) 11 12 14 16

    time complexity:
    0 = n = n/2^0
    1 = n/2
    2 = n/2/2 = n/4 = n/2^2
    3 = n/8 = n/2^3
    k => n/2^k => n/2^k = 1 => n = 2^k => k = log2^n. log n
*/

// The reason that binary search has a logarithmic time complexity is that it works
// by repeatedly dividing the data set in half. Each time the data set is divided,
// the size of the data set that needs to be searched is reduced by half.
// This means that the algorithm makes logarithmically fewer comparisons as
// the size of the data set increases, which makes it much faster than an
// algorithm with a linear time complexity.
//
// For example, consider a data set with 1,000,000 elements. A linear search
// would have to make 1,000,000 comparisons to search the entire data set, while
// a binary search would only have to make around 20 comparisons (log base 2 of
// 1,000,000). This makes binary search much faster for large data sets. Not for
// small data sets


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool flag = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << "Low = " << low << " High = " << high << " Mid = " << mid << "\n";
        
        if (a[mid] == k)
        {
            cout << "\nYES " << mid << "\n";
            flag = 1;
            break;
        }

        if (a[mid] > k)
            high = mid - 1;
        else
            low = mid + 1; /// a[mid]<k
    }

    if (flag == 0)
        cout << "\nNO\n";

    return 0;
}

// Binary search can only be used on sorted data sets. If the data is not sorted,
// the algorithm will not be able to determine which half of the data to search,
// and it will not work properly

/*
9 11
1 3 5 7 9 11 12 14 16
*/

// The best case complexity for a binary search algorithm is O(1), which means
// that the algorithm takes constant time to search the data. This occurs when
// the element being searched for is the first element in the data set. In this
// case, the algorithm will only make one comparison, and it will immediately find
// the element it is searching for.
//
// In the worst case, the complexity of binary search is O(log n), where n is the
// size of the data set. This occurs when the element being searched for is not
// present in the data set, or when it is the last element in the data set. In
// this case, the algorithm will have to divide the data set in half repeatedly
// until it determines that the element is not present, which will take
// logarithmic time.
//
// On average, the complexity of binary search is also O(log n), as this is the
// average number of comparisons that will be needed to find an element in the
// data set.
