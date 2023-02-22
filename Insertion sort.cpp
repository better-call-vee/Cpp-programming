#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    insertionSort(arr, n);
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}

//Insertion sort is a simple sorting algorithm that builds the final sorted array
//(or list) one item at a time. It is similar to how we sort playing cards in our
//hands.
//
//The function "insertionSort" takes in an array "arr" and the size of the array
//"n" as input parameters. It starts with the second element of the array
//(index 1) and assigns it to the variable "key". Then it sets the variable "j"to
//the index of the previous element (i-1).
//
//The while loop then starts, where it checks if the value of "j" is greater than
//or equal to 0 and if the value at the index "j" of the array is greater than
//the value of "key". If both conditions are true, it shifts the value at index
//"j" to the next index (j+1) and decrements the value of "j" by 1. This loop
//continues until the value at index "j" is no longer greater than the value of
//"key" or "j" is no longer greater than or equal to 0.
//
//Finally, the value of "key" is inserted into the array at the index "j+1".
//This process is repeated for the next element in the array until all elements
//have been sorted.
//
//Example:
//arr = [5, 2, 9, 1, 3]
//n = 5
//
//First Iteration:
//i = 1, key = 2, j = 0
//while loop:
//arr[j] = arr[0] = 5 which is greater than 2, so 5 is shifted to the right by
//one position,
//j = -1
//then arr = [5, 5, 9, 1, 3]
//arr[j+1] = arr[0] = 2
//arr = [2, 5, 9, 1, 3]
//
//Second Iteration:
//i = 2, key = 9, j = 1
//while loop: not executed,
//arr = [2, 5, 9, 1, 3]
//
//Third Iteration:
//i = 3, key = 1, j = 2
//while loop:
//arr[j] = arr[2] = 9 which is greater than 1, so 9 is shifted to the right by
//one position,
//j = 1
//then arr = [2, 5, 9, 9, 3]
//arr[j+1] = arr[2] = 1
//arr = [2, 5, 1, 9, 3]
//
//Fourth Iteration:
//i = 4, key = 3, j = 3
//while loop:
//arr[j] = arr[3] = 9 which is greater than 3, so 9 is shifted to the right by
//one position,
//j = 2
//then arr = [2, 5, 1, 9, 9]
//arr[j+1] = arr[3] = 3
//arr = [2, 5, 1, 3, 9]
//
//arr = [2, 5, 1, 3, 9] is now sorted.
