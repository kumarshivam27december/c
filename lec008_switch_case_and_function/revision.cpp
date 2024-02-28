#include <iostream>
using namespace std;
int main()
{
	int n=5;
	int i = 1;
	while(i<=n)
	{
		int space = 1;
		while(space<=i-1)
		{
			cout<<"0"<<" ";
			space++;
		}
		int j=n-i+1;
		while(j>=1)
		{
			cout<<j<<" ";
			j--;
		}
		cout<<endl;
		i++;
	}
}
