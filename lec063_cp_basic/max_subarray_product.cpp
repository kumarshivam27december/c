#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int t;
	cin >> t; int n = t; vector<int>arr;
	while (t--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int leftproduct = 1;
	int rightproduct = 1;
	int ans = arr[0];

	for (int i = 0; i < n; i++) {
		leftproduct = leftproduct == 0 ? 1 : leftproduct;
		rightproduct = rightproduct == 0 ? 1 : rightproduct;

		//prefix_product
		leftproduct *= arr[i];

		//suffix prosuct
		rightproduct *= arr[n - i - 1];

		ans = max(ans, max(leftproduct, rightproduct));
	}
	cout << ans << endl;
	return 0;
}