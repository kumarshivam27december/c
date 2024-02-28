#include <iostream>
using namespace std;
int printrowindexwithmaxsum(int arr[][3],int row,int col)
{
    int maxi = INT_MIN;
    int rowindex = -1;
    for(int row=0;row<3;row++)
    {
        int sum = 0;
        for(int col=0;col<3;col++)
        {
            sum+=arr[row][col];
        }
        if(sum>maxi)
        {
            maxi = sum;
            rowindex = row;
        }
    } 
    cout<<"max sum is "<<maxi<<endl;
    return rowindex;
}
int main()
{
    int arr[3][3];
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            cin>>arr[row][col];
        }
    }


    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }




    int ans  = printrowindexwithmaxsum(arr,3,3);
    cout<<ans<<endl;
    return 0;
}