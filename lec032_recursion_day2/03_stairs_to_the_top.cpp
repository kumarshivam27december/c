#include <iostream>
using namespace std;
int findstairs(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }

    return findstairs(n-1)+findstairs(n-2);
}
int main()
{
    int n;
    cin>>n;
    int ans = findstairs(n);
    cout<<ans<<endl;
    return 0;
}