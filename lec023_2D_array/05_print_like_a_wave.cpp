#include <iostream>
using namespace std;
void printlikewave(int arr[][3],int nrow,int mcol)
{
    for (int col = 0; col < mcol; col++)
    {
        if(col&1)
        {
            for(int row= nrow-1;row>=0;row--)
            {
                cout<<arr[row][col]<<" ";
            }cout<<endl;
        }
        else
        {
            for(int row=0;row<nrow;row++)
            {
                cout<<arr[row][col]<<" ";
            }cout<<endl;

        }
    }
    
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
        }cout<<endl;
    }
    cout<<endl;cout<<endl;cout<<endl;cout<<endl;
    printlikewave(arr,3,3);
    return 0;
}