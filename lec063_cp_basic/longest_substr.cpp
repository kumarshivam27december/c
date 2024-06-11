#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int n = s.size();
	map<char, int> mp;
	int i = 0;
	int j = 0;
	int ans = 0;
	while (j < n) {
		mp[s[j]]++;
		while (mp[s[j]] > 1) {
			mp[s[i]]--;
			i++;
		}
		ans = max(ans, j - i + 1);
		j++;
	}

	cout << ans << endl;
	return 0;
}