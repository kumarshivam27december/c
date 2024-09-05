#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>g[N];
bool vis[N];
// void bfs(int vertex){
// 	//
// }
void dfs(int vertex){
	//take action on vertex after entering the vertex
	vis[vertex]= true;
	for(int child : g[vertex]){
		if(vis[child]) continue;
		cout<<"parent "<<vertex<<" child "<<child<<endl;
		//take action on child before entering the child node
	  dfs(child);
		//take action on child after exiting child node
	}

	//take action on vertex before exiting the vertex
}
int main(){
	int n,m;
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	for(int i = 0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
		dfs(i);
		}
		
	}
	return 0;
}

