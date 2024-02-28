#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    // arr = arr+1; // this is wrong 
    int *ptr = &arr[0];
    ptr = ptr + 1;
    cout<<ptr<<endl;
    return 0;
}