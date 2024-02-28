/*

2. Write a program in C to calculate the sum of numbers from 1 to n using recursion.
Test Data :
Input the last number of the range starting from 1 : 5
Expected Output:

The sum of numbers from 1 to 5 : 
15


*/
#include <iostream>
using namespace std;
int findsum(int n)
{
    //base case
    if(n==0)
    {
        return 0;
    }

    //recursive call
    return n+findsum(n-1);

    
}
int main()
{
    int n;
    cin>>n;
    int ans = findsum(n);
    cout<<ans<<endl;
    return 0;
}