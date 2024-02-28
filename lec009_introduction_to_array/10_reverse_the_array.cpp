#include <iostream>
using namespace std;
void reverseArray(int arr[],int size)
{
   for(int i=size-1;i>=0;i--)
   {
    cout<<arr[i]<<" ";
   }

}
int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<"original array "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverseArray(arr,5);
  
}