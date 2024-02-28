#include <iostream>
using namespace std;
int pow(int m,int n)
{
    int product =1;
    for(int i=0;i<n;i++)
    {
        product = product * m;

    }
    return product;
    

}
bool isPowerOfTwo(int n)
{
    int ans;
    for(int i=0;i<=32;i++)
    {
        if(n==(pow(2,i)))
        {
            return true;
            break;
        }

    }
    return false;

}
int main()
{
    int  n;
    cin>>n;
    bool ans = isPowerOfTwo(n);
    if(ans)
    {
        cout<<"it is power of two ";
    } 
    else
    {
        cout<<"it is not a power of two ";
    }

    return 0;
}