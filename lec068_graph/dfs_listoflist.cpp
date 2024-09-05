#include <bits/stdc++.h>
using namespace std;
void dfs(int vertex,vector<bool>&visited,vector<vector<int>>&adjacency);
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<vector<int>>adjacency(edges);
	for(int i = 1;i<=edges;i++){
		int n1,n2;
		cin>>n1>>n2;
		adjacency[n1].push_back(n2);
		adjacency[n2].push_back(n1);
	}

	vector<bool>visited(nodes,false);
	cout<<"dfs started from root 0"<<endl;
	dfs(0,visited,adjacency);
	return 0;
}
void dfs(int vertex,vector<bool>&visited,vector<vector<int>>&adjacency){
        visited[vertex]=true;
        cout<<vertex<<" ";
        for(int neighbour : adjacency[vertex]){
                if(!visited[neighbour]){
                        dfs(neighbour,visited,adjacency);
                }
        }
}
