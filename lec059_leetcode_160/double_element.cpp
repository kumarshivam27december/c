#include <bits/stdc++.h>
#include <time.h>
using namespace std;
vector<int> twoRepeated(int arr[], int n)
{
    n += 2;
    unordered_set<int>ans;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(mp[arr[i]] == 2){
            ans.insert( arr[i] );
        }
    }

    vector<int> ans1;
    int j =0;
    for(auto i:ans){
        ans1.push_back(i);
        i++;
    }
    return ans1;
}
int main()
{
    clock_t tStart = clock();
    int arr[] = {3,2,1,1,4,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector out = twoRepeated(arr, n - 2);
    for (auto i : out)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}