#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int product =1;

    while(n!=0)
    {
       product=product*(n%10);
       sum=sum+(n%10);
       n=n/10; 

    }
    
    //cout<<"product = "<<product<<endl;
    //cout<<"sum = "<<sum<<endl;
    cout<<"diff = "<<product-sum<<endl;

}