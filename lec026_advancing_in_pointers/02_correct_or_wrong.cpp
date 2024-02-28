#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {23,122,41,67};

    cout<<arr[1]<<endl;
    cout<<*(arr+1)<<endl;// same output
    cout<<1[arr]<<endl;
    cout<<*(1+arr)<<endl;
    return 0;
}