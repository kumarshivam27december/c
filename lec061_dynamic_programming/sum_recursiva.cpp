#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int helper(vector<int>&num,int s){
    if(s<0) return 0; 

    return num[s-1]+helper(num,s-=1); 
}
int summ(vector<int>&num){
    int s = num.size();
    return helper(num,s);
}
int main()
{
    clock_t tStart = clock();
    vector<int> num={2,1,4,5};
    cout<<summ(num);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}