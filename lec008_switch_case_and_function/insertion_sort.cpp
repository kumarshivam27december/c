#include <iostream>
using namespace std;
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void insertionsort(int arr[],int n)
{
	for(int i = 1;i<n;i++)
	{
		int temp = arr[i];
		int j = i-1;
		for(;j>=0;j--)
		{
			if(arr[j]>temp)
			{//shift
				arr[j+1] = arr[j];
			}
			else
			{
				break;	
			}
		}
		arr[j+1] = temp;
	}
}
int main()
{
	int arr[6] = {7,1,9,4,3,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	insertionsort(arr,size);
	printarray(arr,size);
	return 0;
}
