#include <bits/stdc++.h>
using namespace std;
//build prefix array
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
	vector<int> prefix_sum(n);
	prefix_sum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}
	for (int i = 0; i < q; i++) {
		cout << prefix_sum[r[i]] - (l[i] - 1 >= 0 ? prefix_sum[l[i] - 1] : 0);
	}
	return 0;
}