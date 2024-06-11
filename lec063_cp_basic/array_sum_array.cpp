#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int q;
	cin >> q;
	vector<int> l(q);
	vector<int> r(q);
	for (int i = 0; i < q; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < q; i++) {

		int sum = 0;

		for (int j = l[i]; j <= r[i]; j++) {
			sum += arr[j];
		}

		cout << sum << endl;
	}
	return 0;
}


//build prefix arrays
