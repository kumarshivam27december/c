/*
       1
     2 3
   4 5 6
 7 8 9 10 


*/
#include <iostream>
using namespace std;
int main()
{
    int n=4;
    int toprint = 1;
    int i=1;
    while(i<=n)
    {
        int space = n-i;
        while(space)
        {
            cout<<" "<<" ";
            space--;
        }
        int j = 1;
        while(j<=i)
        {
            cout<<toprint<<" ";
            toprint++;
            j++;
        }
        cout<<endl;
        i++;
    }
}