#include <bits/stdc++.h>
using namespace std;
int n,m,flag=1;
vector <int> g[510];
int x,y,vis[510],mem[510];
int dfs(int t) {
	if (mem[t]!=-1) return mem[t];
	if (t==y) {
		return mem[t]=1;
	}
	if (g[t].size()==0) {
		flag=0;
		return mem[t]=0;
	}
	int ans=0;
	for (int i=0; i<g[t].size(); i++) {
		int to=g[t][i];
			ans+=dfs(to);
		}
	return mem[t]=ans;
}
int main() {
	int u,v;
	cin>>n>>m;
	memset(mem,-1,sizeof mem);
	for (int i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	cin>>x>>y;
	int res=dfs(x);
	if (res!=0&&flag==1) cout<<res<<" Yes";
	else cout<<res<<" No";
	return 0;
}
