#include <iostream>
using namespace std;
int unionArray(int arr1[],int n1,int arr2[],int n2)
{
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            cout<<arr2[j]<<" ";
            j++;
        }
        else 
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }

        while(i<n1)
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        while(j<n2)
        {
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    return 0;
}
int main()
{
    int arr1[3]={1,2,3};
    int arr2[6]={1,2,4,5,6,8};
    unionArray(arr1,3,arr2,6);
    return 0;

}