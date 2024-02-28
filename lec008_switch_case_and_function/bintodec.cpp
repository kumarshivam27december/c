#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n = 101;
	int ans = 0;
	int 	i = 0 ;
	while(n!=0)
	{
	
		int digit = n%10;
		if(digit)
		{
			ans = ans + pow(2,i);
		}
		
		i++;
		n/=10;
	}
	cout<<ans<<endl;
}
