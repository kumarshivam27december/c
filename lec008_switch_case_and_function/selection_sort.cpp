#include <iostream>
using namespace std;
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void selectionsort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int minIndex  = i;
		for(int j= i+1;j<n;j++)
		{
			if(arr[minIndex]>arr[j])
			{
				minIndex=j;
			}
          
		}
		swap(arr[i],arr[minIndex]);
	}
}
int main()
{
	int arr[4] = {7,4,8,3};
	int size  = sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr,4);
	printarray(arr,4);
	return 0;
}
