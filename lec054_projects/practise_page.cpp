#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,0,1,1,0};
    int size = 5;
    //sort 0 and 1
    int start = 0;
    int end  = size-1;
    while (start<end)
    {
        while (arr[start]==0 && start<end)
        {
            start++;
        }

        while (arr[end]==1 && start < end)
        {
            end--;
        }

        if (start<end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
            //if any one condition fail it will swap
        }


        // cout<<endl;
      
        
    }

      for (int i = 0; i < size; i++)
        {
           cout<<arr[i]<<" ";
        }
        
}