#include <bits/stdc++.h>
using namespace std;

int countSUMvar(int arr[], int temp[], int left, int right)
{
    int i, j, mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count = countSUMvar(arr, temp, left, mid);
        inv_count += countSUMvar(arr, temp, mid + 1, right);
        i = left;
        j = mid + 1;
        int k = left;
        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];
        for (int i = left; i <= right; i++)
            arr[i] = temp[i];
    }
    return inv_count;
}

int countPairs(int arr[], int n, int k)
{
    int temp[n];
    countSUMvar(arr, temp, 0, n - 1);
    int i = 0, j = n - 1, count = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            count++;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < k)
            i++;
        else
            j--;
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << countPairs(arr, n, k);
    return 0;
}

