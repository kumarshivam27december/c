#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;    
    int left = 2 * i + 1;  
    int right = 2 * i + 2;    

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
       swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteElements(vector<int>& arr, int minr, int maxr) {
    arr.erase(remove_if(arr.begin(), arr.end(), [&](int x) { return x < minr || x > maxr; }), arr.end());
}

void rearrangeMaxHeap(vector<int>& arr) {

    buildMaxHeap(arr);
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
       cin >> arr[i];
    }
    int minr, maxr;
    cin >> minr;
    cin >> maxr;
    buildMaxHeap(arr);
    deleteElements(arr, minr, maxr);
    rearrangeMaxHeap(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
