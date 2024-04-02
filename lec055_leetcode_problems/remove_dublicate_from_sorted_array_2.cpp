#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_dublicate(vector<int> &arr){

    int index = 0;
    for (int element : arr)
    {
        if(index<2 || element!=arr[index-2]){
            arr[index++] = element;
        }
    }
    
    
   return index;
}
int main()
{
    clock_t tStart = clock();
    vector<int> arr = {0,0,0,1,1,1,2,2,3,3,3,4,4,5};
    int ans = remove_dublicate(arr);
    for (int j = 0; j < ans; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}


/*


 //find the left pointer 
    
    if(arr.size()<=2) return arr.size();
    int cow = 2;
    for(int j = 2;j<arr.size();j++){
        
        if(arr[j]!=arr[j-2]){
            arr[cow] = arr[j];
            cow++;
        }
    }
    return cow;
*/