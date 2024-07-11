#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int sum_of_natural_number(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return n+sum_of_natural_number(n-1);
}
int mean(vector<int>&arr,int n){
    if(n==1){
        return arr[n-1];

    }
    return (mean(arr,n-1)*(n-1)+arr[n-1]/n);
}
int main()
{
    clock_t tStart = clock();
    vector<int>arr = {1,2,3,4,5};
    cout<<mean(arr,5)<<endl;
    cout<<endl;
    int sum = 0;
    cout<<sum_of_natural_number(5)<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}