#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int matrix[N][N];
vector<int>graph[N];
void printmatrix(int matrix[][N],int m){
	for(int i = 0;i<=m;i++){
		for(int j = 0;j<=m;j++){
			cout<<matrix[i][j]<<" ";
		}cout<<endl;
	}
}
void printgraph(vector<int> graph[],int m){
	for(int i = 0;i<=m;i++){
		for(auto j: graph[i]){
			cout<<j<<" ";
		}cout<<endl;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		matrix[v1][v2]=1;
		matrix[v2][v1]=1;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	printmatrix(matrix,m);
	printgraph(graph,m);
}
