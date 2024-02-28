/*

        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1

*/
#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int i = 1;
    while(i<=n)
    {
        int space = n-i;
        while(space)
        {
            cout<<" "<<" ";
            space--;
        }
        int first = 1;
        while(first<=i)
        {
            cout<<first<<" ";
            first++;
        }
        int second = 1;
        while(second<=(i-1))
        {
            cout<<(i-second)<<" ";
            second++;
        }
        cout<<endl;
        i++;
    }
}