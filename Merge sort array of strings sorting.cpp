#include <iostream>
#include <string>
using namespace std;

void merge(string arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1; // length of left subarray
    int n2 = right - middle; // length of right subarray
    string L[n1], R[n2]; // create temporary arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i]; // copy elements of left subarray
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[middle + 1 + j]; // copy elements of right subarray
    }
    int i = 0; // initial index of left subarray
    int j = 0; // initial index of right subarray
    int k = left; // initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])   // compare elements from left and right subarrays
        {
            arr[k] = L[i]; // add smaller element to merged subarray
            i++; // increment index of left subarray
        }
        else
        {
            arr[k] = R[j]; // add smaller element to merged subarray
            j++; // increment index of right subarray
        }
        k++; // increment index of merged subarray
    }
    while (i < n1)   // add any remaining elements from left subarray
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)   // add any remaining elements from right subarray
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right); //here first understand this step
    //with the whole and final array. then understand dividing into parts.
    //suppose this example:
    //4
    //date cherry apple banana
    //understand by left=0, middle=1, right=3.
    //then consider, how at first they get divided and sorted. and then get merged
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
