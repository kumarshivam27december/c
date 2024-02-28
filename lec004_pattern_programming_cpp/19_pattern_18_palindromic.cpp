#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int space = n-1;
        while(space)
        {
            cout<<" ";
            space--;
        }
        int tri = 1;
        while(tri<=i)
        {
            cout<<tri;
            tri++;
        }
        cout<<endl;
        i++;
    }
}