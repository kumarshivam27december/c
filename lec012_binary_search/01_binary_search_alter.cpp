#include <iostream>
using namespace std;
int binarySearch(int  arr[], int n, int key)
{
	int s = 0;
	int e = n-1;
	int mid = s + (e-s)/2;
	while(s<=e)
	{
		if(arr[mid]==key)
		{
			
			cout<<mid<<endl;
			
		}
		else if(arr[mid]>key)
		{
			e=mid-1;
			
		}
		else
		{
			s=mid+1;
		}
		
		mid=s+(e-s)/2;
	}
	
	return -1;
}
int main()
{
	int arr[7]={1,3,24,56,78,96};
	int key =3;
	binarySearch(arr,7,key);
	return 0;
}