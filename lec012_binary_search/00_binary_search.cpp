#include <iostream>
using namespace std;
int binarySearch(int arr[],int n, int key)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;//(start+end)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            start=mid+1;

        }
        else
        {
            end=mid-1;


        }

        mid = start + (end-start)/2;
    }
    return 0;
}

int main()
{
    int evenArray[6]={1,2,4,7,89,98};
    int oddArray[7]={2,4,7,9,80,781,987};
    int element_to_be_searched_in_even_array=4;
    int element_to_be_searched_in_odd_array=80;

    int evenindex = binarySearch(evenArray,6,element_to_be_searched_in_even_array);
    cout<<"element "<<element_to_be_searched_in_even_array<<" present at "<<evenindex<<" location "<<endl;
    int oddindex = binarySearch(oddArray,7,element_to_be_searched_in_odd_array);
    cout<<"element "<<element_to_be_searched_in_odd_array<<" present at "<<oddindex<<" location "<<endl;

    return 0;
}