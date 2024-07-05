#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void find_all(int n,vector<vector<int>>&v){
    vector<int>ans;
    for(int i = 1;i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
        }
    }
    v.push_back(ans);
}
void solve(vector<int>&arr){
    vector<vector<int>>v;

    for(int i = 0;i<arr.size();i++){
        find_all(arr[i],v);
    }


    for(int i = 0;i<=v.size();i++){
        for(int j = 0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

}
void find_divisors(vector<int>&arr){
//     vector<vector<int>>v;
//     vector<int>prime(arr.size()+1,1);
//     vector<vector<int>>divisors(arr.size()+1);
//     prime[0]=0;
//     prime[1]=1;
//     int n = *max_element(arr.begin(),arr.end());
//     for(int i = 2;i<=n;i++){
//         divisors[i].push_back(i);
//         for(int j = 2*i;j<=n;j+=i){
//             // if(prime[j]==0){
//                 prime[j]=0;
//                 divisors[i].push_back(i);
//             // }
//         }
//     }
//     // finding all the divisors and put it into vector of vectors 
//     //e.g for arr 2,15, 24,36,12
//     /*
//     output should be
//     1 2 
//     1 3 5 15 
//     1 2 3 4 6 8 12 24 
//     1 2 3 4 6 9 12 18 36 
//     1 2 3 4 6 12 

    
//     */


// //    for(int i = 0;i<arr.size()<<i++){
// //     cout<<v[arr[i]]<<" ";
// //    }

 int n = *max_element(arr.begin(), arr.end());
    
    // vector of vectors to store divisors
    vector<vector<int>> divisors(n + 1);

    // Finding divisors using a modified sieve approach
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }

    // Outputting the divisors for each element in arr
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        for (int divisor : divisors[num]) {
            cout << divisor << " ";
        }
        cout << endl;
    }
}
int main()
{
    clock_t tStart = clock();
    vector<int>arr={2,15,24,36,12};
    // solve(arr);
    find_divisors(arr);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}