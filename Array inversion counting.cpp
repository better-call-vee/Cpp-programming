#include<bits/stdc++.h>

using namespace std;

// Function to count the number of inversions using merge sort
long long countInversions(int arr[], int temp[], int left, int right);

// Function to merge two sorted arrays and count the number of inversions
long long merge(int arr[], int temp[], int left, int mid, int right);

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// create a temporary array
	int temp[n];

	cout << countInversions(arr, temp, 0, n - 1) << endl;

	return 0;
}

// Function to count the number of inversions using merge sort
long long countInversions(int arr[], int temp[], int left, int right)
{
	long long count = 0;

	if (right > left)
	{
		// divide the array into two halves
		int mid = (right + left) / 2;

		// sort the left half
		count += countInversions(arr, temp, left, mid);

		// sort the right half
		count += countInversions(arr, temp, mid + 1, right);

		// merge the sorted halves and count the number of inversions
		count += merge(arr, temp, left, mid + 1, right);
	}

	return count;
}

// Function to merge two sorted arrays and count the number of inversions
long long merge(int arr[], int temp[], int left, int mid, int right)
{
	int i = left, j = mid, k = left;
	long long count = 0;

	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];

			// count the number of inversions
			count += (mid - i);
		}
	}

	// copy the remaining elements, if any
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	// copy the sorted temp array to the original array
	for (int i = left; i <= right; i++)
		arr[i] = temp[i];

	return count;
}

