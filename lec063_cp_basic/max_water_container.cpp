#include <iostream>
#include <vector>

using namespace std;

int maxWaterStored(vector<int>& arr, int n) {
	int left = 0, right = n - 1;
	int leftMax = 0, rightMax = 0;
	int water = 0;

	while (left < right) {
		if (arr[left] < arr[right]) {
			if (arr[left] >= leftMax)
				leftMax = arr[left];
			else
				water += leftMax - arr[left];
			left++;
		} else {
			if (arr[right] >= rightMax)
				rightMax = arr[right];
			else
				water += rightMax - arr[right];
			right--;
		}
	}

	return water;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> arr = {2, 5, 1, 0, 2, 1, 3};
	int size = arr.size();
	cout << "Total amount of water that can be stored: " << maxWaterStored(arr, size) << " units" << endl;
	return 0;
}




