#include<bits/stdc++.h>
using namespace std;
vector<int>ax[20001];
int vis[20001];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	cout<<x<<" ";
	int length=ax[x].size();
	sort(ax[x].begin(),ax[x].end());
	for(int i=0;i<length;i++)dfs(ax[x][i]);
}
int main(){
	int n,e;
	cin>>n>>e;
	int begin=1000000;
	int vis[20001];
	while(e--){
		int a,b;
		cin>>a>>b;
		begin=min(begin,a);
		ax[a].push_back(b);
}
	for(int i=begin;i<n;i++){
		if(!vis[i])dfs(i);
	}
	return 0;
	
}
