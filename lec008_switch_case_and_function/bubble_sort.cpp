#include <iostream>
using namespace std;
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void bubblesort(int arr[],int n)
{
	for(int i = 0;i<n-1;i++)
	{
		bool swapped = false;
		for(int j = 0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
			
			swapped  =true;
		}
		if(swapped==false)
		{
			break;
		}
	}
}
int main()
{
	int arr[4] = {7,4,2,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,size);
	printarray(arr,size);
	return 0;
}
