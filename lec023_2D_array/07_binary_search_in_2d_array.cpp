#include <iostream>
using namespace std;
int ispresent(int arr[][4],int row,int  col,int target)
{
    int start = 0;
    int end = row*col-1;
    int mid = start + (end-start)/2;
    while(start<=end)
    {
      int element = arr[mid/col][mid%col];

      if(element == target)
      {
        return 1;
      }
      else if (element<target)
      {
        start=mid +1;
      }
      else if (element>target)
      {
        end = mid -1;
      }
      mid = start + (end - start)/2;
    }

    return 0;
}
int main()
{
    int  arr[3][4];
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            cin>>arr[row][col];
        }
    }

    int target;
    cout<<"enter key to find ";
    cin>>target;
    int ans = ispresent(arr,3,4,target);
    if(ans)
    {
        cout<<"element is present"<<endl;
    }
    else
    {
        cout<<"element is not present"<<endl;
    }
    return 0;
}