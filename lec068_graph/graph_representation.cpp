#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int matrix[N][N];
//we will now make a list of list instead of matrix as list take just v+e complexity than the matrix which take square of n complexity
//so we will make a vector of vector
vector<int>list(N);
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n;//nodes or vertices
	int m;//edges

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		matrix[v1][v2] = 1;
		matrix[v2][v1] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		} cout << endl;
	}


	for(int i = 0;i<m;i++)
	{
		int v1,v2;
		cin>>v1,v2;
		list[v2].push_back(v1);
		list[v1].push_back(v2);
	}


	

	return 0;
}
