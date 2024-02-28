#include <iostream>
using namespace std;
int intersection(int arr1[],int size1,int arr2[],int size2)
{
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(arr1[i]==arr2[j])
            {


                cout<<arr1[i]<<" ";


            }
        }
    }
    return 0;
}
int main()
{
    int arr1[4]={1,2,3,8};
    int arr2[8]={1,2,4,8,9,11,12,13};
    intersection(arr1,4,arr2,8);
    return 0;
}