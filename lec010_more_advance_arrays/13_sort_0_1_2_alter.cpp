#include <iostream>
#include <algorithm>  // Include the header file for swap()
using namespace std;
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sortArray(int arr[], int n) {
    
    for(int j=0;j<n;j++)
    {
    	int i = 0;
    while (i + 1 < n) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
        i++;
    }
}
}

int main() {
    int arr[5] = {2, 2, 1, 0, 0};
    sortArray(arr, 5);
    printArray(arr,5);

    return 0;
}
