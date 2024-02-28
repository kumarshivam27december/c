#include <iostream>
using namespace std;
int setbit(int n)
{
    int count=0;
    while(n)
    {
    if(n&1)
    {
        count++;
    }
      n=n>>1;
    }
    return count;

}
int totalSetBits(int a,int b)
{
    return setbit(a)+setbit(b);

}
int main()
{
    int a,b;
    cin>>a>>b;
    int total_no_of_set_bits = totalSetBits(a,b);
    cout<<"total_no_of_set_bits"<<" "<<total_no_of_set_bits<<endl;
    
} 
