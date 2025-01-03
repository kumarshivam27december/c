#include <bits/stdc++.h>
using namespace std;
double findmaxavg(vector<int>&arr,int size){
    double curr_sum = 0;
    for(int i = 0;i<size;i++){
        curr_sum+=arr[i];
    }

    double maxi = curr_sum/size;

    for(int k = size;k<arr.size();k++){
        curr_sum+=arr[k];
        curr_sum-=arr[k-size];
        double avgsum = curr_sum/size;
        maxi = max(avgsum,maxi);
    }
    return maxi;
}
int main() {
    vector<int>arr = {1,12,-5,-6,50,3};
    int k = 4;
    double sol = findmaxavg(arr,k);
    cout<<sol<<endl;
    return 0;
}


/*
approach 1 tle

class Solution {
public:
    double findMaxAverage(vector<int>& arr, int size) {

        int i = 0;
        int j = i + size - 1;
        double max_avg = -999999999.0;
        while (j < arr.size()) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            max_avg = max(max_avg, (((double)sum) / ((double)size)));
            cout << max_avg << endl;
            i++;
            j++;
        }
        return max_avg;
    }
};

*/