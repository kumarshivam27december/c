#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>arr;
	while (n--) {
		// 5 5 5 5 5 1

		int num;
		cin >> num;
		arr.push_back(num);
	}


	for (auto i : arr) {
		cout << i << " ";
	} cout << endl;

	vector<int> prefix_arr(arr.size());

	prefix_arr[0] = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		prefix_arr[i] = max(prefix_arr[i - 1], arr[i]);
	}
	vector<int> suffix_arr(arr.size());


	suffix_arr[arr.size() - 1] = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i >= 0; i--) {
		suffix_arr[i] = max(suffix_arr[i + 1], arr[i]);
	}


	cout << endl;


	for (auto i : prefix_arr) {
		cout << i << " ";
	} cout << endl;

	for (auto i : suffix_arr) {
		cout << i << " ";
	} cout << endl;


	// 2 1 0 3 5 1
	// 2 2 2 3 5 5
	// 5 5 5 5 5 1
	int total = 0;
	for (int i = 0; i < arr.size(); i++) {
		total += (min(prefix_arr[i], suffix_arr[i]) - arr[i]) > 0 ? (min(prefix_arr[i], suffix_arr[i]) - arr[i]) : 0;
	}
	cout << total << endl;
	return 0;
}