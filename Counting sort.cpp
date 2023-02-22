//counting sort doesn't work on negative numbers

#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int output[n]; // output array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1]; // create count array (max+1 number of elements)

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

//suppose the input [4, 2, 3, 3, 0]
//16 line loop=> count:[1, 0, 1, 2, 1]

///19 line loop=> count:[1, 1, 2, 4, 5]

//This means that there is 1 element in the input array that is less than or equal
//to 0, 1 element that is less than or equal to 1, 2 elements that are less than
//or equal to 2, 4 elements that are less than or equal to 3 and 5 elements that
//are less than or equal to 4 in the input array.

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
//The second for loop iterates through the input array in reverse order. It takes
//each element from the input array, checks its position in the count array and
//places it in the output array on that position.
//So, for example, it takes the last element of the input array which is 0 and
//checks its position in the count array which is 1, then places it in the output
//array on position (count[0]-1) which is (1-1) = 0th position. Then it decrements
//the count of 0 by 1. Next, it takes the second last element 3 and check its
//position in the count array which is 4, then places it in the output array on
//position (count[3]-1) which is (4-1) = 3rd position. Then it decrements the
//count of 3 by 1.

//output = [0, 2, 3, 3, 4]
///position 0  1  2  3  4
//so, look at the sorted array and the 25th line. after the one 0, 2's position
//is being 1 in the sorted array. then 3's position is being 2 and 3. which are 1
//less than the 19th line loop's count array's elements.that's how it works.

//count[arr[i]] - 1: Subtracting 1 from the count of elements less than or equal
//to the value of the current element gives the correct position of the current
//element in the output array. This is because the output array is zero-indexed,
//and counting sort algorithm starts counting from 1.

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
