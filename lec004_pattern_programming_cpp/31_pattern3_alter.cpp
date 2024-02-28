#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    int print=n*n;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            cout<<print<<" ";
            print--;
            j++;
        }
        cout<<endl;
        i++;
    }
}