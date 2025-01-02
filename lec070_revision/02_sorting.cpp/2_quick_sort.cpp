#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int curr = low; curr < high; curr++)
    {
        if (arr[curr] < pivot)
        {
            i++;
            swap(arr[i], arr[curr]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}