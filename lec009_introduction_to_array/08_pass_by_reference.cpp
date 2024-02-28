#include <iostream>
using namespace std;
void updateArray(int arr[],int n)
{
    arr[0]=111;
  cout<<"The value of array in update function is "<<arr[0]<<endl;
}
int main()
{
  int arr[5]={1,2,3,4,5};
  updateArray(arr,5);  
  cout<<"value of array in main function is "<<arr[0]<<endl;
}




//here address of the array is provided 
// unlike the pass by value as it happen
//  during a value of variable is updated in  1 is not being updated in other or inside main function