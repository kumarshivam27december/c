#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int size, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for (int i = 1; i < size; i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k)
                return true;
            
            lastPos = stalls[i];
        }
    }
    
    return false;
}

int aggressiveCows(int stalls[], int size, int k) {
    sort(stalls, stalls + size);
    int start = 0;
    // int end = stalls[size - 1] - stalls[0];
    int maxi = -1;

    for(int i = 0 ;i<size;i++)
    {
        maxi = max(maxi,stalls[i]);
    } 
    int end = maxi ;
    int result = -1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (isPossible(stalls, size, k, mid)) {
            result = mid;
            start = mid + 1;
        }
        else 
        {
            end = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int arr[5] = {4, 2, 1, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result = aggressiveCows(arr, size, k);
    
    cout << "Maximum distance between cows: " << result << endl;
    
    return 0;
}
