#include <iostream>
using namespace std;

int F(int N)
{
    int a = 0, b = 1, c, i;
    if( N == 0 )
        return a;
        
    for(i = 2; i <= N; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}
// Driver code
int main()
{
    int N = 4;
     
    cout << F(N);
    return 0;
}