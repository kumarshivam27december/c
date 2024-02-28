#include <iostream>
using namespace std;
void print(int n)
{
    //base condition
    if (n==0)
    {
       return;
    }

    //recursive relation

    print(n-1);

    cout<<n<<" ";

    
}
int main()
{
    int n;
    cin>>n;
    cout<<endl;
    print(n);
    return 0;
}