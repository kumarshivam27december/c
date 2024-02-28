#include <iostream>
using namespace std;
int reverse(int n)
{
	int ans = 0;
	while(n)
	{
		int remainder = n%10;
		ans = ans * 10 + remainder;
		n/=10;
	}
	return ans;
}
int main()
{
	int n = 123;
	int ans = reverse(n);
	cout<<ans<<endl;
	return 0;
}
