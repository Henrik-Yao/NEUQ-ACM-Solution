#include<bits/stdc++.h>
using namespace std;
int n,e,u,v,flag=0,vis[20010];
vector<int>vec[20010];
void dfs(int x){
	printf("%d ",x);
	vis[x]=1;
	for(int i=0;i<vec[x].size();i++){
		if(vis[vec[x][i]]==0)
		dfs(vec[x][i]);
	}
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		cin>>u>>v;
		vec[u].push_back(v);
	}
	for(int i=0;i<n;i++)sort(vec[i].begin(),vec[i].end());
	for(int i=0;i<n;i++)if(!vis[i])dfs(i);
	return 0;
}
