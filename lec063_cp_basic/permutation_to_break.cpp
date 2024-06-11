#include <bits/stdc++.h>
#include <set>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n; vector<int>v;
	while (n--) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	set<int>st;
	for (int i = 0; i < v.size(); i++) {
		st.insert(v[i]);
		int iterator = *st.begin();

	}







	return 0;
}