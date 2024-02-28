#include <iostream>
using namespace std;
void countprint(int n)
{
    //base condition
    if (n==0)
    {
        return ;
    }

    cout<<n<<" ";
    //recursive relation
    countprint(n-1);
    
}
int main()
{
    int n;
    cin>>n;
    cout<<'\n';
    countprint(n);
    return 0;
}