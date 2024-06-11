#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	vector<int>v;
	while (t--) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	// int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++) {
			for (int k = i; k <= j; k++) {
				cout << v[k] << " ";
				// sum += v[k];
			} cout << endl;
		}
		cout << endl;
	}

	// cout << sum << endl;
	return 0;
}