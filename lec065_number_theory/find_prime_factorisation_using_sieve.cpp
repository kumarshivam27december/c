#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int main()
{
    //pre-compute the lpf
    clock_t tStart = clock();
    vector<int>lpf(1e6+1);
    // find lpf

    vector<vector<int>>v;
    vector<int>arr={3,15,24,36,60};
    
    for(int i = 0;i<arr.size();i++){
        vector<int>ans;
        while(arr[i]!=1){
            ans.push_back(lpf[arr[i]]);
            arr[i]=arr[i]/lpf[arr[i]];
        }
        v.push_back(ans);
    }


    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}

// find the lowest prime factor of each number and store it 
// in an vector of size 1e6;