#include <iostream>
#include <vector>
using namespace std;
void print(int arr[][3],int n,int m)
{
	int i=0;
	for(i=0;i<3;i++)
	{
		int j=0;
		for(j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}	
}


vector<int> rotate(int arr[][3],int n,int m)
{
	
	int row=arr.size();
	int col=arr[0].size();
	int count = 0;
	int total = row*col;
	int startingrow = 0;
	int endingrow = row-1;
	int startingcol = 0;
	int endingcol = col-1;
	while(count<total)
	{
		vector<int> ans;
		
		//printing starting col 
		
		int index = endingrow
		for(;index>=startingrow;index--)
		{
			ans.push_back(arr[index][staringcol]);
			count++;
		}
		startingcol++;
		
	}
	
	return ans;
}
int main()
{
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

	print(arr,3,3);
	
	
}
