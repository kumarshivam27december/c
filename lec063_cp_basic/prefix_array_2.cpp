#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n; vector<int>arr;
	while (n--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int p, q, r;
	cin >> p >> q >> r;
	vector<int>parr(n), rarr(n);
	for (int i = 0; i < n; i++) {
		parr[i] = arr[i] * p;
		rarr[i] = arr[i] * r;
	}

	vector<int>prefix_max(n), suffix_max(n);


	prefix_max[0] = parr[0];
	for (int i = 1; i < n; i++) {
		prefix_max[i] = max(prefix_max[i - 1] , parr[i]);

	}

	suffix_max[n - 1] = rarr[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		suffix_max[i] = max(suffix_max[i + 1] , rarr[i + 1]);
	}


	int ans = 1000000;
	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, q * arr[i] + prefix_max[i - 1] * suffix_max[i + 1]);
	}
	cout << ans << endl;

	return 0;
}