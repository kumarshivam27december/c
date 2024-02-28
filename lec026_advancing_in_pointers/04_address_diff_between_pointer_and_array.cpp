#include <iostream>
using namespace std;
int main()
{
    int a[20] = {1,2,3,5};
    cout<<&a[0]<<endl;
    int *ptr =  &a[0];
    cout<<&ptr<<endl;// this is different
return 0;
}