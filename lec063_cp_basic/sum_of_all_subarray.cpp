/*

n=4
2 1 3 2
sum of all subarray sum in cpp
2 1 3 2
2 1   2 3  2 2=
2 1 3   2 1 2 = 6+5=11
2 1 3 2 = 8


*/
#include <iostream>
#include <vector>

using namespace std;

int sumOfSubarrays(vector<int>& arr) {
	int n = arr.size();
	int totalSum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				totalSum += arr[k];
			}
		}
	}
	return totalSum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	vector<int> arr;
	while (t--) {
		int n;
		cin >> n;
		arr.push_back(n);
	}
	cout << "Sum of all subarrays: " << sumOfSubarrays(arr) << endl;
	return 0;
}






/*

int sumOfSubarrays(vector<int>& arr) {
	int n = arr.size();
	int totalSum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subarraySum = 0;
			for (int k = i; k <= j; k++) {
				subarraySum += arr[k];
			}
			totalSum += subarraySum;
		}
	}
	return totalSum;
}




*/