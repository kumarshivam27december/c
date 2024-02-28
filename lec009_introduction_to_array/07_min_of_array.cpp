#include <iostream>
using namespace std;
void minArray(int arr[],int n)
{
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
           min=arr[i];
        }
    }
    cout<<"min of the array is "<<min<<endl;

}
int main()
{
    int array[11]={0,2,-9,7,-90,-6,-3,4,-1,-22,87};
    minArray(array,11);
}