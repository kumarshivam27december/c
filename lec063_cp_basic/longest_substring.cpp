#include <bits/stdc++.h>
using namespace std;
bool checkchar(string str, char ch) {
	for (auto i : str) {
		if (i == ch) {
			return true;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	string str;
	cin >> str;
	set<char>st;

	int maxi = INT_MIN;
	for (int i = 0; i < str.size(); i++) {
		string ans = "";
		char ch = str[i];
		if (!checkchar(ans, ch)) {
			ans += str[i];
		} else {
			break;
		}
		int k = ans.size();
		maxi = max(maxi, k);
	}

	cout << maxi << endl;
	return 0;


}

