#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int vis[600];
int path[600];
vector<int>ax[600];
int dfs(int x){
	vis[x]=1;
	if(path[x]!=0)return path[x];
	for(auto i: ax[x]){
		path[x]+=dfs(i);
	}
	return path[x];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		ax[a].push_back(b);
	}
	cin>>a>>b;
	path[b]=1;
	int ans=dfs(a);
	int flag=1;
	for(int i=1;i<=n;i++){
		if(vis[i]!=0&&path[i]==0)flag=0;
	}
	cout<<ans<<" ";
	if(flag==1)cout<<"YES";
	else cout<<"NO";
} 
