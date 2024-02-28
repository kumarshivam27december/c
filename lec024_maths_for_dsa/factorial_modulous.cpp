#include <iostream>
using namespace std;
int fact(int n)
{
    long long int m = 1000000007; 
    int product = 1;
    for(int i=1;i<=n;i++)
    {
        product = ((product)%m *(i)%m)%m;
    }
    return product;
}
int main()
{
    int num;
    cin>>num;
    int ans  = fact(num);
    cout<<"factorial % (10^9 + 7) = "<< ans <<endl;
}