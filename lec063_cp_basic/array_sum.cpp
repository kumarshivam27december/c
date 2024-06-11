#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int sum = 0;
	vector<int>arr;
	while (n--) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	for (int i = a; i <= b; i++) {
		sum += arr[i];
	}
	cout << sum;
}