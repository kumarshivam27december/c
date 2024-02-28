#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    long long int ans = 0;
    while(x){
    int lastdigit=x%10;
    ans=ans*10+lastdigit;
    if(ans>INT_MAX||ans<INT_MIN)
        return 0;
    x/=10;
    
    }
    ans=x<0?-(ans):ans;
    cout<<ans<<endl;

}