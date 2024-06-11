#include <bits/stdc++.h>
using namespace std;
//calculate the total number of element i.e counting it one even if it present more than once

int find_unique(vector<int>&v) {
	int cnt = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] != v[i + 1]) {
			cnt++;
		}
	}
	return cnt;
}
//couting that element only which is present only once

int find_only_one_occurence(vector<int>&v) {
	int n = v.size();
	int cnt = 1;
	if (v[0] != v[1]) cnt += 1;
	for (int i = 1; i < n - 1; i++) {
		if (v[i] != v[i + 1] && v[i] != v[i - 1]) {
			cnt += 1;
		}
	}
	return cnt;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>v;
	int t = n;
	while (t--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int cnt = 0;

	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++) {
		mp[v[i]]++;
	}

	set<int>s;
	for (int i = 0; i < n; i++) {
		s.insert(v[i]);
	}

	for (auto i : mp) {
		if (i.second == 1) {
			cnt++;
		}
	}
	//return without stl
	int len1 = find_unique(v);
	int len2 = find_only_one_occurence(v);
	cout << len1 << " " << len2 << endl;
	cout << s.size() << " " << cnt << endl;
	return 0;
}