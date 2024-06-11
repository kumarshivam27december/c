#include <bits/stdc++.h>
using namespace std;
bool check(string str) {
	//check all caps or first letter cap and all small else false
	if (str[0] >= 97 && str[1] <= 123) {
		for (int i = 1; i < str.size(); i++) {
			if (str[i] >= 97 && str[i] <= 123) {
				return false;
			}
		}
	} else {
		//first capital all capital
		for (int i = 1; i <= str.size(); i++) {
			if (str[i] >= 97 && str[i] <= 123) {
				return false;
			}
		}
	}
	return true;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	string str;
	cin >> str;
	bool b = check(str);
	string ans = "";
	if (b == true) {
		//if first small and all capital
		if (str[0] >= 97 && str[0] <= 123) {
			char p = str[0] - 32;
			ans += p;
			for (int i = 1; i < str.size(); i++) {
				char k = str[i] + 32;
				ans += k;
			}
		} else {
			char y = str[0] + 32;
			ans += y;
			for (int i = 1; i < str.size(); i++) {
				char z = str[i] + 32;
				ans += z;
			}
		}

	} else {
		ans = str;
	}

	cout << ans << endl;
	return 0;
}