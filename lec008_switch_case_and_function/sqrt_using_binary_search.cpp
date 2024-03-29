#include <iostream>
using namespace std;
long long int sqrtInteger(int n)
{
	int s = 0;
	int e = n-1;
	long long int mid = s + (e-s)/2;
	
	long long int ans = -1;
	while(s<=e)
	{
	long long int square = mid * mid ;
		if(square==n)
		{
			return mid;
		}
		else if(square>n)
		{
			
			e = mid -1;
		}
		else
		{
			ans = mid;
			s = mid + 1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
	
}
double moreprecision(int n,int precision,int tempans)
{
	double factor = 1;
	double ans = tempans;
	for(int i=0;i<precision;i++)
	{
		factor = factor / 10;
		for(int j=ans; j*j<n ;j=j+factor)
		{
			ans = j;
		}
	}
	return ans;
}
int main()
{
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	int tempans = sqrtInteger(n);
	cout<<tempans<<endl;
	cout<<"Answer is "<<moreprecision(n,3,tempans)<<endl;
	return 0;
}
