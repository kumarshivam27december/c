#include <iostream>
using namespace std;
void fibo(int n,int a=0,int b=1)
{
	if(n>0)
	{
		cout<<a<<" ";
		fibo(n-1,b,a+b);
	}
}
int main()
{
	int n;
	cin>>n;
	fibo(n);
	return 0;
}
