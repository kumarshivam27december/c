#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	// int t;
	// cin >> t;
	// int target;
	// cin >> target;
	// int sze = t;
	// vector<int>v;
	// while (t--) {
	// 	int n;
	// 	cin >> n;
	// 	v.push_back(n);
	// }

	// int cnt = 0;
	// for (int i = 0; i < sze; i++) {

	// 	for (int j = i; j < sze; j++) {
	// 		int sum = 0;
	// 		for (int k = i; k <= j; k++) {
	// 			sum += v[k];
	// 		}
	// 		if (sum == target) {
	// 			cnt += 1;
	// 		}
	// 	}


	// }


	// vector<int>prefix(sze);
	// prefix[0] = v[0];
	// for (int i = 0; i < sze; i++) {
	// 	prefix[i] = prefix[i - 1] + v[i];
	// }

	// int len = 0;
	// unordered_map<int, int>mp; int sum = 0;
	// for (int i = 0; i < sze; i++) {
	// 	sum += v[i];
	// 	int ans = sum - target;
	// 	// int temp = v[i];

	// 	if (mp.find(ans) != mp.end()) {

	// 		len += mp[ans];
	// 	}
	// 	mp[sum]++;

	// }

	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k ;
	cin >> k;
	map<int, int>mp;
	int sum = 0;
	mp[0] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (mp.count(sum - k)) {
			ans += mp[sum - k];
		}
		mp[sum]++;
	}
	cout << ans << endl;






	// cout << cnt << endl;
	// cout << len << endl;
	return 0;
}
/*
8
7
2 5 -7 2 3  2 -7 7

*/