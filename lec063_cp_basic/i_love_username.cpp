#include <bits/stdc++.h>
using namespace std;
bool checkmin(vector<int>&v, int index, int num) {
	for (int i = 0; i < index; i++) {
		if (v[i] >= num) {
			return false;
		}
	}
	return true;
}
bool checkmax(vector<int>&v, int index, int num) {
	for (int i = 0; i < index; i++) {
		if (v[i] <= num) {
			return false;
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	cin >> t; vector<int>v; int cnt = 0;
	while (t--) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	for (int i = 1; i < v.size(); i++) {
		bool check1 = checkmin(v, i, v[i]);

		bool check2 = checkmax(v, i, v[i]);
		if (check1 || check2) {
			cnt++;
		}

	}
	cout << cnt;
	return 0;
}